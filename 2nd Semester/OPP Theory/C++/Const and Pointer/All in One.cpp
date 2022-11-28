#include<iostream>
using namespace std;
int main()
{
	int a = 10, b = 20;
	int *const ptr = &a;
	*ptr = 11;
	cout << *ptr;
}
//int main()
//{
//	int a = 10, b = 20;
//	int *ptr = &b;
//	ptr = &a;
//	cout << *ptr;
//}
