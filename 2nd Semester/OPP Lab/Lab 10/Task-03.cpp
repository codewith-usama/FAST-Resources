#include<iostream>
#include<string>
using namespace std;
class person {
	string name;
	string id;
	double salary;
	double bonus;
	public:
		void get_data(string name, string id, double salary) {
			this->name = name;
			this->id = id;
			this->salary = salary;
		}
		void display_data() {
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
			cout << "Salary: " << salary << endl;
			cout << "Bonus: " << bonus << endl;
		}
		void cal_bonus() {
			bonus = ((salary * 12 ) / 5);
		}
};
class admin: public person {
	string name;
	string id;
	double salary;
	double bonus;
	public:
		void get_data(string name, string id, double salary) {
			this->name = name;
			this->id = id;
			this->salary = salary;
		}
		void display_data() {
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
			cout << "Salary: " << salary << endl;
			cout << "Bonus: " << bonus << endl;
		}
		void cal_bonus() {
			bonus = ((salary * 12 ) / 5);
		}
};
class account: public person {
	string name;
	string id;
	double salary;
	double bonus;
	public:
		void get_data(string name, string id, double salary) {
			this->name = name;
			this->id = id;
			this->salary = salary;
		}
		void display_data() {
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
			cout << "Salary: " << salary << endl;
			cout << "Bonus: " << bonus << endl;
		}
		void cal_bonus() {
			bonus = ((salary * 12 ) / 5);
		}
};
int main() {
	person *ob1, obj;
	admin ob2;
	account ob3;
	ob1 = &obj;
	ob1->get_data("Mohammad Taha", "1565", 6500);
	ob1->cal_bonus();
	ob1->display_data();
	ob1 = &ob2;
	ob1->get_data("Mohammad Usama", "Emp 1545", 8000);
	ob1->cal_bonus();
	ob1->display_data();
	ob1 = &ob3;
	ob1->get_data("Mohammad Ahmed", "Emp 1554", 10000);
	ob1->cal_bonus();
	ob1->display_data();
}
