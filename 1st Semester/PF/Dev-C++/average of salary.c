#include <stdio.h>
main()
{
	int n, i, fs, t=0, ms, t1=0, sum=0, avg, k=0;
	char c;
	printf("Enter number of employees: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		printf("\nPress 'F' for female employee and 'M' for male employee: ");
		scanf(" %c", &c);
		if(c=='f' || c=='F')
		{
			printf("Enter salary of female employee: ");
			scanf("%d", &fs);
			t=t+fs;
			k++;
		}
		else if(c=='m' || c=='M')
		{
			printf("Enter salary of male employee: ");
			scanf("%d", &ms);
			t1=t1+ms;
			k++;
		}
		else 
		{
			printf("\nInvalid code Enter again\n");
			n++;
		}
	}
	
	sum=t+t1;
	avg=sum/k;
	printf("\nSum of male employee salary is %d", t1);
	printf("\nSum of female employee salary is %d", t);
	
	printf("\nTotal sum of salary is %d", sum);
	printf("\nAverage of salary is %d", avg);
	}
