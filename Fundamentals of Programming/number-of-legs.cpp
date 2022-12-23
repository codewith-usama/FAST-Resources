#include<iostream>
using namespace std;
int main()
{
	int cow,hen,pig,cowl,henl,pigl,sum;
	cout << "Enter the no of chicken:";
	cin >> hen;
	cout << "Enter the no of cow:";
	cin >> cow;
	cout << "Enter the no of pig:";
	cin >> pig;
	henl=2*hen;
	cowl=4*cow;
	pigl=4*pig;
	sum=henl+cowl+pigl;
	cout << "total no of legs is " << sum;
	
	
}
