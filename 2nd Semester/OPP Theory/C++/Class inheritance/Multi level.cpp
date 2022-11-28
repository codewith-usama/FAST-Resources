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
		void get_data()
		{
			person::getdata();
			cout << "Name of company: ";
			cin >> company;
			cout << "Salary: ";
			cin >> salary;
		}
		void dis()
		{
			person::display();
			cout << "\nName of company: " << company;
			cout << "\nSalary: " << salary;
		}
};
class programmer : public employee{
	int num;
	public:
		void getdata()
		{
			employee::get_data();
			cout << "Enter num of programming language known: ";
			cin >> num;
		}
		void display()
		{
			employee::dis();
			cout << "\nLanguages are: " << num;
		}
};
int main()
{
	programmer ob1;
	ob1.getdata();
	ob1.display();
}
