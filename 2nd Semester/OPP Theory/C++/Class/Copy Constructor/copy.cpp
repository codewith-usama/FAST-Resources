#include<iostream>
using namespace std;
class A
{
	int *x;
	public:
		A()
		{
			x = new int;
			*x = 0;
		}
		A(int a)
		{
			x = new int;
			*x = a;
			cout << "In contructor " <<*x;
		}
		A(const A & o)
		{
			x = new int;
			*x = *o.x;
			cout << "\nIn copy " << *x;
		}
		void setX(int x)
		{
			*this->x = x;
		}
		void display()
		{
			cout <<endl << *x;
		}
};
int main()
{
	A ob1(5);
	A ob2(ob1);
	ob2.setX(10);
	ob2.display();
	
}
