#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
struct Menu_food
{
	string name;
	double price;
	char code;
};
struct Menu_drink
{
	string name;
	double price;
	char code;
};	
class CoffeeShop
{
//	Menu_food menu[4] = {{"1.Zinger", 350, 'z'}, {"2.Chicken Tikka", 500, 'c'}, {"3.Palao", 200, 'p'}, {"4.Pizza", 700, 'p'}};
//	Menu_drink menu1[3] = {{"1.Tea", 150, 't'}, {"2.Soft drink", 170, 'd'}, {"Coffee", 250, 'c'}};
	string name;
	string order;
	public:
//	void add_order()
//	{
//		for(int i = 0; i < 6; i++)
//		{
//			order[i] = menu[i].name;
//		}
//	}	 
	void fulfillOrder()
	{
		cout << "\nYour order is placed.\n";
	}
	int num, quan;
	void food()
	{
		cout << "\n1.Zinger 350\n2.Chicken Tikka 500\n3.3.Palao 200\n4.Pizza 700\n";
		cout << "Enter your order: ";
		cin >> num;
		cout << "Enter Quantity: ";
		cin >> quan;
		fulfillOrder();
		add_order_food(num,quan);
	}
	void add_order_food(int num, int quan)
	{
		if(num == 1)
		{
			bill = 350 * quan;
			cout << "Your Bill is Rs "<< bill;
		}
		else if(num == 2)
		{
			bill = 500 * quan;
			cout << "Your bill is Rs "<< bill;
		}
		else if(num == 3)
		{
			bill = 200 * quan;
			cout << "Your bill is Rs "<< bill;
		}
		else if(num == 4)
		{
			bill = 700 * quan;
			cout << "Your bill is Rs "<< bill;
		}
	}
	void drink()
	{
		cout << "\n1.Tea 150\n2.2.Soft drink 170\n3.Coffee 250\n";
		cout << "Enter your code: ";
		cin >> num;
		cout << "Enter Quantity: ";
		cin >> quan;
		add_order(num, quan);
		fulfillOrder();
		
	}
	double bill = 0;
	double add_order(int num, int quan)
	{
		if(num == 1)
		{
			bill = 150 * quan;
			cout << "Your Bill is Rs "<< bill;
			return bill;
		}
		else if(num == 2)
		{
			bill = 170 * quan;
			cout << "Your bill is Rs "<< bill;
			return bill;
		}
		else if(num == 3)
		{
			bill = 250 * quan;
			cout << "Your bill is Rs "<< bill;
			return bill;
		}
		
	}
	
}; 
int main()
{
	CoffeeShop ob1;
	int num;
	char ch = 'y';
	while(ch == 'y')
	{
	cout << "Online Resturant Placement";
	cout << "\n What do you want to order??\n1.Food items\n2.Drinks\n";
	cin >> num;
	if(num == 1)
	{
		ob1.food();
	}
	else if(num == 2)
	{
		ob1.drink();
	}
	else 
	cout << "Wrong code Entered.";
	cout << "\nWanna order y/n: ";
	cin >> ch;
	if(ch == 'n' || ch == 'N')
		ch = 'n';
	else
	system("cls");
	continue;
	}
}
