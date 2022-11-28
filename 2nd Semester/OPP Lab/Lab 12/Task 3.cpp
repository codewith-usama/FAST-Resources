#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class person
{
	public:
		int age;
		char name[50];
		person()
		{
			cout << "Enter the string: ";
			cin.getline(name, 50);
			cout << "Enter the age: ";
			cin >> age;
			display();
			cout << endl;
			write_in_file();
			cout << endl;
			read_from_file();
		}
		void display()
		{
			cout<<"The name will be : " << name << endl;
			cout<<"The age will be : " << age << endl;
		}
		void write_in_file()
		{
			ofstream fout;
			fout.open("oop-lab", ios::out| ios::binary);
			fout.write((char*)this,sizeof(*this));
			fout.close();
		}
		void read_from_file()
		{
			ifstream fin;
			fin.open("oop-lab", ios::in| ios::binary);
			fin.read((char*)this,sizeof(*this));
			while(!fin.eof())
			{
				display();
				fin.read((char*)this,sizeof(*this));
			}
			fin.close();
		}
};
int main()
{
	person ob1;
}

