#include<iostream>
using namespace std;
template <class x>
x array(x a[],x n) {
	x temp;
	cout << "Enter the position: ";
	cin >> temp;
	cout << "At position: " << temp << " Value will be: " << a[temp - 1];
}
int main() {
	int n;
	int a[10];
    cout << "Enter the lenght of the array: ";
	cin >> n;
	cout << "Now enter the values of the array: ";
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	array(a, n);
}

