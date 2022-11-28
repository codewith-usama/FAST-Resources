#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int i,j,n;
	int array[50];
	float temp;
	printf("Enter a number:");
	scanf("%d", &j);
	srand(time(0));
	for(i=0;i<=7;i++)
	{
	
    array[i]=rand()%10;
    }
    for(i=0;i<=7;i++)
	printf("\n%d\n", array[i]);
	
	for(n=0;n<=7;n++)
	{
		if(array[n]==j)
		{
			printf("Number is found");
			break;
		}
			
		}
	}

