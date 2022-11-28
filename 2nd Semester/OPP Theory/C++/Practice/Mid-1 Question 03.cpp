#include<iostream>
using namespace std;
class customer
{
	double acc_balance;
	string acc_no;
	double annual_income;
	public:
		string cus_name;
		double get_balance()
		{
			return acc_balance;
		}
		string get_acc_no()
		{
			return acc_no;
		}
		double get_income()
		{
			return annual_income;
		}
		customer()
		{
		}
	customer(string cus_name, string acc_no, double acc_balance, double annual_income)
	{
		this->cus_name = cus_name;
		this->acc_no = acc_no;	
		this->acc_balance = acc_balance;
		this->annual_income = annual_income;
	}
	
};
class bank
{
	double amount;
		 
	public:
		string branch_code;
		string branch_name; 
		string branch_manager;
		int num_of_braches;
		float rate_of_intrest;
		//customer ob3 = ob1;
		float calculate_loan()
		{
			cout << "Name: " << ob3.cus_name << endl
			<< "Account Balance: " << ob3.get_balance(); 
			cout << "Account number: " << ob3.get_acc_no();
			cout << "\nAnnual income: " << ob3.get_income();
			cout<< "\nEnter requested loan amount: ";
		 	cin>> amount;
		 	if(ob3.get_income() < amount)
		 	{
		 		cout << "Loan issued!\n";
		 		return amount * rate_of_intrest;
			}
			else
			cout << "Sorry you are exceedig the policy.";
			return 0;
		}
		bank(string branch_name, string branch_code, string branch_manager, int num_of_branches, float rate_of_intrest)
		{
			this->branch_name = branch_name;
			this->branch_code = branch_code;
			this->branch_manager = branch_manager;
			this->num_of_braches = num_of_braches;
			this->rate_of_intrest = rate_of_intrest;
		}
};
int main()
{
	double balance, income;
	string name, num;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter Account Num: ";
	cin >> num;
	cout << "Enter current balance: ";
	cin >> balance;
	cout << "Enter annual income of customer: ";
	cin >> income;
	customer ob1(name, num, balance, income);
	system("cls");
	float intrest;
	string manager_name, branch_name, code;
	int num_of_branches;
	cout << "Enter Branch name: ";
	fflush(stdin);
	getline(cin, branch_name);
	cout << "Enter Branch code: ";
	cin >> code;
	cout << "Enter manager name: ";
	fflush(stdin);
	getline(cin, manager_name);
	cout << "Enter num of branches: ";
	cin >> num_of_branches;
	cout << "Enter rate of intrest for loan: ";
	cin >> intrest;
	bank ob2(branch_name, code, manager_name, num_of_branches, intrest);
	system("cls");
	float loan = ob2.calculate_loan();
	cout << "Your payback amount is: " << loan;
}
