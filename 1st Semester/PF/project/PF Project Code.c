#include <stdio.h>
//#include <stdlib.h>

main()
{
	int ec;
	system("Color 3A");
	printf("\t\t\t\t\t		WELCOME TO FAST-NUCES\nStudent Press 1\nVisitor Press 2\n");
	scanf("%d", &ec); // "ec" used to store Enterance code
	int sc, i;
	for(i=1;i<=ec;i++)
	{
		
		if(ec==1)
		{
			printf("Welcome dear student\nPress 1 for Classes Shedule\nPress 2 for up Coming Event\nPress 3 for Socieyies Information\nPress 4 for Cafetetia and Dhaba price list\n");
			scanf("%d", &sc); // "sc" used to Store Students code

			if(sc==1)
			{
				printf("Slots\t	1		2		3		4		5		6		7	        8");
				printf("\nTimings\t      09-9:50	    9:50-10:40     10:45-11:35     11:35-12:25     12:30-01:20\t   01:20-02:10     02:15-03:05    03:05-03:55");
				printf("\n	  						   CLASSROOMS\n");
				printf("\n\t      Algo-5H			      DB-5G			     Algo-5G	   FM- 5D(E,F)	       DB-5F\n\t      Sohail			      Farah		   	     Dr.Atif	    Dr.Nazia	    Faizadullah");
				printf("\n\n\t      SDA-5A	     SDA-5A	     SDA-5D			   ISE BSE-3A	   ISE BSE-3A	      Algo-5E\n\t      Rubab	     Rubab	  Javeria Farooq		      Rubab	      Rubab	      Sohail");
				printf("\n\n\t      FM- 5C(C,D)    Algo-5C	     DB-5C	   		   WP-7A(A,B)	   SM- 5A(E,F,G,H)\n\t      Zeeshan Khan   Sohail	   Dr. Zulfiqar			   Abdul Rahman	     Dr. Saad");
				printf("\n\n\t      Algo-5G	     DB-5D	     HCI-7B		              HCI-7F	      ISS-7F\n\t      Dr. Atif	     Anum Qureshi    Farrukh		      	     Farrukh        Dr. Sufian");
				//PRINTF("\n\n\t")
				return 0;
			}
		}
	}
}
