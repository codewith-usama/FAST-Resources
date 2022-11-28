#include<iostream>
#include<string>
using namespace std;
class daytype
{
	string day[7] = {{"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}, {"Sunday"}};
	int num;
	string day1;
	public:
//		if(day1 == "mon" || day1 == "fri" || day1 == "sun")
//		{
//			cout << day[0];
//		}
	cout << "Hello";
		if(day1 == "tue")
		{
			cout << day[1];
		}
		public:
		daytype(string day1, int num)
		{
			this->day1 = day1;
			this->num = num;
		}
		
};
int main()
{
	string day;
	int num;
	cout << "Enter the day: ";
	cin >> day;
	cout << "Enter adding num: ";
	cin >> num;
	daytype ob(day, num);
}
