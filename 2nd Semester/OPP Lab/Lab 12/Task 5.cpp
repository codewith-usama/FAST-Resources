#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int temp = 0;
	char ch, line[100];
	ifstream fin;
	fin.open("Story.txt", ios::in);
	ch = fin.get();
	while(!fin.eof())
	{
		ch = fin.get();
		if(ch == 'A')
		{
		    fin.getline(line,sizeof(line));
			temp++;
		}
	}
	cout << "The number of lines will be: " << temp;
	fin.close();
}

