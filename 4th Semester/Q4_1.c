#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
int i;
void *sh_memory;
char buff[100];
int shmid;
shmid = shmget((key_t)1001, 1024,0666|IPC_CREAT);
printf("Key of Shared memory is %d\n",shmid);
sh_memory = shmat(shmid,NULL,0);
printf("Process attached at %p\n",sh_memory);
printf("Enter some data to write to shared memory\n");
read(0,buff,100);
strcpy(sh_memory,buff);
printf("You Wrote : %s\n",(char *)sh_memory);

}
