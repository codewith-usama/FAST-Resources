#include<iostream>
using namespace std;
class A
{
	int *x, *y;
	public:
		A()
		{
			x = new int;
			y = new int;
			*x = 10;
			*y = 20;
		}
		void display()
		{
			cout << "Value is "<< *x << " " << *y;
		}
		A(const A & ob)
		{
			x = new int;
			y = new int;
			*x = *(ob.x);
			*y = *(ob.y);
		}
		void set(int x, int y)
		{
			*this->x = x;
			*this->y = y;
		}
};
int main()
{
	A ob1;
	A ob2 = ob1;
	ob1.display();
	cout << endl;
	ob2.display();
	ob2.set(1,2);
	cout << endl;
	
	ob1.display();
	cout << endl;
	ob2.display();
}
