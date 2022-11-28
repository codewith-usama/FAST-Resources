#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main()
{
	int l;
	char str[100];
	char ch;
	ifstream fin;
	cout<<"The string is from file: ";
	fin.open("lab-12", ios::in);
	while(!fin.eof())
	{
		ch = fin.get();
		cout<<ch;
	}
	fin.close();
	cout<<endl;
	cout<<"Now we copy the string the into other file: ";
	ofstream fout;
	fout.open("copiedfile", ios::out);
	fout << ch;
	fout.close();
}

