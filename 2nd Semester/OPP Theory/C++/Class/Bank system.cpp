#include<iostream>
using namespace std;
class Client
{
	public:
	string acc_no = "00115878459789";
	string acc_type = "Habib Bank";
	double acc_balance = 15000;
	
	public:
		void all()
		{
			acc_no;
			acc_type;
			acc_balance;
		}
		void AccNo()
		{
			acc_no;
		}
		void AccType()
		{
			acc_type;
		}
		void Accbalance()
		{
			acc_balance;
		}
		void withdraw(double amount)
		{
			if(acc_balance == 0 || acc_balance > amount)
			{
				cout << "Not Enough Amount";
			}
			else
				acc_balance -= amount;
		}
		void deposit(double amount)
		{
			acc_balance += amount;
		}
		double setbalance()
		{
			acc_balance;
		}
};
class New_User
{
	public:
	string Name;
	string acc_no1;
	string acc_type1;
	double acc_balance1 = 0;
	
	void deposit(double amount)
	{
		acc_balance1 += amount;
	}
	double setbalance1()
	{
		acc_balance1;
	}
	
};
void heading()
{
	cout << "Welcome To Habib Bank";
}
int main()
{
	Client ob1;
	New_User ob2;
	int choice;
	heading();
	cout << "\n1.New User\n2.Client\n";
	cin >> choice;
	char i;
	int amount;
	system("cls");
	heading();
	if(choice == 1)
	{
		cout << "\nEnter Your Full Name: ";
		fflush(stdin);
		getline(cin,ob2.Name);
		cout << "Enter Accout Number: ";
		getline(cin,ob2.acc_no1);
		while(ob2.acc_no1 == ob1.acc_no)
		{
			system("cls");
			heading();
			cout << "\nEnter Your Full Name: "<<ob2.Name;
			cout << "\nAccount Number Already Taken.\n";
			cout << "Enter Accout Number: ";
			fflush(stdin);
			getline(cin,ob2.acc_no1);
		}
		cout << "Enter Type: ";
		getline(cin,ob2.acc_type1);
		cout << "Do you want to depoit some Amount y/n?";
		cin >> i;
		if(i == 'y' || i == 'Y')
		{
			cout << "Enter Amount to Deposit: ";
			cin >> amount;
			ob2.deposit(amount);
			cout << "Account Balance is Rs."<<ob2.setbalance1();
			cout << "\nThank You Sir.";
		}
		else
		cout << "Thank You Sir.";
	}
}

