#include<iostream>
using namespace std;
int main()
{
	int arr[5];
	for(int i = 0; i < 5; i++)
	{
		cout << "Enter " << i+1 << " number: ";
		cin >> arr[i];
	}
	for(int i = 4; i >= 0; i--)
	{
		cout << "array is: " << arr[i] << endl;
	}
}
