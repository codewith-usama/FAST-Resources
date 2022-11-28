#include<iostream>
using namespace std;
class product // Product class to store the major data of product
{
	string product_code;
    string name_of_product;
	double product_market_price;
	int num_of_customer;
	double annual_sale_of_product;
		
	void setCode(string product_code) // to set the code of the product
	{
		this->product_code = product_code;
	}	
	string getCode() // to get/read the code of product
	{
		return product_code;
	}
	void setName(string name_of_product) // to set the name of product
	{
		this->name_of_product = name_of_product;
	}
	string getName() // to get/read the name of product
	{
		return name_of_product;
	}
	void setPrice(double product_market_price) // to set the price of product 
	{
		this->product_market_price = product_market_price;
	}
	double getPrice() // to get/read the price of product
	{
		return product_market_price;
	}
	void setCutomer(int num_of_customer) // te set the number of customer/buyer of product
	{
		this->num_of_customer = num_of_customer;
	}
	int setCustomer() // to get/read the number of customer
	{
		return num_of_customer;
	}
	void setAnnualSale(double annual_sale_of_product) // to set the annual sale of the product
	{
		this->annual_sale_of_product = annual_sale_of_product;
	}
	double getAnnualSale() // to get/read the annual sale of the product
	{
		return annual_sale_of_product;
	}
	product(string product_code, string name_of_product, double product_market_price, int num_of_customer, double annual_sale_of_product)
	{
		//single constructor for class Product to assign the data on the time of object creating.
		this->product_code = product_code;
		this->name_of_product = name_of_product;
		this->product_market_price = product_market_price;
		this->num_of_customer = num_of_customer;
		this->annual_sale_of_product = annual_sale_of_product;
	}
};
class office // Office class to store the data of office.
{
	string name_of_office;
	string location; // to store the complete location of different offices
	string office_code; // to store the unique code for each office
	string manager_name; // Manager of office
	int num_of_employee; // number of Employees in each office
	
	void setName(string name_of_office) // to set the name of different officess
	{
		this->name_of_office = name_of_office;
	}
	string getName() // t get/read the name of officess
	{
		return name_of_office;
	}
	void setLocation(string location) // to set the exact location of the office
	{
		this->location = location;
	}
	string getLocation() // to get/read the location of the office
	{ 
		return location;
	}
	void setCode(string office_code) // to set the unique code of each office
	{
		this->office_code = office_code;
	}
	string getCode() // to read the code of office
	{
		return office_code;
	}
	void setManager(string manager_name) // to set the name of manager of different officess
	{
		this->manager_name = manager_name;
	}
	string getManager() // to read the name of the manager
	{
		return manager_name;
	}
	void setNum(int num_of_employee) // to set the number of employees work in each officess
	{
		this->num_of_employee = num_of_employee;
	}
	int getNum() // to get/read the number of employees work in the officess
	{
		return num_of_employee;
	}
	office(string name_of_office, string location, string office_code, string manager_name, int num_of_employee)
	{
		// Cunstructor for Class Office to store the data on the time of making object for class.
		this->name_of_office = name_of_office;
		this->location = location;
		this->office_code = office_code;
		this->manager_name = manager_name;
		this->num_of_employee = num_of_employee;
	}
};
class monthly_bills // Monthly Bills class to store the monthly expenditure of the company.
{
	double electricity_bill;
	double water_bill;
	double gas_bill;
	double monthly_expenditure;
	double transport_bill;
	public:
		void setElectricity(double electricity_bill) // to set the monthly electricity bill of office
		{
			this->electricity_bill = electricity_bill;
		}
		double getElectricity() // to set/read the amount of electricity bill
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
		void setGas(double gas_bill)
		{
			this->gas_bill = gas_bill;
		}
		double getGas()
		{
			return gas_bill;
		}
		void setMonthly_Expediture(double monthly_expenditure)
		{
			this->monthly_expenditure = monthly_expenditure;
		}
		double getMonthly_Expenditure()
		{
			return monthly_expenditure;
		}
		void setTransport(double transport_bill)
		{
			this->transport_bill = transport_bill;
		}
		double getTransport()
		{
			return transport_bill;
		}
	monthly_bills(double electricity_bill, double water_bill, double gas_bill, double monthly_expenditure, double transport_bill)	
	{
		// Cunstructor to take the amount of bill of Class Monthly Class.
		this->electricity_bill = electricity_bill;
		this->water_bill = water_bill;
		this->gas_bill = gas_bill;
		this->monthly_expenditure = monthly_expenditure;
		this->transport_bill = transport_bill;
	}
};
class Salary // Salary to store the salary of members.
{
	double manager_salary;
	double employees_salary;
	double guards_salary;
	public:
		void setManageSalary(double manager_salary) // to set the salary of Manager
		{
			this->manager_salary = manager_salary;
		}
		double getManagerSalary() // to fet/read the salary of manager
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
	Salary(double manager_salary, double employees_salary, double guards_salary)
	{
		// Contructor for Class Salary to store the values of class Salary.
		this->manager_salary = manager_salary;
		this->employees_salary = employees_salary;
		this->guards_salary = guards_salary;
	}
};
