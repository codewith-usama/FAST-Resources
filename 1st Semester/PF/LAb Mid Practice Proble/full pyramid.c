#include<stdio.h>
main()
{
	int rows, i, k=0, space;
	printf("Enter number of rows: ");
	scanf("%d", &rows);
	for(i=1;i<=rows;i++,++k);
	{
		for(space=1;space<=rows-i;++space)
		{
			printf(" ");
		}
			while(k!=2*i-1)
			{
				printf(" %d");
				++k;

			}
		printf("\n");
	}
	return 0;
}

