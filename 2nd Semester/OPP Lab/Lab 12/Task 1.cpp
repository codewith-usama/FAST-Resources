#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main()
{
	int l;
	char str[100];
	char ch;
	ofstream fout;
	ifstream fin;
	cout << "Enter the string: ";
	cin.get(str,99);
	l = strlen(str);
	cout << "The length of string is:  ";
	cout << l;
	cout << endl;
	fout.open("lab-12", ios::out);
	fout << str;
	fout.close();
	cout << "The original string: ";
	fin.open("lab-12", ios::in);
	while(!fin.eof())
	{
		ch = fin.get();
		cout << ch;
	}
	fin.close();
}

