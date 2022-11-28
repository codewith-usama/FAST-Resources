#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class A
{
	public:
		char ID[15];
		char name[20];
		int score;
	void input()
	{
		cout << "Enter the ID: ";
		cin.ignore();
		cin.get(ID, 15);
		cout << "Enter the name: ";
		cin.ignore();
		cin.get(name,19);
		cout << "Enter the score: ";
		cin >> score;
	}
	void display()
	{
		cout << "ID :" <<ID << endl;
		cout << "NAME:" << name << endl;
		cout << "SCORE: " << score << endl;
	}
	void write();
	void read();
	void search();
};
void A::write()
{
	ofstream fout;
	fout.open("k20-0190", ios::app| ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}
void A::read()
{
	ifstream fin;
	fin.open("k20-00190", ios::in| ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!fin.eof())
		display();
		
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
void A::search()
{
	char ser[15];
	cout<<"Enter thr id for searching the details: ";
	cin.getline(ser,15);
	ifstream fin;
	fin.open("k20-0190", ios::in| ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(ser,ID))
		{
			display();
			fin.read((char*)this,sizeof(*this));
		}
		display();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}

int main()
{
	A ob1;
	ob1.input();
	ob1.write();
	ob1.read();
}

