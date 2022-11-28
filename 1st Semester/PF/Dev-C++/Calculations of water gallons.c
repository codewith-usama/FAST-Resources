#include<stdio.h>
main()
{
	int ig, cg, hg, p;
	char ch;
	printf("Press 'H' for Home usage: ");
	printf("\nPress 'C' for Commercial usage: ");
	printf("\nPress 'I' for Industrial usage:\n ");
	
	scanf("%c", &ch);
	
	switch(1)
	{
		case 1:
			if(ch=='H' || ch=='h')
			{
				printf("\nEnter number of gallons: ");
				scanf("%d", &hg);
				p=hg*500;
				printf("\nAmount of %d gallons is %d", hg, p);
			}
			else if(ch=='C' || ch=='c')
			{
				printf("\nEnter number of gallons: ");
				scanf("%d", &cg);
				if(cg<1000)
				{
					p=cg*1000;
					printf("\nAmount of %d gallons is %d", cg, p);
				}
				else 
				{
					p=cg*1250;
					printf("\nAmount of %d gallons is %d", cg, p);
				}
			}
			else if(ch=='i' || ch=='I')
			{
				printf("\nEnter number of gallons: ");
				scanf("%d", &ig);
				if(ig<500)
				{
					p=ig*1000;
					printf("\nAmount of %d gallons is %d", ig, p);
				}
				else if(ig>=500 && ig<=2500)
				{
					p=ig*2000;
					printf("\nAmount of %d gallons is %d", ig, p);
				}
				else
				{
					p=ig*3000;
					printf("\n\nAmount of %d gallons is %d", ig, p);
				}
			}
	}
}
