#include<iostream>
using namespace std;
class Bank
{
	string acc_no;
	string acc_title;
	int acc_type;
	double acc_balance = 1000;
	
	public:
//		void setAccNo(string s)
//		{
//			acc_no = s;
//		}
//		string getAccNo()
//		{
//			return acc_no;
//		}
		void deposit(double amount)
		{
			acc_balance += amount;
		}
		void withdraw(double amount)
		{
			if(acc_balance == 0 || acc_balance < amount)
			{
				cout << "You dont have enough Amount";
			}
			else 
			acc_balance -= amount;
		}
		double setbalance()
		{
			acc_balance;
		}
};
int main()
{
	Bank ob1;
	int choice;
	double amount;
	cout << "1.Depoit\n2.Withdraw\n";
	cin >> choice;
	if(choice == 1)
	{
		cout << "Enter Amount you want to deposit: ";
		cin >> amount;
		ob1.deposit(amount);
		cout << ob1.setbalance();
	}
	else if(choice == 2)
	{
		cout << "Enter Amount You want to withdram: ";
		cin >> amount;
		ob1.withdraw(amount);
//		cout << ob1.setbalance();
	}
	else 
	cout << "Incorrect code.";
	
	
}
