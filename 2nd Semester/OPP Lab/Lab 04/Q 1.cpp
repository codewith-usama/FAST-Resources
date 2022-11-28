#include<iostream>
#include<cmath>
using namespace std;
class circle
{
	double radius;
	public:
		void getArea(double radius)
		{
			cout << "Radius is: " << pow(radius,2);
		}
		void getPerimeter(double radius)
		{
			cout << "\nPerimeter is: " << pow(radius,2) * 3.1416;
		}
		circle(double radius)
		{
			this->radius = radius;
			getArea(radius);
			getPerimeter(radius);
		}
		
		
};
int main()
{
	double r;
	cout << "Enter radius: ";
	cin >> r;
	circle ob(r);
	
}
