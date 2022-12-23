#include<iostream>
using namespace std; 
int main()
{
	int sec,hour,min,sech,secm;
	cout << "Enter the no of hour : ";
	cin >> hour;
	cout << "Enter the no of mins :";
	cin >> min;
	secm=min*60;
	sech=hour*3600;
	sec=secm+sech;
	cout << "\nThe no sec in value is" << sec;
}
