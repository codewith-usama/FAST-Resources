#include<iostream>
using namespace std;
int main()
{
	int a = 10, b = 20;
	const int *ptr = &a;
	ptr = &b;
//	*ptr = 12;
	cout << *ptr;
}
inline void

//int main() both no const
//{
//	int a= 10, b = 20;
//	int *ptr = &a;
//	cout << *ptr;
//	ptr = &b;
//	cout << *ptr;
//}
