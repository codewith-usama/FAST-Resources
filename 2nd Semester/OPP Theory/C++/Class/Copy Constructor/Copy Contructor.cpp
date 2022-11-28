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
			*x = 0;
			*y = 1;
			cout << "In null constructor "<< *x << " " << *y;
		}
		A(int a, int b)
		{
			x = new int;
			y = new int;
			*x = a;
			*y = b;
			cout << "In parametrized constructor "<< *x << " " << *y;
		}
//		private:
		A(const A & o)
		{
			x = new int;
			y = new int;
			*x = *o.x;
			*y = *o.y;
			cout << "\nIn copy constructor "<< *x << " " << *y;
		}
		public:
		void setXY(int x, int y)
		{
			*this->x = x;
			*this->y = y;
			display();
		}
		void display()
		{
			cout << "\nAfter "<< *x << " " << *y;
		}
};
int main()
{
	A ob1(10,12);
	A ob2(ob1);
	ob2.setXY(11,15);
	A ob3(1,2);
	ob1.display();
	ob2.display();
}
