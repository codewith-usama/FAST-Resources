#include<iostream>
using namespace std;
class vehicles {
	public:
	int price;
	vehicles(){
	}
	
};
class car : public vehicles{
	public:
	int capacity;
	int num_of_doors;
	string fuel_type;
		car()
		{
			cout << "Enter price of car: ";
			cin >> price;
			cout << "Enter seating capacity: ";
			cin >> capacity;
			cout << "Enter num of doors: ";
			cin >> num_of_doors;
			cout << "Enter fuel type: ";
			fflush(stdin);
			getline(cin, fuel_type);
		}
};
class motor_cycle : public vehicles{
	public:
	int num_of_cylinder;
	int num_of_gears;
	int num_of_wheels;
		motor_cycle()
		{
			cout << "Enter price of motor cycle: ";
			cin >> price;
			cout << "Enter num of cylinder: ";
			cin >> num_of_cylinder;
			cout << "Enter num of gear: ";
			cin >> num_of_gears;
			cout << "Enter num of wheels: ";
			cin >> num_of_wheels;
		}
};
class audi : public car{
	string model;
	public:
	void display_car(){
		system("cls");
		cout << "Car " << model << " has " << num_of_doors << " num of doors " << " seating capacity of " << capacity << " fuel type " << fuel_type << " of price " << price;
	}
	audi()
	{
		cout << "Enter model of car: ";
		getline(cin, model);
		system("cls");
	}
};
class yahama : public motor_cycle
{
	int make_type;
	public:
		yahama()
		{
			cout << "Enter make type of motor cycle: ";
			cin >> make_type;
		}
		void display_bike()
		{
			cout << "\nBike has " << num_of_cylinder << " num of cylinder " << num_of_gears << " num of gears and " << num_of_wheels << " num of wheels make in " << make_type << " of price " << price; 
		}
};
int main()
{
	audi ob1;
	yahama ob2;
	ob1.display_car();
	ob2.display_bike();
}
