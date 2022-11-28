#include<stdio.h>
int main()
{   
	int i,code;
//	printf("Secret code is 2020");
	for(i=1;i<=4;i++)
	{
		printf("Enter the secret code: ");
		scanf("%d", &code);
		if(code==2020)
		printf("\nWelcome");
		
		if(code!=2020)
		printf("\nTry again");
	}
}
