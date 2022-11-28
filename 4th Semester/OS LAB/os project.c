#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#define MAX_LINE 1024               /* The maximum length command */

// macros for colors:
#define KRED  "\x1B[31m"
#define RESET "\x1b[0m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define BOLDBLUE "\033[1m\033[34m"	/* Bold Blue */

char current_dir[MAX_LINE];
char *home_dir;

int p_wait_flag = 1;                //parent invokes wait if flag is 1
int input_redirection_flag = 0;     //if 1, default input comes from file
int output_redirection_flag = 0;    //if 1, default output goes to file
int saved_stdin, saved_stdout;      //to restore default input and output settings
int in, infile_index, out, outfile_index; //To handle redirection from and to files
int pipe_flag, pipe_index, p_command2;      
/* ^
pipe_flag   => If command requires communication between two command through a pipe.
pipe_index  => index of "|" in a command.
p_command2  => Starting index of the command after "|" in a pipe command.
*/
int exit_sh = 0;
int empty_command = 0;
int command_count = 0;                                          //To count commands


char* replaceStrAtBeg(char* str, char* needle, char* replace);
void run_change_dir(char *dir);
void ParseCommand(char * command, char ** args);
void CheckForRedirection( char ** args);
void FlagsDefaultSettings();
void CheckForPipes(char ** args);

int main(void)
{
    printf(BOLDBLUE"\n\t\tAOA! Welcome to Umar and Asfand's shell:) \n"RESET);    // BOLDBLUE: will be the color of our statement. RESET ko agar remove bhi kardo to koi fark nhi parega.
    int should_run = 1;     //To determine when to exit the shell program.
    pid_t pid;              //To store process id after forking.
    char **args = malloc(sizeof(char) * (MAX_LINE/2 + 1));          //To store every arguement in a command
    char *command = malloc(sizeof(char) * MAX_LINE);                //To store the currently typed command
    char *command_history_buffer = malloc(sizeof(char) * MAX_LINE); //To store commands and allow for history display
    int state, state2;      //To store state of executing a command in a child and parent process.                          
    int pipefd[2];          //To store piping channels that commands will communicate through
    char ** args1 = malloc(sizeof(char) * (MAX_LINE/2 + 1));    //In case of pipes: args for the command on the left
    char ** args2 = malloc(sizeof(char) * (MAX_LINE/2 + 1));    //In case of pipes: args of the command on the right
    char *command_to_parse = malloc(sizeof(char) * MAX_LINE);                //To store the currently typed command

    home_dir = getenv("HOME");
    getcwd(current_dir, MAX_LINE);
  
    while(should_run && exit_sh == 0)                                         
    {   

        FlagsDefaultSettings();		// Setting the flag default values including the gcc compiler flags list
        printf(GRN"FASTShell-> "RESET);
        printf(GRN "%s ->" RESET, current_dir);
        memset(command, 0, MAX_LINE);	// allocating memory for the currently typed command and initializing the array of chars (command) to '0'.
        
        /*
        memset() is used to fill a block of memory with a particular value.
		The syntax of memset() function is as follows :

		ptr ==> Starting address of memory to be filled
		x   ==> Value to be filled
		n   ==> Number of bytes to be filled starting 
        from ptr to be filled
		void *memset(void *ptr, int x, size_t n);
        */

        fgets (command, MAX_LINE, stdin);	// For reading a string value with spaces
        fflush(stdout);       // for clearing the output buffer
        
        //If user entered exit, return 0. Otherwise, start parsing the command.
        if(strlen(command) <= 0)
        {   
            return 0;      
        } 
        else 
        {
            strcpy(command_to_parse, command);	// copying input cmd from command to command_to_parse
            ParseCommand(command_to_parse, args);
            int history_cmd = 0;
            for(int i =0; args[i] != NULL; i++)
            {
                if(strcmp(args[i], "pichetodekho") == 0)
                	history_cmd = 1;
            }

            if(history_cmd == 1)
            { 
                if(command_count <= 0)	// if history is empty
                {   printf(KRED"No commands in history \n"RESET);
                    continue;
                }
                printf("%s\n", command_history_buffer);		// print prev cmd
                strcpy(command, command_history_buffer); 	// copy prev cmd to command (currently typed command)
                strcpy(command_to_parse, command);			
                ParseCommand(command_to_parse, args);
            }
            /*Store it by value since the command will be adjusted in parsing 
            and the buffer needs to store original command.*/
            strcpy(command_history_buffer, command);
            command_count++;

            CheckForRedirection(args);
            CheckForPipes(args);

            //Handle redirection if existent
            if(input_redirection_flag == 1 )
            {
                in = open(args[infile_index], O_RDONLY);
                if(in <0)
                {
                    printf("Failed to open file with name %s \n", args[infile_index]);
                    return 1;
                }
                else
                {
                    saved_stdin = dup(0);
                    dup2(in, 0);
                    close(in);
                }                
                
            }

            if(output_redirection_flag == 1)
            {
                out = open(args[outfile_index], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
                if(in <0)
                {
                    printf("Failed to open file with name %s \n", args[outfile_index]);
                    return 1;
                }
                else
                {
                    saved_stdout = dup(1);
                    dup2(out, 1);
                    close(out);
                }                
                
            }

            //Handle piping if existent
            if(pipe_flag == 1)
            {
                for(int i =0; i <= pipe_index; i++)
                {
                    if(i == pipe_index)
                    {
                        args1[i] = NULL;
                        break;
                    }
                    args1[i] = args[i];
                }
                int last_i = 0;
                for(int i = pipe_index + 1; args[i] != NULL; i++)
                {
                    args2[i - pipe_index - 1] = args[i];  
                    last_i = i;                 
                }
                args2[last_i + 1] = NULL;
            }

            //Check for exit
            for(int i=0; args[i] != NULL;i ++)
            {
                if(strcmp(args[i], "exit") == 0)
                exit_sh = 1;
            }
            
            if(strcmp(args[0], "cd") == 0)
			{
				run_change_dir(args[1]);
				continue;
			}

            //Check for empty command
            if(args[0] == NULL || strcmp(args[0], "\0") == 0 || strcmp(args[0], "\n") == 0)
                empty_command = 1;

            if(empty_command == 0)
            {
                if(exit_sh != 1)
                {
                    pid = fork();           //create process

                    if(pid == -1)           //Error occured creating the clone process
                    {
                        printf("PID returned -1. Fork failed.");
                        return 0;
                    }
                    else if(pid == 0)        //The child (new) process
                    {
                        if(input_redirection_flag == 1 | output_redirection_flag == 1)
                        {    
                            char *args_new[MAX_LINE/2 + 1];
                            for(int i=0; !(strcmp(args[i], "<") == 0 || strcmp(args[i], ">") == 0); i++)
                                args_new[i] = args[i]; 
                            state = execvp(args_new[0], args_new);
                            printf(KRED"Error occured"RESET);
                            exit(-1);
                        }
                        else if(pipe_flag == 1)
                        {
                            pid_t pid_2;
                            pipe(pipefd);
                            pid_2 = fork();
                            
                            if(pid_2 <0)
                            {    
                                printf("PID returned -1. Fork failed.");
                                return 0;
                            }
                            else if(pid_2 == 0) // create grandchild
                            {
                            saved_stdout = dup(1);
                            dup2(pipefd[1], 1);     //Replace stdout with the output part of the pipe
                            close(pipefd[0]);       //close unused input side of the pipe
                            execvp(args1[0], args1);//Enter command that will produce output to the other command with ags2
                            printf("Command %s not found. \n", args1[0]);
                            exit(-1);
                            }
                            else if(pid_2 > 0) //run in child of shell (parent of grandchild)
                            {
                                wait(NULL);
                                saved_stdin = dup(0);
                                dup2(pipefd[0], 0); //Replace stdin with the input part of the pipe
                                close(pipefd[1]);   //close output part of the pipe
                                state2 = execvp(args2[0], args2); //execute command that will take input from the pipe
                                
                                if(state2 <0)
                                printf("Command %s not found. \n", args1[0]);
                                exit(-1);
                            }
                        }

                        else    //No piping or redirection commands
                        {
                            state = execvp(args[0], args);
                        }
                        
                        if(state <0)
                        printf(KRED"Command %s not found. \n"RESET, args[0]);
                        exit(0);
                    }
                    else        //Parent process
                	{
						if(p_wait_flag == 1)
                            wait(NULL);
					}
                }
                else
                {
                    printf(BOLDBLUE"\t\tAllah Hafiz. :)\n\n"RESET);
                    should_run  = 0;
                }
            }
        }
        //Restore default in and out 
        dup2(saved_stdout, 1);
        dup2(saved_stdin, 0);
    }  

	return 0;
}

void ParseCommand(char * command, char ** args)	// args:stores every arguement in a command
{
    int args_count =0;                  //to determine the current number of arguements
    int command_len = strlen(command);  //length of the command    
    int arg_i = -1;                     //starting index of the next arguement
    int prev_command = 0;
    int history = 0;
    

    for(int i =0; i < command_len; i++)
    {                     

        switch(command[i])
        {
            case ' ':
            case '\t': 
	            if(arg_i != -1)           
	            {
	                args[args_count] = &command[arg_i];
	                args_count++;
	            }
	            command[i] = '\0';         
	            arg_i = -1;   
	            break;

            case '\n':
	            if(arg_i != -1)           
	            {
	                args[args_count] = &command[arg_i];
	                args_count++;
	            }
	            command[i] = '\0'; 
	            //args[args_count+1] = NULL;   
	            break;
            default:                     
	            if(arg_i == -1)
	              arg_i = i;
	            if(command[i] == '&')
	            {
	                p_wait_flag = 0;    //parent won't invoke wait()
	                command[i] = '\0'; 
	                i++;
	                //args[args_count+1] = NULL; 
	            }
	            break;
        }    
    }  
/*for(int i=0; i< args_count; i++)
printf("args[%d]:%s\n", i, args[i]);*/
	args[args_count] = NULL;
}

void CheckForRedirection(char ** args)
{
    for(int i=0; args[i] != NULL; i++)
    {
        //printf(" %d %s \n",i, args[i]);
        if(strcmp(args[i], "<") == 0)
        {
            input_redirection_flag = 1;
            if(args[i+1] != NULL)
                infile_index = i+1;
            else
                printf("Command %s has invalid file name. ", args[0]);
        }
        if(strcmp(args[i], ">") ==0)
        {
            output_redirection_flag = 1;
            if(args[i+1] != NULL)
                outfile_index = i+1;
            else
                printf("Command %s has invalid file name. ", args[0]);
        }
    }
    //printf("Redirection I O %d %d \n", input_redirection_flag, output_redirection_flag);   
}

void FlagsDefaultSettings()
{
    //default settings for flags
        input_redirection_flag = 0;
        output_redirection_flag = 0;
        p_wait_flag = 1;
        pipe_flag = 0;
        exit_sh  =0;
        empty_command = 0;
}

void CheckForPipes(char ** args)
{
    for(int i=0; args[i] != NULL; i++)
    {
        if(strcmp(args[i], "|") == 0)
        {
            pipe_flag = 1;
            pipe_index = i;
            if(args[i+1] == NULL)
            {
                printf("Invalid command after |. \n");
            }           
        }
    }
}


// To replace the ~ with home directory (or opposite)
char* replaceStrAtBeg(char* str, char* needle, char* replace)
{
  char* str_res = strstr(str, needle);

  if(str_res == NULL ){ // not found
    return str;
  }else if( (str_res - str) != 0 ){ // not at the beggining
    return str;
  }

  char* res = malloc( strlen(str) + strlen(replace) - strlen(needle) + 1 );

  strcpy(res, replace);

  strcpy(res+strlen(replace), str+strlen(needle));

  return res;
}

void run_change_dir(char *dir)
{
  if(!dir) return;

  char *home_dir_with_slash = malloc(strlen(home_dir) +2);
  strcpy(home_dir_with_slash, home_dir);
  strcat(home_dir_with_slash, "/");

  char *chdir_path = replaceStrAtBeg(dir, "~", home_dir);

  if(chdir(chdir_path) != 0){
    perror("Failed changing directory"); 
  }
  getcwd(current_dir, MAX_LINE);
}

/*
Why is wait flag 1 by default (why call wait by default - is it because it is used every time?
How to implement the code to make it usable for pipes (Pipes are not being used the right way)
Program always executes last command when pipes are used (except for use with exit. Exit leaves shell immediately.)
Find purpose of fork and how many concepts of OS are being used.

*/
