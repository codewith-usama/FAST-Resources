#include<iostream>
using namespace std;
class Date
{
	public:
		int a_month;
		int a_day;
		int a_year;
};
int main()
{
	Date ob1;
	cout << "Enter month: ";
	cin >> ob1.a_month;
	cout << "Enter day: ";
	cin >> ob1.a_day;
	cout << "Enter year: ";
	cin >> ob1.a_year;
	cout << endl << ob1.a_month << "/" << ob1.a_day << "/" << ob1.a_year;
}
