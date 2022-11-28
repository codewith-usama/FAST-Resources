#include <stdio.h>
int main()
{
	int day,month,year,c=0,a;
	char ch;

while(1)	{
fflush(stdin);
	if(ch=='N' || ch=='n'){
		break;
	}
else

        printf("Enter date (Days/Month/Year structure:) ");
        scanf("%d/%d/%d",&day,&month,&year);
        if(year>=1900 || year<=9999)//to check year 
        {
        	if(month>=1 && month<=12){//to check month
            
            	if((dd>=1 && dd<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))//check days
                {
                	c=0;
                	printf("Date is valid.\n");
                	c++;
				}
                else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                {
                	c=0;
                	printf("Date is valid.\n");
                	c++;
				}
                else if((day>=1 && day<28) && (month==2))
                {
                	c=0;
                	printf("Date is  valid.\n");
                	c++;
                }
				
                 if(day==28 && month==2) {
				 
                {
                	c=0;
                	printf("Date is valid.\n");
                	c++;
				}
		
                if(day>28)	{
					
                	printf("Day is invalid.\n");
				}
			}
		
			
			else
			if(month>12){
			
				printf("Month is not valid.\n");
			}
}
else
    {
	
       	  printf("Year is not valid.\n");
	  }

}


	   if(c==1)
	   {
	   	    printf("\nChecking year is leap year or not...");
	   	    if(year % 4!=0)
            {
            	if( year % 100)
                {
                	if ( year % 400)
            	    {
            	       printf("%d is a Leap Year\n",year);
            	     fflush(stdin);
                	 printf("WANT MORE PRESS EXPECT THAN  N\n");
            	       scanf("%c",&ch);
			        }
				}
                else
                {
                	printf("%d is not a Leap Year\n",year);
                	 fflush(stdin);
                	 printf("WANT MORE PRESS EXCEPT THAN N\n");
            	       scanf("%c",&ch);
				}
            }
            else
            {
            	printf("%d is a Leap Year\n",year);
            	 fflush(stdin);
            	  printf("WANT MORE PRESS EXCEPT THAN N\n");
            	       scanf("%c",&ch);
			}
	
	   }
}

	  }
