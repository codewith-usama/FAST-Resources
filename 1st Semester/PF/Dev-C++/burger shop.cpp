#include<stdio.h>
int main()
{ 
    int snack, counter=0, B, tb, P, tp, F, tf, S, ts, total, opt;
	printf("\t\tUSAMA ONLINE RESTURANT PLACEMENT\n               \t\t\tWELCOME!\n");
	printf("Please select from the following Menu");
	printf("\n1.Burger(Rs.200)\n2.Pizza(Rs.500)\n3.French Fries(Rs.50)\n4.Sand Witches(Rs.150)");
	printf("\nEnter number of snack you want to order:");
	
	scanf("%d", &snack);
	
	if(counter==snack)
	{
		printf("\nYou order nothing");
	}
	
	if(counter<snack)
	{
		printf("\nEnter first snack you want to order:");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
				printf("Enter quantity of burger:");
				scanf("%d", &B);
				tb=B*200;
				break;
			case 2:
				printf("Enter quantity of Pizza:");
				scanf("%d", &P);
				tp=P*500;
				break;
			case 3:	
				printf("Enter quantity of French Fries:");
				scanf("%d", &F);
				tf=F*50;
				break;
			case 4:
				printf("Enter quantity of Sandwiches:");
				scanf("%d", &S);
				ts=S*150;
				break;	
			default:
				printf("invalid option");
		        break;		
		}
	}
	
	counter++;
	if(counter<snack)
	{
		printf("Enter second snack you want to order:");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1:
				printf("Enter quantity of burger:");
				scanf("%d", &B);
				tb=B*200;
				break;
			case 2:	
				printf("Enter quantity of Pizza:");
				scanf("%d", &P);
				tp=P*500;
				break;
			case 3:
				printf("Enter quantity of French Fries:");
				scanf("%d", &F);
				tf=F*50;
				break;			
			case 4:
				printf("Enter quantity of Sandwiches:");
				scanf("%d", &S);
				ts=S*150;
				break;
			default:
				printf("invalid option");
			    break;					
    	}
   }
   
	counter++;
	if(counter<snack)
	{
		printf("Enter third snack you want to order:");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1:
				printf("Enter quantity of burger:");
				scanf("%d", &B);
				tb=B*200;
				break;
			case 2:
				printf("Enter quantity of Pizza:");
				scanf("%d", &P);
				tp=P*500;
				break;
			case 3:
				printf("Enter quantity of French Fries:");
				scanf("%d", &F);
				tf=F*50;
				break;			
			case 4:
				printf("Enter quantity of Sandwiches:");
				scanf("%d", &S);
				ts=S*150;
				break;
			default:
				printf("invalid option");
			    break;					
    	}
   }
	counter++;
	if(counter<snack)
	{
		printf("Enter fourth snack you want to order:");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1:
				printf("Enter quantity of burger:");
				scanf("%d", &B);
				tb=B*200;
				break;
			case 2:
				printf("Enter quantity of Pizza:");
				scanf("%d", &P);
				tp=P*500;
				break;
			case 3:
				printf("Enter quantity of French Fries:");
				scanf("%d", &F);
				tf=F*50;
				break;			
			case 4:
				printf("Enter quantity of Sandwiches:");
				scanf("%d", &S);
				ts=S*150;
				break;	
			default:
				printf("invalid option");
			    break;				
    	}
   }
   
   total = tb + tp + tf + ts;
   printf("\nyou have ordered \nBurger %d \nPizza %d \nFrench Fries %d \nSandwiches %d ", B, P, F, S);
   printf("\nYour total Amount is %d", total);
   printf("\nThank you");
   //getchar;
}
