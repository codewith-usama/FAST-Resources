#include<iostream>
using namespace std;
int main()
{
	string name[2];
	int num[2];
	char dep[2];
	for(int i = 0; i < 2; i++)
	{
		cout << "Student "<<i+1 << " data\n";
		cout << "Student Name: ";
		fflush(stdin);
		getline(cin,name[i]);
		cout << "Roll num: ";
		cin >> num[i];
		cout << "Department: ";
		cin >> dep[i];
	}
	for(int i = 0; i < 2; i ++)
	{
		cout << "\nName: "<<name[i] <<endl;
		cout << "Roll num: "<<num[i]<<endl;
		cout <<"department: "<<dep[i];
	}
	
}
