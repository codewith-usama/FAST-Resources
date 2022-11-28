#include<iostream>
using namespace std;
class Area
{
	float area;
	public:
//	void setDim(float x, float y)
//	{
//		area = x * y;
//	}
//	float getarea()
//	{
//		return area;
//	}
	float returnArea()
	{
		return area;
	}
	Area(float x, float y)
	{
		area = x * y;
	}
};
int main()
{
	float width, height;
	cout << "Enter width of rectangle: ";
	cin >> width;
	cout << "Enter height of rectangle: ";
	cin >> height;
	Area ob1(width, height);
	cout << "Area of Rectangle is: "<< ob1.returnArea();
	return 0;
}
