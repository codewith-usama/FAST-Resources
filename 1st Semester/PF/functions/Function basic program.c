#include<stdio.h>
add()
{
	system("Color 0A");
	int a, b[100], i, sum=0, j=1;
	printf("How many number you want to add? ");
	scanf("%d", &a);
	system("cls");
	for(i=1;i<=a;i++)
	{
		printf("Enter Number %d: ", j);
		scanf("%d", &b[i]);
		j++;
		sum=sum+b[i];
	}
	system("cls");
	printf("\nSum is %d", sum);
	if(sum%10>=2)
	printf("\nGreater");
	else
	printf("\nLesser");
}

main()
{
	add();
}
