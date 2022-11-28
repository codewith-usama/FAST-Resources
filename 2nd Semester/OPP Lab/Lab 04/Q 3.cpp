#include<iostream>
using namespace std;
class Invoice
{
	string part_num;
	string part_description;
	int quantity_of_the_item;
	double price_per_item;
	public:
		double getInvoiceAmount()
		{
			if(quantity_of_the_item < 0)
				quantity_of_the_item = 0;
			double amount = quantity_of_the_item * price_per_item;
			return amount;
		}
		Invoice(string part_num, string part_description, int quantity_of_the_item, double price_per_item)
		{
			this->part_num = part_num;
			this->part_description = part_description;
			this->quantity_of_the_item = quantity_of_the_item;
			this->price_per_item = price_per_item;
			double amount = getInvoiceAmount();
			if(amount < 0)
				amount = 0;
				cout << "The amount is "<<amount;	
		}			
};
int main()
{
	string num, description;
	int quantity;
	double price;
	cout << "Enter part num: ";
	cin >> num;
	cout << "Enter part description: ";
	fflush(stdin);
	getline(cin,description);
	cout << "Enter quantity of items: ";
	cin >> quantity;
	cout << "Price of items: ";
	cin >> price;
	Invoice ob1(num, description, quantity, price);
}
