#include<iostream>
using namespace std;
class A
{
	int * x;
	int * y;
	public:
		A(int x, int y)
		{
			this->x = new int; // Memory allocate for int variable of class
			* this->x = x; // De refrencing of memory allocation
			this->y = new int;
			* this->y = y; 
		}
		A(){ }
		void setX(int x)
		{
			*this->x = x;
			display();
		}
		void setY(int y)
		{
			*this->y = y;
			display();
		}
		void display()
		{
			cout << *x << endl;
			cout << *y << endl;
		}
		A(const A & ob)
		{
			x = new int;
			*x = *ob.x;
			y = new int;
			*y = *ob.y;
			display();
		}
};
int main()
{
	A ob1(5,2);
	A ob2(ob1);
	ob2.setX(99);
	ob2.setY(22);
}
