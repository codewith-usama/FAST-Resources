#include<iostream>
using namespace std;
class person{
	int age;
	protected:
		string name;
		public:
			void set_age(int age){
				this->age = age;
			}
			int get_age(){
				return age;
			}
};
class employee{
	int id;
	protected:
		float salary;
		public:
			void set_id(int id){
				this->id = id;
			}
			int get_id(){
				return id;
			}
};
class manager : public person, public employee{
	string type;
	public:
	void set_type(string type){
		this->type = type;
	}
	string get_type(){
		cout << "\nAge is: " << get_age();
		cout << "\nID is: " << get_id();
		return type;
	}
	
};
class it_manager : public manager{
	int num_of_person;
	public:
		void display(){
			cout << "Name: " << name;
			cout << "\nType: " << get_type();
			cout << "\nSalary is: " << salary;
			cout << "\nNum of person: " << num_of_person;
			
		}
		it_manager(int age, string name, int id, float salary, string type, int num_of_person){
			this->name = name;
			this->salary = salary;
			this->num_of_person = num_of_person;
			set_type(type);
			set_id(id);
			set_age(age);
			
		}
};
int main()
{
	it_manager ob1(18, "Mohammad Usama", 190, 50000, "Manager", 50);
	ob1.display();
	return 0;
}
