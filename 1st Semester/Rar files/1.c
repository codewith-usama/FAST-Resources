#include<stdio.h>
#include<stdlib.h>

void pf(FILE *);
void input(struct employee *pf);
void displayf(FILE *);
void inputf(FILE *ptr , struct employee *pf);

void input(struct employee *pf)    //input structure data
{
	int i;
	while(i<3)
	{
		printf("ENter employe %d detail \n" , i+1);
		printf("Enter name : \t");
		gets(*f->name);
		printf("House no :\t");
		scanf("%d" ,&(*f->d.hno));
		i++;
	}
}
void 	inputf(FILE *ptr , struct employee *f)   //transferring data in file 
{
	int i;
		while (i<3);
		{
			fprintf(ptr , "Employee %d detail \nName \t%s \nHouse no \t%d" , i+1 ,*f->name, *f->d.hno);
			i++;
		}
}
void displayf(FILE *f)    //displaying file 
{
	char filedata[100000];
	fflush(stdin);
	fgets(filedata , 100000 , f );
	puts(filedata); 
}

struct adress     ///nested structure
{
	int hno;
};

struct employee         //main structuure
{
	char name[20];
	struct adress d;
} a[3];

int main()
{
	struct employee *f;
	f = a ;
	FILE *ptr;
	ptr = fopen("k201065" , "r+") ;
	input(&f);
	inputf(ptr , *pf);
	system("cls");
	displayf(ptr);
	fclose(ptr);
	
}
