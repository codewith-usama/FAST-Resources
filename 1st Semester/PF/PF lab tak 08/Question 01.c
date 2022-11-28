#include<stdio.h>
#include<stdio.h>
int count_of_digit(int x)
{
	static int count=0;
	if(x>0)
	{
		count++;
		count_of_digit(x/10);
	}
	else
	return count;
}
main()
{	
	int n,count=0;
	printf("Enter a Positive Integar Number:");
	scanf("%d",&n);
	
	//count = count_of_digit(n);
	printf("Total digit in %d is %d",n,count_of_digit(n));
	
}
