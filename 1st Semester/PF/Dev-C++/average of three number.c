#include<stdio.h>
main()
{
	int num1, num2, num3;
	printf("Enter num1:");
	scanf("%d", &num1);
	printf("Enter num2:");
	scanf("%d", &num2);
	printf("Enter num3:");
	scanf("%d", &num3);
	
	if((num1 != num2) ||(num1!=num3)|| (num2 != num3 ) )
{
		printf("number are not equal");
 }
   // else if (num1==num2 && num2==num3)
    else if(num1==num2&&num1==num3&&num2==num3);
	{
    	printf("Number are equal");
	}	

 if(num1>num2 && num2>num3)
	{
		printf("Num1 is greatest");
	}
	else if(num2>num3&&num2>num1)
	{
		printf("num2 is greatest");
	}
	else if(num3>num2&&num3>num1)
	{
		printf("num3 is greatest");
	}
 //return 0;
}
//    else(num1==num2 && num2==num3);
//    {
//    	printf("Number are equal");
//	}
	

