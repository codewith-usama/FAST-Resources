#include<stdio.h>
main()
{
	float weight, height, bmi;
	printf("Enter weight(lb):");
	scanf("%f", &weight);
	
	printf("Enter height(in):");
	scanf("%f", &height);
	
	bmi=(weight*703)/(height*height);
	printf("%f", bmi);
	
	if(bmi<15)
	printf("Starvation");
	
	else if (bmi<18.5)
	printf("Underweight");
	
	else if (bmi>=18.5 && bmi<25)
	printf("Ideal");
	
	else if (bmi>=25 && bmi<30)
	printf("Overweight");
	
	else
	printf("\nMorbidly Obese");
}
