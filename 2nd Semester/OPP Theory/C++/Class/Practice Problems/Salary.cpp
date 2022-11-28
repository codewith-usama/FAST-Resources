#include<iostream>
using namespace std;
class Salary
{
	double sal;
	int num;
	public:
	double getInfo(double salary, int num_of_hours)
	{
		if(salary < 500)
		Addsal(salary);
		else if(num_of_hours > 6)
		Addwork(salary);
	}
	double Addsal(double a)
	{
		a += 10;
		return a;
	}
	double Addwork(double b)
	{
		b += 5;
		return b;
	}
//	Salary(double x, int y)
//	{
//		sal = x;
//		num = y;
//	}
};
int main()
{
	double salary;
	int hours;
	cout << "Enter salry of employee: ";
	cin >> salary;
	cout << "Enter num of hours: ";
	cin >> hours;
	Salary ob1;
	ob1.Addwork(salary);
	
}
