#include<stdio.h>
main()
{    
    int num;
	printf("Enter any number:");
	scanf("%d", &num);
	
	switch(num%2==0)
	{
		case 0:
			printf("Number is odd");
			break;
		case 1:
		    printf("Number is even");
			break;	
	}
}
