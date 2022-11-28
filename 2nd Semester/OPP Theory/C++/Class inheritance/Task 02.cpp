#include<iostream>
using namespace std;
class employee{
	string l_name;
	int num_of_emp;
	public:
		void display(){
			cout << "Name: " << l_name;
			cout << "\nNum of Employees :" << num_of_emp; 
		}
		employee(string l_name, int num){
			this->l_name = l_name;
			num_of_emp = num;
		}
};
class manager : public employee{
	string title;
	double club_dues;
	public:
};
class scientist : public employee{
	string title;
	int publication;
	public:
};
class laborer : public employee{
	string title;
	public:
		void display(){
			employee::display();
		}
};
int main()
{
	employee ob1("Usama", 45);
}
