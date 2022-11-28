#include<iostream>
using namespace std;
class bank
{
	double accnum;
	char acctype;
	double balance;
	double ans;
	public:
	bank()
	{
		cout<<"enter the account number "<<endl;
		cin>>accnum;
		cout<<"enter the account type "<<endl;
		cin>>acctype;
		cout<<"enter the balance "<<endl;
		cin>>balance;
		if(acctype=='s')
		{
		savings(balance);
		cout<<"account number : "<<accnum<<endl;
		cout<<"account type : "<<acctype<<endl;
		cout<<"balance : "<<balance<<endl;
		cout<<"interest : "<<ans;
	    }
		else if(acctype=='c')
		{
		checking(balance);
		cout<<"account number : "<<accnum<<endl;
		cout<<"account type : "<<acctype<<endl;
		cout<<"balance : "<<balance<<endl;
		cout<<"interest : "<<ans<<endl;
	    }
	}
	double savings(double balance)
	{
		if(balance>=1000)
		{
			ans=0.04*balance;
			return ans;
		}
	}
	double checking(double balance)
	{
		if(balance==2000)
		{
			ans=0.03*balance;
			return ans;
		}
		else if(balance>2000)
		{
			ans=0.05*balance;
			return ans;
		}
	}
};
int main()
{
	bank b1;
	cout<<endl;
	bank b2;
}
