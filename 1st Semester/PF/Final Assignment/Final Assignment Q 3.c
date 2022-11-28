#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct player
{
    char name[50];
    int age;
};


int main() 
{
        FILE *fp;
        int array[9], l, m, player, f, i, k, j;
        int n = 0, c = 0;
        struct player p1;
        struct player p2;
        char plyr[50];
        system("Color 0A");

        printf("Enter the name of Player 1: ");
        scanf("%s",p1.name);

        printf("Enter the Age of player 1: ");
        scanf("%d",&p1.age);

        printf("\nEnter the name of Player 2: ");
        scanf("%s",p2.name);

        printf("Enter the Age of player 2: ");
        scanf("%d",&p2.age);
        
        for (i = 0; i < 9; i++)
                array[i] = ' ';

        while (c < 9) 
		{
                f = 0;
                system("cls");
                printf("\n\n");
                printf("\t\t\t  %c | %c  | %c  \n", array[0], array[1], array[2]);
                printf("\t\t\t----+----+----\n");
                printf("\t\t\t  %c | %c  | %c  \n", array[3], array[4], array[5]);
                printf("\t\t\t----+----+---\n");
                printf("\t\t\t  %c | %c  | %c  \n", array[6], array[7], array[8]);
                if (c % 2 == 0)
				{
                        m = 'X';
                        player = 1;
                }
				else
				{
                        m = 'O';
                        player = 2;
                }
                if(player==1)
				{
                    strcpy(plyr,p1.name);
                }
                else if(player==2)
				{
                    strcpy(plyr,p2.name);
                }
                printf("%s's turn |Enter between|(1-9):", plyr);
                scanf("%d", &l);
                if (l < 1 || l > 9) 
				{
                        printf("Please enter between 1-9\n");
                        continue;
                }
                if (array[l - 1] == 'X' || array[l - 1] == 'O') 
				{
                        printf("Please Enter the place value again,place occuppied\n");
                        sleep(20);
                        continue;
                }
                array[l - 1] = m;
                c++;

                for (i = 0; i < 9; i++) 
				{
                        if (i % 3 == 0)
                                f = 0;

                        if (array[i] == m)
                                f++;

                        if (f == 3) 
						{
                                n = 1;
                                goto win;
                        }
                }

                f = 0;
                for (i = 0; i < 3; i++) 
				{
                        for (k = i; k <= i + 6; k = k + 3) 
						{
                                if (array[k] == m)
                                        f++;
                        }
                        if (f == 3) 
						{
                                n = 1;
                                goto win;
                        }
                        f = 0;
                }
                
                if ((array[0] == m && array[4] == m && array[8] == m) ||
                        (array[2] == m && array[4] == m && array[6] ==  m)) 
						{
                	        n = 1;
                    	    goto win;
		                }
        }
  win:
        system("cls");
        printf("\n\n");
        printf("\t\t\t  %c | %c  | %c  \n", array[0], array[1], array[2]);
        printf("\t\t\t----+----+----\n");
        printf("\t\t\t  %c | %c  | %c  \n", array[3], array[4], array[5]);
        printf("\t\t\t----+----+---\n");
        printf("\t\t\t  %c | %c  | %c  \n\n", array[6], array[7], array[8]);
        if (n) 
		{
                printf("%s is the winner\nCongratulations!!\n", plyr);
                fp=fopen("gamehistory.txt", "a");
                
                char wdecide[50];
                
                strcpy(wdecide,plyr);
                strcat(wdecide, " won the game");
                fprintf(fp," \n%s",wdecide );
                fclose(fp);
        } 
		else 
		{	
                printf("Game Draw\n");
        }

        return 0;
  }
