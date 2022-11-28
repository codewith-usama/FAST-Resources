#include<iostream>
using namespace std;
class Car
{
	public:
	string model;
	string name;
	int seats;
	void brake()
	{
		cout << "Applying brake";
	}
};
int main() 
{
	Car ob1;
	int select;
	cout << "Enter Car Model: ";
	cin >> ob1.model;
	cout << "Enter Car Name: ";
	cin >> ob1.name;
	cout << "ENter seat Capacity: ";
	cin >> ob1.seats;
	cout << "Enter 1 for applying brake: ";
	cin >> select;
	if(select == 1)
	ob1.brake();
	else
	cout << "Fail to apply brake.";
}
