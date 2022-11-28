#include<iostream>
using namespace std;
class person{
	char name[100], gender[100];
	int age;
	public:
		getdata()
		{
			cout << "Name: ";
			cin >> name;
			cout << "Age: ";
			cin >> age;
			cout << "Gender: ";
			cin >> gender;
		}
		void display()
		{
			cout << "Name: " << name;
			cout << "\nAge: " << age;
			cout << "\nGender: " << gender;
		}
};
class employee : public person{
	char company[100];
	float salary;
	public:
		void getdata()
		{
			person::getdata();
			cout << "Name of company: ";
			cin >> company;
			cout << "Salary";
			cin >> salary;
		}
		void display()
		{
			person::display();
			cout << "\nName of company: " << company;
			cout << "\nSalary: " << salary;
		}
};
int main()
{
	employee ob1;
	cout << "Enter data\n";
	ob1.getdata();
	cout << "Display data\n";
	ob1.display();
}
