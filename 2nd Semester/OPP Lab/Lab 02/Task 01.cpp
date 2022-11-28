#include<iostream>
using namespace std;
float Residential()
{
	float Bill_processing_fee = 4.50;
	float Basic_service_fee = 20.50;
	float Premium_channels = 7.50; //per channel
	int choice; 
	float choice1;
	cout << "Number of Premium channels: ";
	cin >> choice;
	choice1 = choice * 7.50;
	return choice1;
}
int Busniess()
{
	float Bill_processing_fee = 15.00; //for first 10 connections, $5.00 for each additional connection
	float service_fee  = 75.00;
	float Premium_channels = 50.00; // per channel for any number of connections
	int choice1, choice2;
	float choice3;
	cout << "Number of connections: ";
	cin >> choice1;
	if(choice1 > 10)
	{
		choice2 = choice1 - 10;
		choice3 = (choice2 * 5) + 75;
	}
	int channel;
	float channel1;
	cout << "Number of Premium channels: ";
	cin >> channel;
	channel1 = channel * 50;
	int total;
	total = channel1 + choice3;
	return total;
}
int main()
{
	int acc_no;
	char code;
	cout << "Enter Acount Number: ";
	cin >> acc_no;
	cout << "Customer Code\nResidential customer R/r \nBusiness customer B/b\nYour Choice:";
	cin >> code;
	
	if(code == 'r' || code == 'R')
	{
		cout << "\nThe Amount of selected channels is: $"<<Residential();
		cout << "\nThe Account Number is: "<<acc_no;

	}
	else if(code == 'b' || code == 'B')
	{
		cout << "\nThe Total Amount is: $"<<Busniess();
		cout << "\nThe Account Number is: "<<acc_no;
	}
	else
		cout << "Wrong code.";
		
}

