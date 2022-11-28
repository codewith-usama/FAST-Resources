#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct department
{
	int id;
	char name[20];
};
struct employee
{
	int Emp_id;
	char Emp_name[20];
	int salary;
	int age;
	struct department dpt;
}e[5],*p;
void viewrecord()
{
	system("cls");
	int i;
	FILE *f;
	f=fopen("k200190.txt","r+");
	if(f==NULL)
	{
		exit(1);
	}
	i=0;
	while(fread(p,sizeof(e),1,f)==1)
	{
		printf("Employee ID: %d\n",(p+i)->Emp_id);
		printf("Employee Name: %s\n",(p+i)->Emp_name);
		printf("Employee Salary: %d\n",(p+i)->salary);
		printf("Enter Age: %d\n",(p+i)->age);
		printf("Enter Department ID: %d\n",(p+i)->dpt.id);
		printf("Enter Employee Name: %s\n",(p+i)->dpt.name);
		i++;
	}
	fclose(f);
	printf("Press key to continue: ");
	getchar();
}
void replace()
{
	system("cls");
	int i=0,j=0;
	FILE *f,*temp;
	f=fopen("k200190.txt","r+");
	temp= fopen("temp.txt","w+");
	fseek(f,0,SEEK_SET);
	if(f==NULL)
	{
		exit(1);
	}
	while(fread(p,sizeof(e),1,f)==1)
	{
		while(1)
		{
			
			if((p+j)->Emp_name[i] == ' ')
			{
				(p+j)->Emp_name[i] = '-';
				break;
			}
			i++;
		}
		i=0;
		j++;
		fwrite(p,sizeof(e),1,temp);
	}
	i=0;
	fseek(temp,0,SEEK_SET);
	while(fread(p,sizeof(e),1,temp)==1)
	{
		printf("%s\n",(p+i)->Emp_name);
		i++;
	}
	fclose(f);
	fclose(temp);
	remove("k200190.txt");
	rename("temp.txt","k200190.txt");
	
	printf("Press any key to continue:");
	getchar();
}
void function()
{
	system("cls");
	int i=0,j=0,max=0;
	FILE *f;
	f=fopen("k200190.txt","r+");
	if(f==NULL)
	{
		exit(1);
	}
	while(fread(p,sizeof(e),1,f)==1)
	{
		if(strcmp((p+i)->dpt.name,"x")==0)
		{
			if(max<p->salary)
			{
				max=p->salary;
			}
		}
		i++;
	}
	fseek(f,0,SEEK_SET);
	
	while(fread(p,sizeof(e),1,f)==1)
	{
		if(strcmp((p+j)->dpt.name,"y")==0)
		{
			if((p+j)->salary>max);
			{
				printf("%s\n",(p+j)->Emp_name);
			}
		}
		j++;
	}
	fclose(f);
	printf("Press any key to continue:");
	getchar();
}
void deleterec()
{
	int id,i=0,j=0;
	printf("Enter Employee ID you want to Delete: ");
	scanf("%d",&id);
	FILE *fp,*temp;
	fp= fopen("K200190.txt","r+");
	temp= fopen("temp.txt","w+");
	if(fp==NULL)
	{
		exit(1);
	}
	if(temp==NULL)
	{
		exit(1);
	}
	while(fread(p,sizeof(e),1,fp)==0)
	{
		if(id==(p+i)->Emp_id)
		{
		}
		else
		{
			fwrite(p,sizeof(e),1,temp);
		}
		i++;
	}
	fseek(temp,0,SEEK_SET);
	i=0;
	while(fread(p,sizeof(e),1,temp)==1)
	{
		printf("Employee ID: %d\n",(p+i)->Emp_id);
		printf("Employee Name: %s\n",(p+i)->Emp_name);
		printf("Employee Salary: %d\n",(p+i)->salary);
		printf("Enter Age: %d\n",(p+i)->age);
		printf("Enter Department ID: %d\n",(p+i)->dpt.id);
		printf("Enter Employee Name: %s\n",(p+i)->dpt.name);
		i++;
	}
	fclose(fp);
	fclose(temp);
	remove("k200190.txt");
	rename("temp.txt","k200190.txt");
	printf("press any key to continue");
	getchar();
	viewrecord();
}
int main()
{
    system("cls");
    int i;
	p =&e[0];
	FILE *fp,*f;
	fp=fopen("k200190.txt","r+");
	if(fp==NULL)
	{
		exit(1);
	}
	for(i=0;i<5;i++)
	{
		printf("Employee %d\n",i+1);
		printf("Enter Employee ID: ");
		scanf("%d",&(p+i)->Emp_id);
		printf("Enter Employee Name: ");
		fflush(stdin);
		gets((p+i)->Emp_name);
		printf("Enter Employee Salary: ");
		scanf("%d",&(p+i)->salary);
		printf("Enter Age: ");
		scanf("%d",&(p+i)->age);
		printf("Enter Department ID:");
		scanf("%d",&(p+i)->dpt.id);
		printf("Enter Employee Name: ");
		fflush(stdin);
		gets((p+i)->dpt.name);
		fwrite(p,sizeof(e),1,fp);
	}
	fclose(fp);

viewrecord();
function();
replace();
deleterec();
	
    return 0;
}

