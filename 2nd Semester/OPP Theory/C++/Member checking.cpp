#include<iostream>
using namespace std;
class membertype{
	string name;
	string id;
	int num_of_book;
	double amount;
	public:
		membertype& set_name(string name)
		{
			this->name = name;
			return *this;
		}
		membertype& set_num_of_book(int num)
		{
			num_of_book = num;
			return *this;
		}
		membertype& set_amount(double amount)
		{
			this->amount = amount;
			return *this;
		}
		void display(){
			cout << name << " of ID " << id << " bought " << num_of_book << " books of Rs " << amount << ".\n";
		}
		membertype()
		{
		}
		membertype(string name, string id, int num_of_book, double amount)
		{
			this->name = name;
			this->id = id;
			this->num_of_book = num_of_book;
			this->amount = amount;
		}
};
int main()
{
	double amount;
	string name, id;
	int num;
	cout << "Enter person name: ";
	getline(cin, name);
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter num of books bought: ";
	cin >> num;
	cout << "Amount spend: ";
	cin >> amount;
	membertype ob1(name, id, num, amount);
	ob1.display();
	ob1.set_name("Ahmed").set_num_of_book(55).set_amount(5000);
	ob1.display();
}
