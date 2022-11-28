#include<stdio.h>
	main(){
	
	float num1 , num2;
	char op, decision;
	do{
		
		printf("Enter two  numbers and operation\n");
		scanf("%f %f %c", &num1, &num2, &op);
		//printf("%d", num1);
		if(op == '+')
	
			//int sum = num1 + num2;
			printf("Sum is %f", num1+num2);
		if(op == '-')
		
			printf("Subtractio is %f", num1-num2);
		if(op == '*')
		
			printf("Multiplication is %f", num1*num2);
		if(op == '/')
		
			printf("Sum is %f", num1/num2);	
			
		printf("\nDo you want to continue\n");
		scanf(" %c",&decision);	
		printf("\n");
		//clrscr();
	}
	while (decision == 'y');
	
}
	
	
