#include<iostream>
using namespace std;
class add
{
	static int a, b;
	public:
		int sum()
		{
			return a + b;
		}
};
int add :: a = 10, add :: b = 14;
int main()
{
	add ob1;
	cout << ob1.sum();
}
