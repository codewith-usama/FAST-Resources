#include<iostream>
using namespace std;
int main()
{
	string Movie_Name;
	cout<<"Enter Movie Name: ";
	getline(cin,Movie_Name);
	
	int adult_ticket_price, child_ticket_price;
	
	cout<<"Enter adult ticket price: ";
	cin>>adult_ticket_price;
	
	cout<<"Enter child ticket price: ";
	cin>>child_ticket_price;
	
	
	int child_ticket_slod, adult_ticket_slod;
	cout<<"Enter child ticket slod: ";
	cin>>child_ticket_slod;
	
	cout<<"Enter adult ticket slod: ";
	cin>>adult_ticket_slod;
	
	system("cls");
	
	cout<<endl<<"Movie Name is *******  "<<Movie_Name;
	
	int Number_of_Tickets_Sold;
	
	Number_of_Tickets_Sold = adult_ticket_slod + child_ticket_slod;
	
	cout<<endl<<"Number of ticket sold are ************  "<<Number_of_Tickets_Sold;
	
	int Gross_Amount;
	
	Gross_Amount = child_ticket_slod * child_ticket_price + adult_ticket_slod * adult_ticket_price;
	
	cout<<endl<<"Gross Amount is ***************  $ "<<Gross_Amount;
	
	int Percentage_of_Gross_Amount_Donated;
	
	cout<<endl<<"Enter Percentage of Gross Amount Donated: ";
	cin>>Percentage_of_Gross_Amount_Donated;
	
	int Amount_Donated;
	
	Amount_Donated = (Gross_Amount / Percentage_of_Gross_Amount_Donated) * 100;
	
	cout<<endl<<"Amount Donated is ***********  "<<Amount_Donated;
	
	int Net_Sale;
	
	Net_Sale = Gross_Amount - Amount_Donated;
	
	cout<<endl<<"Net sale is ************* $ "<<Net_Sale;
}
