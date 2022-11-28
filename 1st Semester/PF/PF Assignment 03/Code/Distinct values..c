#include<stdio.h>
main()
{
	int x, y, z;
	printf("Enter 3 numbers:");
	scanf("%d,%d,%d",&x,&y,&z);
	if (x==y && y==z)
	{
    	printf("it has 1 distinct value=%d",x);
		return 0;
	}
	if(x==y || y==z || z==y || y==x || z==x || x==z)
	{
    	printf("It has 2 distinct value");
		return 0;
	}
	else
    printf("It has 3 distinct values");
}

