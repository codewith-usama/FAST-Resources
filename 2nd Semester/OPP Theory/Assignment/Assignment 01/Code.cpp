#include<iostream>
using namespace std;
class product // Product class to store the major data of product.
{
	public:
		string name_of_product;
		double product_market_price;
		int purchaser_of_product;
		double annual_sale_of_product;
	private:	
		int product_code;
	public:
		void setCode(int product_code)
		{
			this->product_code = product_code;
		}	
		int getCode()
		{
			return product_code;
		}
};
class office : public product // Office class to store the data of office and secondly inherited the class product with class office details.
{
	public:
	string name_of_office;
	string location;
	string manager_name; // Manager of office.
	int num_of_employee; // number of Employees in each office.
};
class monthly_bills : public office // Monthly Bills class to store the monthly expenditure of the company anf inherited upper both classes.
{
	double electricity_bill, water_bill;
	double monthly_expenditure, transport_bill;
	public:
		void setElectricity(double electricity_bill)
		{
			this->electricity_bill = electricity_bill;
		}
		double getElectricity()
		{
			return electricity_bill;
		}
		void setWater(double water_bill)
		{
			this->water_bill = water_bill;
		}
		double getWater()
		{
			return water_bill;
		}
		void setMonthly_Expediture(double monthly_expenditure)
		{
			this->monthly_expenditure = monthly_expenditure;
		}
		double getMonthly_Expenditure()
		{
			return monthly_expenditure;
		}
};
class Salary : public monthly_bills // Salary to store the salary.
{
	double manager_salary;
	double employees_salary;
	double guards_salary;
	public:
		void setManageSalary(double manager_salary)
		{
			this->manager_salary = manager_salary;
		}
		double getManagerSalary()
		{
			return manager_salary;
		}
		void setEmployeeSalary(double employees_salary)
		{
			this->employees_salary = employees_salary;
		}
		double getEmployeeSalary()
		{
			return employees_salary;
		}
		void setGuard_Salary(double guards_salary)
		{
			this->guards_salary = guards_salary;
		}
		double getGuard_Salary()
		{
			return guards_salary;
		}
};
int main()
{
	int num;
	cout << "Enter Number of Offices Company have: ";
	cin >> num;
	Salary ob1[num];
	int code;
	double electricity_bill, water_bill;
	double monthly_expenditure, transport_bill;
	for(int i = 0; i < num; i++)
	{
		cout << "Office"<< i + 1 << "Data.";
		cout << "Enter Office Name: ";
		getline(cin,ob1[i].name_of_office);
		cout << "Enter Office Code: ";
		code;
		ob1[i].setCode(code);
		cout << "Office Manager: ";
		getline(cin,ob1[i].manager_name);
		cout << "Complete Location of Office: ";
		getline(cin,ob1[i].location);
		cout << "Employess in Office: ";
		cin >> ob1[i].num_of_employee;
		
		cout << "Enter Electricity bill: ";
		cin >> electricity_bill; 
		ob1[i].setElectricity(electricity_bill);
		cout << "Enter Water bill: ";
		cin >> water_bill;
		ob1[i].setWater(water_bill);
		cout << "Enter Monthly Expediture: ";
		cin >> monthly_expenditure;
		ob1[i].setMonthly_Expediture(monthly_expenditure);
	}
}
