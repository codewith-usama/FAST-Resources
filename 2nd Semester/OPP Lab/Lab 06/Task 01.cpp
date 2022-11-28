#include<iostream>
#include<math.h>
using namespace std;
class circle
{
	float radius;
	public:
		static int count;
	circle()
	{
		++count;
	}
	circle(float radius)
	{
		this->radius = 	radius;
		++count;
	}
	float getarea()
	{
		return pow(radius, 2) * 3.142;	
	}	
};
int circle :: count = 0;
int main()
{
	circle ob1;
	circle ob2;
	circle ob3;
	circle ob4(2);
	cout << ob4.getarea() << endl;
	cout << circle :: count;	
}
