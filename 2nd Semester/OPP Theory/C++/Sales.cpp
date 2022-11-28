#include<iostream>
#include <bits/basic_string.h>
using namespace std;
class sales{
	int id;
	string name;
	int quantity;
	public:
		void display()
		{
			cout << "Name: " << name;
			cout << "\nID: " << id;
			cout << "\nQuantity: " << quantity;
		}
		sales(int id, string name, int quantity)
		{
			this->name = name;
			this->id = id;
			this->quantity = quantity;
		}
		sales(const sales & ob )
		{
//			
			name = ob.name;
			id = ob.id;
			quantity = ob.quantity;
		}
};
int main()
{
	string name;
	int quantity, id;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter Quantity: ";
	cin >> quantity;
	sales ob1(id, name, quantity);
	ob1.display();
	sales ob2(ob1);
	ob2.display();
}
