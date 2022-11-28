#include<iostream>
using namespace std;
float Regular_service()
{
	int number_of_min;
	int store, store1;
	float store2, store3;
	cout << "Enter Number of min: ";
	cin >> number_of_min;
	if(number_of_min <= 50)
	{
		store = 10;
		cout <<"Number of min used are: "<<number_of_min;
		return store;
	}
	else
		store1 = number_of_min - 50;
		store2 = store1 * 0.20;
		store3 = store2 + 10;
		cout <<"Number of min used are: "<<number_of_min;
		return store3;
		
		
}
float Premium_service()
{
	int number_of_min_day, number_of_min_night;
	 
	int store, store1, var, var2, zar;
	
	float store2, var1, var3, var4, zar1;
	
	cout << "Enter Number of min used in day: ";
	cin >> number_of_min_day;
	cout << "Enter Number of min used in night: ";
	cin >> number_of_min_night;
	
	if(number_of_min_day <= 75)
	{
		if(number_of_min_night <= 100)
		{
			store = 25;
			cout <<"\nNumber of min used during day: "<<number_of_min_day;
			cout <<"\nNumber of min used during night: "<<number_of_min_night;
			cout <<"\nTotal Number of min used are: "<<number_of_min_day + number_of_min_night;
			return store;
		}
		else
		{
			store1 = number_of_min_night - 100;
			store2 = (store1 * 0.05) + 25;
			cout <<"\nNumber of min used during day: "<<number_of_min_day;
			cout <<"\nNumber of min used during night: "<<number_of_min_night;
			cout <<"\nTotal Number of min used are: "<<number_of_min_day + number_of_min_night;
			return store2;
		}
	}
	else
	{
		if(number_of_min_night > 100)
		{
			var = number_of_min_night - 100;
			var1 = var * 0.05;
			
			var2 = number_of_min_day - 75;
			var3 = var2 * 0.10;
			
			var4 = var1 + var3 + 25;
			cout <<"\nNumber of min used during day: "<<number_of_min_day;
			cout <<"\nNumber of min used during night: "<<number_of_min_night;
			cout <<"\nTotal Number of min used are: "<<number_of_min_day + number_of_min_night;
			return var4;
		}
		else
		{
			zar = number_of_min_day - 75;
			zar1 = (zar * 0.10) + 25;
			cout <<"\nNumber of min used during day: "<<number_of_min_day;
			cout <<"\nNumber of min used during night: "<<number_of_min_night;
			cout <<"\nTotal Number of min used are: "<<number_of_min_day + number_of_min_night;
			return zar1; 
		}
	}
}
int main()
{
	string acc_no;
	char service_code;
	cout << "Enter Account Num: ";
	getline(cin,acc_no);
	float i, j;
	cout << "Enter Service code\n1.Regular service R/r\n2.Premium service P/p\n";
	cin >> service_code;
	if(service_code == 'r' || service_code == 'R')
	{
		i = Regular_service();
		cout << "\nAccount number is: "<<acc_no;
		cout << "\nService is Regular.";
		cout << "\nDue Amount is: $"<< i;
	}
	else if(service_code == 'p' || service_code == 'P')
	{
		j = Premium_service();
		cout << "\nAccount number is: "<<acc_no;
		cout << "\nService is Premium.";
		cout << "\nDue Amount is: $"<< j;
	}
	else
	cout << "Error.";
}
