#include<iostream>
#include<string.h>
using namespace std;
void replace_not(string arr);
int main()
{
	string arr;
	cout << "Enter a string: ";
	getline(cin, arr);
	replace_not(arr);
}
void replace_not(string arr)
{
			if(arr.length() == 3 )
			{		
				arr[0] = 'n';
				arr[1] = 'o';
				arr[2] = 't';
			}	
	cout << arr;
}

