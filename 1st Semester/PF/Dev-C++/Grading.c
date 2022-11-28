#include<stdio.h>
main()
{
	int marks_obtained, total_marks;
	float percentage;
	char grade;
	printf("Enter marks obtained\a:");
	scanf("%d", &marks_obtained);
	printf("Enter total marks\a:");
	scanf("%d", &total_marks);
	percentage=marks_obtained*100/total_marks;
	printf("Your percentage is %.2f%%", percentage);
    
	if(percentage>=91 && percentage<=100)
	{
		printf("\nYour grade is A++\a.");
	return 0;
	}
	else if(percentage>=81 && percentage<=90)
	{
		printf("\nYour grade is A+.");
	return 0;
	}
	else if(percentage>=71 && percentage<=80)
	{
		printf("\nYour grade is A.");
	return 0;
	}
	else if(percentage>=61 && percentage<=70)
	{
		printf("\nYour grade is B.");
	return 0;
	}
	else if(percentage>=51 && percentage<=60)
	{
		printf("\nYour grade is C.");
	return 0;
	}
	else if(percentage>=41 && percentage<=50)
	{
		printf("\nYour grade is D.");
	return 0;
	}
	else(percentage<40);
    {
    	printf("\nFail");
	}
return 0;
}
