#include<iostream>
#include<string>
using namespace std;
int main()
{
	string Name;
	int marks[5];
	cout<<"Enter student Name: ";
	getline(cin,Name);
	
	
	int sum = 0;
	
	for(int i = 0; i <= 4; i++)
	{
		cout<<"Enter test "<<i+1<<" Marks: ";
		cin>>marks[i];
		sum = sum + marks[i];
	}
	
	system("cls");
	cout<<"Student Name is "<<Name;
	cout<<endl;
	for(int i = 0; i <= 4; i++)
	{
		cout<<marks[i]<<" ";
	}
	
	float avg;
	
	avg = sum / 5;
	
	cout<<endl<<"Average Marks is "<<avg;
}
