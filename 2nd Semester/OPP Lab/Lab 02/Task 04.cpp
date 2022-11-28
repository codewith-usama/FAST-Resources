#include<iostream>
#include<cmath>
using namespace std;
float radius(float a, float b, float c, float d);
float distance(float i, float j, float k, float l);
float circumference(float a);
float area(float a);
int main()
{
	float x1, x2, y1, y2;
	cout << "Enter X1: ";
	cin >> x1;
	cout << "Enter Y1: ";
	cin >> y1;
	cout << "Enter X2: ";
	cin >> x2;
	cout << "Enter Y2: ";
	cin >> y2;	
	radius(x1, y1, x2, y2);
}
float distance(float i, float j, float k, float l)
{
	float a;
	return sqrt(a = pow((k - i), 2) + pow((l - j), 2));
}
float radius(float a, float b, float c, float d)
{
	float r = distance(a, b, c, d);
	cout << "The Radius is: "<< r;
	cout << "\nThe Diameter is: "<< r * 2;
	circumference(r);
}
float circumference(float a)
{
	float i = (2 * 3.1416) * a;
	cout << "\nThe Circumference is: "<< i;
	area(a);
}
float area(float i)
{
	float a = pow(i, 2) * 3.1416;
	cout << "\nThe Area is: "<< a;
}
