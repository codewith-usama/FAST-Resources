#include<iostream>
using namespace std;
template  <class y, class z>
y function(y a, z b) {
	y c;
	c = a;
	a = b;
	cout << "The number after swaping will be: " << a << "   " << c;
}
int main() {
	int num1, num2;
	cout << "Enter num1: ";
	cin >> num1;
	cout << "Enter num2: ";
	cin >> num2;
	function(num1, num2);
}

