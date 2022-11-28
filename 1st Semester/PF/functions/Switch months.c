#include<stdio.h>
main()
{
	int n;
	char month[12][10] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	printf("Enter the Number of Month 1-12:");
	scanf("%d", &n);
	
	if(n>=1 && n<=12)
	{
	
		switch(n)
		{
			case 1:
				{
					printf("%s", month[0]);
					break;
				}
			case 2:
				{
					printf("%s", month[1]);
					break;
				}	
			case 3:
				{
					printf("%s", month[2]);
					break;
				}	
			case 4:
				{
					printf("%s", month[3]);
					break;
				}	
			case 5:
				{
					printf("%s", month[4]);
					break;
				}	
			case 6:
				{
					printf("%s", month[5]);
					break;
				}	
			case 7:
				{
					printf("%s", month[6]);
					break;
				}	
			case 8:
				{
					printf("%s", month[7]);
					break;
				}	
			case 9:
				{
					printf("%s", month[8]);
					break;
				}	
			case 10:
				{
					printf("%s", month[9]);
					break;
				}	
			case 11:
				{
					printf("%s", month[10]);
					break;
				}	
			case 12:
				{
					printf("%s", month[11]);
					break;
				}	
		}
	}
	else
	printf("Invalid month number");
}

