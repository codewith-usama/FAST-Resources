#include<stdio.h>
main()
{
	char cc;
	system("Color 0A");
	printf("		\t\t\t\t\tWELCOME TO FAST-NUCES's CAFETERIA");
	printf("\n\n1. Roll Paratha\tRs.50\n2. Mayo Roll\tRs.60\n3. BBQ Roll\tRs.80\n4. Aandy Wala Burger\tRs.50\n5. French Ferries\tRs.30\n6. French Ferries\tRs.50\n7. French Ferries\tRs.100\n8. Chai\t\t\tRs.30\n9. Biscuits\n");
	scanf("%c", &cc); // "CC" is used to store the code for Cafeteria menu
	
	int rpo, mro;
	switch(cc)
	{
		case '1':
			printf("How many Roll Paratha do you want to order: ");
			scanf("%d", &rpo); // "rpo" is used to store the quantity of ordered Roll Paratha
			printf("50*%d = %d", rpo, 50*rpo);
			printf("\nRs .%d is you bill\nThank You", 50*rpo);
			break;
		case '2':
			printf("\nHow many Mayo Roll do you ant to order: ");
			scanf("%d", &mro); // "mro" is used to store the quantity of ordered Mayo Roll	
			printf("60*%d = %d", mro, 60*mro);
			printf("\nRs. %d is your bill \nThank you", 60*mro);
			break;
	}
}
