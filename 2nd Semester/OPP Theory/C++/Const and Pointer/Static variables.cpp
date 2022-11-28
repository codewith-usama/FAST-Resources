#include<iostream>
using namespace std;
class A
{
	public:
		static int count, total;
		int cost;
		A()
		{
			cost = 0;
			count++;
		}
		A(int cost)
		{
			this->cost =  cost;
			total +=cost;
			count++;
		}
};
int A :: count = 0, A :: total = 0;
int main()
{
	A ob1(55);
	A ob2(22);
	A ob3(3);
	A ob4(20);
	cout << A :: count;
	cout << endl << A :: total;
}
