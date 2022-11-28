#include <stdio.h>
 
int main()
{
    FILE *fptr1, *fptr2;
    char filename[40];
    char ch;
    int delete_line, temp = 1;
    system("Color 0A"); // First file.txt
 
    printf("Enter file name: ");
    gets(filename);
    
    fptr1 = fopen(filename, "r");
    
    if(fptr1 == NULL)
    {
    	puts("Error");
	}
	else
	{
    ch = getc(fptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fptr1);
    }
    
    rewind(fptr1);
    
    printf("\n\n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    
    fptr2 = fopen("replica.c", "w");
    ch = getc(fptr1);
    while (ch != EOF)
    {
        ch = getc(fptr1);
        if (ch == '\n')
            temp++;
          
            if (temp != delete_line)
            {
               
                putc(ch, fptr2);
            }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(filename);
    
    rename("replica.c", filename);
    printf("\n The contents of file after being modified are as follows:\n");
    fptr1 = fopen(filename, "r");
    ch = getc(fptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fptr1);
    }
    fclose(fptr1);
	}
    return 0;
}
