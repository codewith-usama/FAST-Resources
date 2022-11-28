#include<iostream>
#include<string>
using namespace std;
class student
{
	public:
	string name;
	int roll_num;
	string address;
	string number;
};
int main()
{
	student ob1;
	for(int i = 0; i < 3; i++)
	{
	
		cout << "Student 1 Data.";
		cout << "\nEnter Name: ";
		cin.getline(cin,ob1[i].name);
		cout << "Enter Roll Num: ";
		cin >> ob1[i].roll_num;
		cout << "Enter Address: ";
		cin.getline(cin,ob1[i].address);
		cout << "Enter Phone Num: ";
		getline(cin,ob1[i].number);
	}
	
//	cout << "Student 2 Data.";
//	cout << "\nEnter Name: ";
//	getline(cin,ob2.name);
//	cout << "Enter Roll Num: ";
//	cin >> ob1.roll_num;
//	cout << "Enter Address: ";
//	getline(cin,ob2.address);
//	cout << "Enter Phone Num: ";
//	getline(cin,ob2.number);
}
