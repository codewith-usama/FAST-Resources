#include<stdio.h>
main()
{
	int sr, er, sum=0, x;
	printf("Enter starting range:");
	scanf("%d", &sr);
	printf("Enter ending range:");
	scanf("%d", &er);
	for(x=sr; x<=er; x++)
	{
		if(x%5==0)
		{
			printf("\nThe sum is %d", x);
		}
	}
	
}
