#include<iostream>
using namespace std;
class Employee
{
	public:
	double salary;
	string f_name;
	string l_name;
};
int main()
{
	Employee ob1;
	Employee ob2;
	cout << "Enter First name: ";
	cin >> ob1.f_name;
	cout << "Enter Last name: ";
	cin >> ob1.l_name;
	cout << "Enter Salary: ";
	cin >> ob1.salary;
	if(ob1.salary < 0)
	{
		ob1.salary = 0.0;
		fflush(stdin);
	}
	cout << "\nEnter First name: ";
	cin >> ob2.f_name;
	cout << "Enter Last name: ";
	cin >> ob2.l_name;
	cout << "Enter Salary: ";
	cin >> ob2.salary;
	if(ob2.salary < 0)
	{
		ob2.salary = 0.0;
		fflush(stdin);
	}
	system("cls");
	cout << endl << "Name: " << ob1.f_name << " " << ob1.l_name;
	cout << endl << "Salary: " << ob1.salary << " After Raising: " << (ob1.salary * 0.1) + ob1.salary;
	
	cout << endl << "Name: " << ob2.f_name << " " << ob2.l_name;
	cout << endl << "Salary: " << ob2.salary << " After Raising: " << (ob2.salary * 0.1) + ob2.salary;
	
}
