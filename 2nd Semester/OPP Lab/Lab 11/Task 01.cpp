#include<iostream>
using namespace std;
class Employee {
	string name;
	string code;
	public:
		Employee(string name, string code) {
			this->name = name;
			this->code = code;
		}
		void Display() {
			cout << "Name: " << name << endl;
			cout << "Code: " << code << endl;
		}
};
class Consultant: virtual public Employee {
	int year_of_experience;
	public:
		Consultant(int year, string name, string code): Employee(name, code){
			year_of_experience = year;
		}
		void Display() {
			cout << "Year of Experience: " << year_of_experience << endl;
		}
};
class Manager: virtual public Employee {
	int num_of_terms;
	public:
		Manager(int num, string name, string code): Employee(name, code) {
			num_of_terms = num;
		}
		void Display() {
			Employee::Display();
			cout << "Num of Terms: " << num_of_terms << endl;
			
			
		}
};
class ConsultantManager: public Consultant, public Manager {
	
	public:
		ConsultantManager(string name, string code, int num_of_terms, int year_of_experience):Manager(num_of_terms, name, code), Consultant(year_of_experience, name, code), Employee(name, code){
		}
		void Display() {
			Manager::Display();
			Consultant::Display();
		}
};
int main() {
	ConsultantManager ob1("Ali", "S-123", 17, 5);
	ob1.Display();
	return 0;
}
