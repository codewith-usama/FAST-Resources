#include<stdio.h>
#include<string.h>


int element(int arr[10])
{
	int i,j,min,x;
	for (i = 0; i <= 9; i++)
	{
		for(j = 0; j <= 8; j++)
		{
			if(arr[j]>arr[j+1])
			{
				min=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=min;
			}
		}
	x=arr[0];
	
	return x;	
	}
}

int element1(int arr[10]) 
{
	int i,j,min,y;
	for (i = 0; i <= 9; i++)
	{
		for(j = 0; j <= 8; j++)
		{
			if(arr[j]>arr[j+1])
			{
				min=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=min;
			}
		}
	y=arr[9];
	
	return y;	
	}
}



int main()
{
	int i, j=1;
	int e[10];
	
	for (i=0;i<=9;i++)
	{
			printf("Enter Number %d: ", j);
			j++;
			scanf("%d",&e[i]);
	}	
	
	printf("Lowest element is: %d\n",element(e));
	printf("Highest element is: %d" ,element1(e));
} 
