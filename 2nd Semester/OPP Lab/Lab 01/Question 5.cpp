#include<iostream>
#include<string>
using namespace std;
struct Game
{
	string Name;
	int home_runs, hits;
}player[10];
int main()
{
	for(int i = 0; i < 10; i++)
	{
		cout << "Player "<<i+1<<" Data";
		cout << "\nName: ";
		fflush(stdin);
		getline(cin,player[i].Name);
		
		cout << "Enter Home Runs: ";
		cin >> player[i].home_runs;
		
		cout << "Enter Number of Hits: ";
		cin >> player[i].hits;
		
		system("cls");
	}
	int search;
	cout << "Enter Index number to find the data: ";
	cin >> search;
	
	cout << "Name -> "<<player[search].Name;
	cout << "\nHome Runs -> "<<player[search].home_runs;
	cout << "\nHits -> "<<player[search].hits;
	
	
	char choice='y'; 
	int choice1;
	
	cout << "\nDo you want to change the data y/n? ";
	cin >> choice;
	
	if(choice=='n')
		choice='n';
		
	while(choice=='y')
	{
		cout << "Press 1 to change the Name.\nPress 2 to change the Home runs.\nPress 3 to change the Hits\nYour Choice: ";
		cin >> choice1;
		switch(choice1)
		{
			case 1:
				cout << "Enter New Name: ";
				fflush(stdin);
				getline(cin,player[search].Name);
				cout << "Do you want to change more settings y/n? ";
				cin >> choice;
				if(choice=='n')
					choice='n';
				break;		
			case 2:
				cout << "Enter Player's New Home runs: ";
				cin >> 	player[search].home_runs;
				cout << "Do you want to change more settings y/n? ";
				cin >> choice;
				if(choice=='n')
					choice='n';
				break;
			case 3:
				cout << "Enter Player's New hits: ";
				cin >> player[search].hits;
				cout << "Do you want to change more settings y/n? ";
				cin >> choice;
				if(choice=='n')
					choice='n';
				break;		
		}
		system("cls");
	}
	
	
	cout << "\n\n\t\t*********************\n\t\t  Player New Record\n\t\t*********************";
	for(int i = 0; i < 10; i++)
	{
		cout << "\n\t\tName -> "<<player[i].Name;
		cout << "\n\t\tHome Runs -> "<<player[i].home_runs;
		cout << "\n\t\tHits -> "<<player[i].hits;
	}
	
}
