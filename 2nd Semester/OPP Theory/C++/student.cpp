#include<iostream>
using namespace std;
class student{
	string name;
	string roll_num;
	string semester;
	string sec;
	public:
		void display()
		{
			cout << "Name: " << name;
			cout << "\nRoll Num: " << roll_num;
			cout << "\nSemester: " << semester;
			cout << "\nSec: " << sec;
		}
		student(string name, string roll_num, string semester, string sec)
		{
			this->name = name;
			this->roll_num = roll_num;
			this->semester = semester;
			this->sec = sec;
		}
};
int main()
{
	string name, roll_num, semester, sec;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter roll num: ";
	getline(cin, roll_num);
	cout << "Enter semester: ";
	getline(cin, semester);
	cout << "Enter sec: ";
	getline(cin, sec);
	student ob1(name, roll_num, semester, sec);
	ob1.display();
}
