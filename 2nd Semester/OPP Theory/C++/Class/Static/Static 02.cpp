#include<iostream>
using namespace std;
class A
{
	static int var1;
	float var2;
	public:
		static void f()
		{
			var1 = 20;
//			var2 = 22.1;
		}
}; int A :: var1 = 50;
int main()
{
	A ob1;
	A ob2;
	cob1.f();
//	cout << A :: f();
	
}
