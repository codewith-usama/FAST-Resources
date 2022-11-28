#include<iostream>
#include<string.h>
using namespace std;
class coffee_shop{
	public:
	static float amount;
    string CoffeeShop_name;
    struct Menuitem
    {
        string name;
        string type;
        double price;
    } Menu[8];
    public:
    char add_order(int serial_num, string name, Menuitem order[])
    {
    	char status;
    	int i;
    	for(i = 0; i < 7; i++)
    	{
    		if(name == Menu[i].name)
    		{
    			status = 'Y';
    			cout << "Item added.";
    			order[serial_num].name = Menu[i].name;
    			order[serial_num].type = Menu[i].type;
				order[serial_num].price = Menu[i].price;
			}
		}
		if (status != 'Y')
        {
            status = 'N';
            cout << "Item does not exist" << endl;
            return status;
        }
	}
	void fulfill_order()
	{
		cout << "\nOrder Completed.\n";
	}
	
	float due_amount(Menuitem order[], int num)
	{
		for(int i = 0; i < num; i++)
		{
			amount += order[i].price;
		}
		return amount;
	}
	void list_order(Menuitem order[], int serial_num)
	{
		system("cls");
		cout << "Following is the list of your order.\n";
		for(int i = 0; i < serial_num; i++)
		{
			cout << "\nName: " << order[i].name;
			cout << "\nType: " << order[i].type;
			cout << "\nPrice: " << order[i].price;
		}
		fulfill_order(); cout << endl;
	}
	void drink(Menuitem order[], int num)
	{
		cout << "\nYour order for Drink item is";
		for(int i = 0; i < num; i++)
		{
			if(order[i].type == "Drink")
			{
				cout << "\nName: " << order[i].name;
			}
		}
		cout << endl;
	}
	string cheap_item(Menuitem order[], int num)
	{
		string cheap_item;
		double min = 99999;
		for(int i = 0; i < num; i++)
		{
			if(order[i].price < min)
			{
				min = order[i].price;
				cheap_item = order[i].name;
			}
		}
		return cheap_item;
	}
	void food(Menuitem order[], int num)
	{
		cout << "\nYour order for Food item is";
		for(int i = 0; i < num; i++)
		{
			if(order[i].type == "Food")
			{
				cout << "\nName: " << order[i].name;
			}
		}
		cout << endl;
 }
    coffee_shop()
    {
    	Menu[0].name = "Tea";
        Menu[0].type = "Drink";
        Menu[0].price = 30;
        Menu[1].name = "Coffee";
        Menu[1].type = "Drink";
        Menu[1].price = 50;
        Menu[2].name = "Sandwich";
        Menu[2].type = "Food";
        Menu[2].price = 100;
        Menu[3].name = "Mayo-Roll";
        Menu[3].type = "Food";
        Menu[3].price = 80;
        Menu[4].name = "Pizza (small)";
        Menu[4].type = "Food";
        Menu[4].price = 80;
        Menu[5].name = "Cake";
        Menu[5].type = "Food";
        Menu[5].price = 60;
        Menu[6].name = "Cold Drink";
        Menu[6].type = "Drink";
        Menu[6].price = 50;
        Menu[7].name = "Biryani";
        Menu[7].type = "Food";
        Menu[7].price = 70;
        
        cout << "Enter the name of shop: ";
        getline(cin, CoffeeShop_name);
        system("cls");
        cout << "Welcome to " << CoffeeShop_name << " Cafe!" << endl
        << "Following items are avaliable on cafe.\n\n";
        for(int i = 0; i < 7; i++)
        {
        	cout << "Name: " << Menu[i].name;
        	cout << "\nType: " << Menu[i].type << endl;
        	cout << "Price: " << Menu[i].price << endl << endl;
		}
	}
};
float coffee_shop::amount = 0;
int main()
{
	coffee_shop ob1;
	int num;
	cout << "\nEnter number of items you want to order: ";
	cin >> num;
	string name_of_item;
	coffee_shop::Menuitem order[num];
	for(int i = 0; i < num; i++)
	{
		cout << "\nEnter the name of product " << i + 1 << endl;
		fflush(stdin);
		getline(cin, name_of_item);
		if(ob1.add_order(i, name_of_item, order) == 'N')
		{
			i--;
		}
	}
	ob1.list_order(order, num);
	cout << "Your total bill is: " << ob1.due_amount(order, num);
	cout << "\nThe cheap item you bought is " << ob1.cheap_item(order, num) << endl;
	ob1.drink(order, num);
	ob1.food(order, num);
}
