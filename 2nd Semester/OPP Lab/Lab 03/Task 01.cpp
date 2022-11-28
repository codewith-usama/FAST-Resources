#include<iostream>
using namespace std;
class user
{
	int age;
	string name;
	public:
		void setage(int age)
		{
			this->age = age;
		}
		int getage()
		{
			return age;
		}
		void setname(string name)
		{
			this->name = name;
		}
		string getname()
		{
			return name;
		}
};
int main()
{
	user ob1;
	string name;
	int age;
	for(int i = 0; i < 2; i++)
	{
		cout << "Enter Name: ";
		fflush(stdin);
		getline(cin,name);
		cout << "Enter Age: ";
		cin >> age;
		ob1.setname(name);
		ob1.setage(age);
	
		cout << "Name: "<<ob1.getname();
		cout << "\nAge: "<<ob1.getage() << endl;
	}
}
