#include<iostream>
using namespace std;
class Employee
{
	int employee_id;
	double employee_salary;
	public:
		void setID(int employee_id)
		{
			this->employee_id = employee_id;
		}
		int getID()
		{
			return employee_id;
		}
		void setSalary(double employee_salary)
		{
			this->employee_salary = employee_salary; 
		}
		double getSalary()
		{
			return employee_salary;
		}
		string employee_name;
		string employee_dob;
		string employee_desigination;
};
class Company : public Employee
{
	double Total_buget_of_company;
	public:
		void setTotalBudget(double Total_buget_of_company)
		{
			this->Total_buget_of_company = Total_buget_of_company;
		}
		double getTotalBudget()
		{
			return Total_buget_of_company;
		}
		int Total_num_of_employee;	
};
class Office : public Company
{
	double budget_of_office;
	public:
		void setOfficeBudget(double budget_of_office)
		{
			this->budget_of_office = budget_of_office;
		}
		double getOfficeBudget()
		{
			return budget_of_office;
		}
		int Total_num_of_officess;
};
int main()
{
	Office ob1;
	int id;
	double salary;
	cout << "Employee Data";
	cout << "\nEmployee ID: ";
	cin >> id;
	ob1.setID(id);
	cout << "Employee Name: ";
	fflush(stdin);
	getline(cin,ob1.employee_name);
	cout << "Employee Deigination: ";
	getline(cin,ob1.employee_desigination);
	cout << "Employee DOB (dd/mm/yy): ";
	getline(cin,ob1.employee_dob);
	cout << "Employee Salary: ";
	cin >> salary;
	ob1.setSalary(salary);
	system("cls");
	
	double budget;
	cout << "Company Data";
	cout << "\nCompany's Total Budget: ";
	cin >> budget;
	ob1.setTotalBudget(budget);
	cout << "Total num of Employees in Company: ";
	cin >> ob1.Total_num_of_employee;
	system("cls");
	
	double Obudget;
	cout << "Office Data";
	cout << "\nOffice budget: ";
	cin >> Obudget;
	ob1.setOfficeBudget(Obudget);
	cout << "Total num of Officess: ";
	cin >> ob1.Total_num_of_officess;
	system("cls");
	system("Color 0a");
	cout << "ID ----------------------------- "<< ob1.getID();
	cout << "\nName --------------------------- "<< ob1.employee_name;
	cout << "\nDesigination ------------------- "<< ob1.employee_desigination;
	cout << "\nSalary ------------------------- "<< ob1.getSalary();
	cout << "\nDate Of Birth ------------------ "<< ob1.employee_dob;
	cout << "\nCompany's total budget --------- "<< ob1.getTotalBudget();
	cout << "\nTotal Employees in company ----- "<< ob1.Total_num_of_employee;
	cout << "\nOffice Budget ------------------ "<< ob1.getOfficeBudget();
	cout << "\nTotal Employees ---------------- "<< ob1.Total_num_of_officess;
}
