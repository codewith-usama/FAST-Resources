#include<stdio.h>
main()
{
	int i=1, j=1;
	for(;j<=i;)
	{
		if(i>5)
		break;
		j=j+i;
		printf("%d\n", j);
		i=i+j;
	}
}
