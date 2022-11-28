#include<stdio.h>
main()
{
	int num;
	printf("Enter any number:");
	scanf("%d", &num);
	
	switch(num>=0)
	{
		case 0:
			printf("Number is negative");
			break;
		case 1:
			printf("Number is positive");
			break;	
	}
}
