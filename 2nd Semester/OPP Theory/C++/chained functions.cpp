#include<iostream>
using namespace std;
class A
{
	int x, y;
	public:
		A(){}
		A& setx(int a)
		{
			x = a;
			return *this;
		}
		A& sety(int b)
		{
			y = b;
			return *this;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
};
int main()
{
	A ob;
	ob.setx(2).sety(23);
	cout << ob;
	cout << ob.getx() << " " << ob.gety();
}
