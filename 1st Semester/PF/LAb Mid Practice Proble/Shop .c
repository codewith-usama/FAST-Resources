#include<stdio.h>
main()
{
	printf("\t\tSHOP OVER RS.3000 AND ENJOY 10%% DICSCOUNT\n");
	int itp, tp, fp, wp, ta, discount, ap, ar, ap1, ar1, ntp;
	printf("\nEnter the total number of items purchased by the customer:");
	scanf("%d", &itp);
	printf("Number of T-shirts purchased:");
	scanf("%d", &tp);
	printf("Number of formal shirts purchased:");
	scanf("%d", &fp);
	printf("Number of Wrist Watches purchased:");
	scanf("%d", &wp);
	ntp=tp+fp+wp;
	
		if(itp==ntp)
		{
			ta=(tp*500)+(fp*1000)+(wp*500);
			printf("\nYour total amount is Rs.%d", ta);
    	    if(ta>3000)
    		{
			printf("\nCongratulations! You have purchased items of over Rs.3000, Enjoy the 10%% discount on total.");
			discount=ta*0.9;
			printf("\nYou bill after discount is %d", discount);
			printf("\nAmount provided by the customer:");
			scanf("%d", &ap);
			ar=ap-discount;
			printf("\nAmount returned:%d", ar);
			printf("\nThank you for shoppping.");
			return 0;
			}
			else
    		{	
				printf("\nAmount provided by the customer:");
    			scanf("%d", &ap1);
    			ar1=ap1-ta;
    			printf("\nAmount returned:%d", ar1);
    			printf("\nThank you for shopping.");
    			return 0;	
			}
    	}
    	
   		else
   		printf("Invalid values please recount for best shopping experience."); 
   		
}
