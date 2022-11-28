#include<iostream>
using namespace std;
class A
{
	public:
		static int total, sum;
		int cost;
		A()
		{
			cost = 0;
			++total;
		}
		A(int cost)
		{
			this->cost = cost;
			sum += cost;
			++total;
		}
}; int A :: total = 0; int A :: sum = 0;
int main()
{
	A ob1;
	A ob2;
	A ob3(500);
	A ob4(550);
	cout << "Num of objects are "<<A::total << endl;
	cout << "Sum is "<< A :: sum << endl;
}
