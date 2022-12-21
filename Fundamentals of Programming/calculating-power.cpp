#include<iostream>
using namespace std;
int main()
{
	int current,voltage,power;
	cout << "Enter current :";
	cin >> current;
	cout << "Enter voltage :";
	cin >> voltage;
	power=current*voltage;
	cout << "The power is " << power;
}
