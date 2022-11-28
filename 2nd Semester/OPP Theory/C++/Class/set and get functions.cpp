#include<iostream>
using namespace std;
class Bank
{
	string acc_no;
	string acc_title;
	double acc_balance;
	
	public:
		string getAccNo()
		{
			return acc_no;
		}
		string getTitle()
		{
			return acc_title;
		}
		double getBalance()
		{
			return acc_balance;
		}
		
		void setAccNo(string no)
		{
			acc_no = no;
		}
		void setTitle(string ti)
		{
			acc_title = ti;
		}
		void setBalance(double amount)
		{
			acc_balance = amount;
		}
		void deposit(double amount)
		{
			acc_balance += amount;
		}
		void withdraw(double amount)
		{
			if(acc_balance == 0 || acc_balance < amount)
			{
				cout << "\nError";
			}
			else
			acc_balance -= amount;
		}
};
int main()
{
	Bank ob;
	ob.setAccNo("100-21578");
	cout << ob.getAccNo();
	ob.setTitle("Usama");
	cout << endl << ob.getTitle();
	ob.setBalance(1500);
	cout << endl << ob.getBalance();
	ob.withdraw(120);
	cout << endl << ob.getBalance();
}
