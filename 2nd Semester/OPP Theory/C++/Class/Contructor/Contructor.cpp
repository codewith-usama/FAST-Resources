#include<iostream>
using namespace std;
class Bank
{
	string acc_no;
	string acc_type;
	double acc_balance;
	
	public:
		string getno()
		{
			return acc_no;
		}
		void setno(string x)
		{
			acc_no = x;	
		}
		string gettype()
		{
			return acc_type;
		}
		void settype(string y)
		{
			acc_type = y;
		}
		double getbalance()
		{
			return acc_balance;
		}
		void setbalance(double z)
		{
			acc_balance = z;
		}
		Bank()
		{
			acc_no = "aaaaaaaaaaaaaaaaaaaa";
			acc_type = "abc-xyz";
			acc_balance = 0;
		}
		Bank(string x, string y, double z)
		{
			acc_no = x;
			acc_type = y;
			acc_balance = z;
		}
		
};
int main()
{
	Bank ob1;
	Bank ob2("14151asa", "Usama", 151121);
	cout << ob2.getno() << endl;
	cout << ob2.gettype() << endl;
	cout << ob2.getbalance() << endl;
}
