#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main(){
void *mem1,*mem2;
char buff1[100],buff2[100];
int shmid1,shmid2,count,adda,addb,addsum;
shmid1=shmget((key_t)2345,1024,0666);
shmid2=shmget((key_t)1001,1024,0666);
mem1 = shmat(shmid1,NULL,0);
mem2 = shmat(shmid2,NULL,0);
printf("Fibonacci Series:\n");
printf("0 ");
for(count = 0;count<=10;count++){
    adda = atoi((char *)mem1);
    addb = atoi((char *)mem2);
    addsum = adda+addb;
    printf("%d ",addsum);
    sprintf(buff2 , "%d" ,addb);
    sprintf(buff1 , "%d" ,addsum);
    strcpy(mem1,buff2);
    strcpy(mem2,buff1);
    addsum = 0;

}
}

