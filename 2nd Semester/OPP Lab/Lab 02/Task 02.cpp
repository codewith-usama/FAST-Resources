#include<iostream>
using namespace std;
int showChoices()
{
	int choice;

	cout << "\n1.Feet To Meter\n2.Inch To Cent";
	cout << "\n3.Cent To Inch\n4.Meter To Feet\n";
	cin >> choice;
	return choice;

}
int feetAndInchesToMetersAndCent(int k)
{
	int a = 1;
	
	char j = 'y';
	while(j == 'y')
	{
		if(k == 1)
		{	
			float var1, out;
			cout << "\nFeet: ";
			cin >> var1;
			out = var1 * 0.3048;
			cout << "In meter is: "<< out;
			cout << "\nDo you want more convertion y/n: ";
			cin >> j;
			system("cls");
		
		if(j == 'y')
			return a;
			
		else
		break;
		
		}
		else if(k == 2)
		{
			float var2, out1;
			cout << "\nInch: ";
			cin >> var2;
			out1 = var2 * 2.54;
			cout << "In Centi is: "<< out1;	
			cout << "\nDo you want more convertion y/n: ";
			cin >> j;
			system("cls");		
		if(j == 'y')
			return a;
			
		else
		break;
		}
	}
	
	
	
}
int metersAndCentTofeetAndInches(int b)
{
	int a = 1;
	
	char j = 'y';
	while(j == 'y')
	{
		if(b == 3)
		{	
			float var2, out1;
			cout << "\nCenti: ";
			cin >> var2;
			out1 = var2 * 0.393701;
			cout << "In Inch is: "<< out1;

			cout << "\nDo you want more convertion y/n: ";
			cin >> j;
			system("cls");
		if(j == 'y')
			return a;
		
		else
		break;
		}
		else if(b == 4)
		{
			float var, out;
			cout << "\nMeter: ";
			cin >> var;
			out = var * 3.28084;
			cout << "In Feet is: "<< out;		
			
			cout << "\nDo you want more convertion y/n: ";
			cin >> j;
			system("cls");
		if(j == 'y')
			return a;
			
		else
		break;
		}
	}
	
}
int main()
{
	int i;
	int j = 1;

	while(j == 1)
	{
		i = showChoices();
		if(i == 1 || i == 2)
		{
			j = feetAndInchesToMetersAndCent(i);
			if(j == 1)
			continue;
			else
			break;	
		}
		else if(i == 3 || i == 4)
		{
			j = metersAndCentTofeetAndInches(i);
			if(j == 1)
			continue;
			else
			break;
		}
		else
		cout << "\nWrong code.";
		exit(1);
		
	}	
}
