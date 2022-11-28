#include<stdio.h>
main()
{
    int i,n ,j=0;
    printf("Enter Number Of Rows For Checkeboard:");
    scanf("%d",&n);
	for (i=1; i<=n; i++) 
	{
		if(i%2==0)
    {
	printf(" ");
    }
	for (j=0;j<n;j++ )
	{
    	printf(" *");

	}
    printf("\n");
	}
}

