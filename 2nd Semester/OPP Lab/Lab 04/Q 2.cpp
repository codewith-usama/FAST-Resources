#include<iostream>
/*In starting Account Balance is 0. You have to deposit some amount to withdraw.*/
using namespace std;
class Account
{
	double acc_balance;
	public:
		void setDeposit(double acc_balance)
		{
			this->acc_balance +=  acc_balance;
			setDisplay(this->acc_balance);
		}
		void setWithdraw(double acc_balance)
		{
			if(this->acc_balance == acc_balance || this->acc_balance > acc_balance)
			{
				this->acc_balance -= acc_balance;
				setDisplay(this->acc_balance);
			}
			else
			cout << "Not enough balance to withdraw.";
			
		}
		void setDisplay(double acc_balance)
		{
			cout <<"Current Balance is: "<<acc_balance;
		}
};
int main()
{
	Account ob1;
	int num;
	
	char ch = 'y';
	double amount, amount1;
	while(ch == 'y' || ch == 'Y')
	{
		cout << "1.Deposit\n2.Withdraw\n";
		cin >> num;
		if(num == 1)
		{
			cout << "Enter Amount to deposit: ";
			cin >> amount;
			ob1.setDeposit(amount);
			cout << "\nMore transcition?? y/n ";
			cin >> ch;
			if(ch == 'n' || ch == 'N')
				ch = 'n';
		}
		else if(num == 2)
		{
			cout << "Enter Amount to withdraw: ";
			cin >> amount1;
			ob1.setWithdraw(amount1);
			cout << "\nMore transcition?? y/n ";
			cin >> ch;
			if(ch == 'n' || ch == 'N')
				ch = 'n';
		}
		system("cls");
	}
	
}
