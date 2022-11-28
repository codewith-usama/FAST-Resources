#include<iostream>
using namespace std;
class MyClass
{
	int ob1;
	public:
		MyClass(int a)
		{
			a = ob1;
		}
		~MyClass()
		{
			cout << "Destroying\n";
		}
};
void fun(void);
int main()
{
	fun();
	MyClass ob1(1);
	MyClass ob2(1);
	fun();
	
}
void fun()
{
	cout << "\nWelcome\n";
}
