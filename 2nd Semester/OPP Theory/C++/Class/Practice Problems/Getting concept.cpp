#include<iostream>
using namespace std;
class A
{
	int *v1;
	public:
		A()
		{
		}
		A(int n)
		{
			v1 = new int[n];
//			cout<<n;
		}
		void useArray()
		{
			for(int i = 0; i < 2; i++)
			{
				v1[i] = i;
				cout << i;
			}
		
		}
};
int main()
{
	A ob1(3);
}
