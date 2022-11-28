#include<iostream>
using namespace std;
float tax()
{
	int income;
	float amount;
	int time, rate;
	cout << "Enter Income: ";
	cin >> income;
	cout << "Enter consulting time (min): ";
	cin >> time;
	cout << "Enter hourly rate: ";
	cin >> rate;
	
	if(income <= 25000)
	{
		if(time > 30)
		{
			amount = rate * 0.40;
			return amount;
		}
		else
		{
			cout << "Person has low income.";
			exit(1);	
		}
	}
	else
	{
		if(time <= 20)
		{
			cout << "Person has low income.";
			exit(1);
		}
		else
		{
			amount = rate * 0.70;
			return amount;
		}
	}
	}
int main()
{
	float i = tax();
	cout << "\nThe billing Amount is: " << i;
}
