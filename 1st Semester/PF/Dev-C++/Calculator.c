#include<stdio.h>
main()
{
	float n1, n2;
	char oper;
	system("color 0a");
	printf("\t\t\tBasic Arthematic Calculator By Mohammad Usama\n");
	printf("\t\t\t\t\tOperators +,-,*,/\n");
	printf("\tEnter a number: ");
	scanf("%f", &n1);
	printf("\tEnter an operator: ");
	scanf(" %c", &oper);
	printf("\tEnter a number: ");
	scanf("%f", &n2);
	
		switch(oper)
		{
			case '+':
				printf("%.2f + %.2f = %.2f", n1, n2, n1+n2);
				break;
		
			case '-':
				printf("%.2f - %.2f = %.2f", n1, n2, n1-n2);
				break;
			case '*':
				printf("%.2f * %.2f = %.2f", n1, n2, n1*n2);
				break;
			case '/':
				printf("%.2f / %.2f = %.2f", n1, n2, n1/n2);
				break;
			default:
				printf("Incorrect operator");
			
		}
}
