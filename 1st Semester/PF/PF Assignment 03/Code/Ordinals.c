#include<stdio.h>
main()
{
	int i, e;
	printf("Input For Print Hello: ");
	scanf(" %d", &e);
	i=1;
	while(i<=e)
	{
		printf(" %d", i);
		if(i%10==1 && i!=11 || i==1)
		{
			printf("st");
		}
		if(i%10==2 && i!=12 || i==2)
		{
			printf("nd");
		}
		if(i%10==3 && i!=13 || i==3)
		{
			printf("rd");
		}
		if(i%10>=4 || i%10==0)
		{
			printf("th");
		}
		if(i>=11 && i<=13)
		{
			printf("th");
		}
		printf(" Hello\n");
	    i++;
	}
}
