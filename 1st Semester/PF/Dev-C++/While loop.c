 #include <stdlib.h>
	main(){
		
		int num;
		int sum =0;
		char dec = 'y';
		//char ch;
		while( dec!= 'n'){
			
			printf("Enter a number:");
			scanf("%d", &num);
			sum += num;
			printf("Do you want to continue\n");
			scanf(" %c",&dec);
			
			//scanf("%d", &dec);
		}
		printf("%d",sum);
		// clrscr();
		 system("cls");
		// getch();
	}

