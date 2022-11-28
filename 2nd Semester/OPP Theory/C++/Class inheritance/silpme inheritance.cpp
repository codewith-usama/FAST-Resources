#include<iostream>
using namespace std;
class employee{
	protected:
	string id;
		void set_id(string id){
		this->id = id;
	}
	double salary;
	
	employee(){
		cout << "\nIn employee null.\n";
	}

	employee(string id, double salary)
	{
		this->id = id;
		this->salary = salary;
	}
};
class pharmatic : public employee{
	protected:
	string licence;
	public:
		pharmatic(){
			cout << "\nIn pharmatic null.\n";
		}
		pharmatic(string licence, string id, double salary) : employee(id, salary)
		{
			this->licence = licence;
		}
};
class accountant : public pharmatic{
	string name;
	public:
		accountant(){
			cout << "\nIn accountant null.\n";
		}
		accountant(string name, string licence, string id, double salary) : pharmatic(licence, id, salary)
		{
			this->name = name;
		}
		void display(){
			cout << "\nName: " << name;
			cout << "\nLicence: " << licence;
			cout << "\nID: " << id;
			cout << "\nSalary: " << salary;
		}
		void set_id(string id){
			employee::set_id(id);
		}
};
int main()
{
	accountant ob1("Usama", "ABC", "20K-0190", 5000);
	ob1.set_id("20");
	ob1.display();
	
}
