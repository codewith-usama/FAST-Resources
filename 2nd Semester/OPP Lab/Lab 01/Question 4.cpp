#include<iostream>
using namespace std;
struct menuItemType
	{
		string menuItem;
		double menuPrice;
	}item;
	
int main()
{
	int choice;
	cout<<"Welcome to Johnny's Restaurant";
	cout<<endl<<"1.Plain Egg\t\t $1.45"<<endl<<"2.Bacon and Egg\t\t $2.45"<<endl<<"3.Muffin\t\t $0.99"<<endl<<"4.French Toast\t\t $1.99"<<endl<<"5.Fruit Basket\t\t $2.49"<<endl<<"6.Cereal\t\t $0.69"<<endl<<"7.Coffee\t\t $0.50"<<endl<<"8.Tea\t\t\t $0.75"<<endl;
	
	
	char i='y';
	
	while(i=='y')
	{
		cout << "Enter (1-8) for order anythig: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				cout << "Plain egg Order placed $1.45";
				item.menuPrice += 1.45;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 2:
				cout << "Bacon and Egg Order placed $2.45";
				item.menuPrice += 2.45;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 3:
				cout << "Muffin Order places $0.99";
				item.menuPrice += 0.99;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 4:
				cout << "French Toast Order placed $1.99";
				item.menuPrice += 1.99;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 5:
				cout << "Fruit Basket Order placed $2.49";
				item.menuPrice += 2.49;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 6:
				cout << "Cereal Order placed $0.69";
				item.menuPrice += 0.69;	
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 7:
				cout << "Coffee Order placed $0.50";
				item.menuPrice += 0.50;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;
			case 8:
				cout << "Tea Order placed $0.75";
				item.menuPrice += 0.75;
				cout << "\nDo you want to order anything else y/n? ";
				cin >> i;
				if(i == 'n')
					i = 'n';
				break;										
		}
	}
	system("cls");
	cout<<"Welcome to Johnny's Restaurant";
	
	cout << "\nTax $"<<item.menuPrice * 0.5;
	cout << "\nAmount Due $"<<item.menuPrice * 0.5 + item.menuPrice;
	
}
