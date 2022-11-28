#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char fun[56];
	int code,i,j,k,l;
	system("Color 0A");
	printf("1.Decrypt:\n2.Encrypt: ");
	scanf("%d",&code);
	if(code==1 || code==2)
	{
		
	printf("\nEnter Key:");
	scanf("%d",&k);
	printf("\nEnter String To Decrypt(In Capital):\nEnter String To Encrypt(In Small):");
	fflush(stdin);
	gets(fun);
	i=strlen(fun);
	if(code==1)
	{
		for(j=0;j<i;j++)
		{
			if(fun[j]>=65&&fun[j]<=90)
			{
				fun[j]=fun[j]+k;
			if(fun[j]>90)
			{
				l=fun[j]-90;
				fun[j]=65+l-1;
			}
			fun[j]=fun[j]+32;
		}
		else
		fun[j]=fun[j];		
		}
	}
	else if (code==2)
	{
		for(j=0;j<i;j++)
		{
			if(fun[j]>=97&&fun[j]<=122)
			{
				fun[j]=fun[j]-k;
				if(fun[j]<97)
				{
					l=fun[j]-97;
					fun[j]=122+l+1;
				}
				fun[j]=fun[j]-32;
			}
			else
			fun[j]=fun[j];		
		}
	
	}
	
	printf("\nThe new string is: ");
	puts(fun);
	
	}
	else 
	printf("Incorrect Code");	
}
