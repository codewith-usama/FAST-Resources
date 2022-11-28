#include<iostream>
#include<string.h>
using namespace std;
class coffee_shop
{
	string shop_name;
	public:
	struct menu_list
	{
		string name;
		string type;
		int price;
	}menu[8];
	public:
	char addorder(int serial, string name_of_item, menu_list Orders[])
	{
		char status;
		for(int i = 0; i < 8; i++)
		{
			if(menu[i].name == name_of_item)
			{
				status = 'Y';
				cout << "Item added." << endl;
				order[serial].name = menu[i].name;
				order[serial].type = menu[i].type;
				order[serial].price = menu[i].price;
			}
		}
		if(i == 8 && status != Y)
		{
			status = 'N';
			cout << "This item is currently unavailable!";
			return status;
		}
		else
		return status;
		
	}
	
	coffee_shop()
	{
		menu[0].name = "Biryani";
		menu[0].type = "Food";
		menu[0].price = 200;
		menu[1].name = "Palao";
		menu[1].type = "Food";
		menu[1].price = 250;
		menu[2].name = "Zinger";
		menu[2].type = "Food";
		menu[2].price = 650;
		menu[3].name = "Cake";
        menu[3].type = "Food";
        menu[3].price = 400;
        menu[4].name = "Samosa";
        menu[4].type = "Food";
        menu[4].price = 50;
		menu[5].name = "Sting";
		menu[5].type = "Drink";
		menu[5].price = 100;
		menu[6].name = "Due";
		menu[6].type = "Drink";
		menu[6].price = 70;
		menu[7].name = "Coffee";
        menu[7].type = "Drink";
        menu[7].price = 250;
		
		
		cout << "Enter shop name: ";
		getline(cin, shop_name);
		system("cls");
		cout << "Welcome to " << shop_name << " Cafe!" << endl
		<< endl
		<< "Following items are available at our cafe!\n";
		for(int i = 0; i < 8; i++)
		{
			cout << i+1 << ".Name of item " << menu[i].name << endl;
			cout << "  Type of item " << menu[i].type << endl;
			cout << "  Price " << menu[i].price << endl << endl;
		}
	}
};
int main()
{
	coffee_shop ob1;
	int num_of_items;
	string name;
	cout << "Enter num of item you want to order: ";
	cin >> num_of_items;
	coffee_shop::menu_list order[num_of_items];
	for(int i = 0; i < num_of_items; i++)
	{
		cout << "Enter name of item: " << i+1 << endl;
		getline(cin, name[i]);
		if(ob1.addorder(i, name, order) == 'N')
		{
			i--;
		}
	}
		
}
