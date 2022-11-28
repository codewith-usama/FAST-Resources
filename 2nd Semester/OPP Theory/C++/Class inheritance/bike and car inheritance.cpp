#include<iostream>
using namespace std;
class vehicle{
	public:
	float mileage;
	double price;
	public:
		vehicle(float mileage, double price){
			this->mileage = mileage;
			this->price = price;
		}
	void show_vehicle(){
		cout << "Mileage: " << mileage;
		cout << "\nPrice: " << price << endl; 
	}
};
class car : public vehicle{
	protected:
	double owner_ship_cost;
	int warranty;
	int seating_capacity;
	string fuel_type;
	public:
		car(double owner_ship_cost, int warranty, int seating_capacity, string fuel_type, float mileage, double price) : vehicle(mileage, price){
			this->owner_ship_cost = owner_ship_cost;
			this->warranty = warranty;
			this->seating_capacity = seating_capacity;
			this->fuel_type = fuel_type;
		}
		void display_car(){
			show_vehicle();
			cout << "Final cost: " << owner_ship_cost;
			cout << "\nWarrenty: " << warranty;
			cout << "\nSeating Capacity: " << seating_capacity;
			cout << "\nFueal type: " << fuel_type << endl;
		}
};
class bike : public vehicle{
	protected:
	int num_of_cylinder;
	int num_of_gears;
	string cooling_type;
	string wheel_type;
	int fuel_tank_size;
	public:
		bike(int num_of_cylinder, int num_of_gears, string cooling_type, string wheel_type, int fuel_tank_size ,float mileage, double price) : vehicle(mileage, price){
			this->num_of_cylinder = num_of_cylinder;
			this->num_of_gears = num_of_gears;
			this->cooling_type = cooling_type;
			this->wheel_type = wheel_type;
			this->fuel_tank_size = fuel_tank_size;
		}
		void display_bike(){
			show_vehicle();
			cout << "Num of cylinder: " << num_of_cylinder;
			cout << "\nNum of gears: " << num_of_gears;
			cout << "\nCooling type: " << cooling_type;
			cout << "\nWheel type: " << wheel_type;
			cout << "\nSize of fuel tank: " << fuel_tank_size << endl;
		}
};
class audi : public car{
	string model_type;
	public:
		audi(string model_type, double owner_ship_price, int warranty, int seating_capacity, string fuel_type, float mileage, double price) : car(owner_ship_price, warranty, seating_capacity, fuel_type, mileage, price){
			this->model_type = model_type;
		}
		void display_audi(){
			display_car();
			cout << "Model type: " << model_type << endl << endl;
		}
		
};
class ford : public car{
	string model_type;
	public:
		ford(string model_type, double owner_ship_price, int warranty, int seating_capacity, string fuel_type, float mileage, double price) : car(owner_ship_price, warranty, seating_capacity, fuel_type, mileage, price){
			this->model_type = model_type;
		}
		void display_ford(){
			display_car();
			cout << "Model type: " << model_type;
		}
};
class bajaj : public bike{
	int make_type;
	public:
		bajaj(int make_type, int num_of_cylinder, int num_of_gears, string cooling_type, string wheel_type, int fuel_tank_size, float mileage, double price) : bike(num_of_cylinder,num_of_gears, cooling_type, wheel_type, fuel_tank_size, mileage, price){
			this->make_type = make_type;
		}
		void display_bajaj(){
			display_bike();
			cout << "Make type: " << make_type << endl << endl;
		}
};
class tvs : public bike{
	int make_type;
	public:
		tvs(int make_type, int num_of_cylinder, int num_of_gears, string cooling_type, string wheel_type, int fuel_tank_size, float mileage, double price) : bike(num_of_cylinder,num_of_gears, cooling_type, wheel_type, fuel_tank_size, mileage, price){
			this->make_type = make_type;
		}
		void display_tvs(){
			display_bike();
			cout << "Make type: " << make_type << endl << endl;
		}
};
int main()
{
	bajaj ob1(2000, 5, 5, "Air", "Steel", 5, 15.2f, 5000);
	ob1.display_bajaj();
	audi ob2("A8", 5000, 10, 4, "Petrol", 6.4, 45000);
	ob2.display_audi();
	tvs ob3(2000, 5, 5, "Air", "Steel", 5, 15.2f, 5000);
	ob3.display_tvs();
	ford ob4("Ford F8", 5000, 10, 4, "Petrol", 6.4, 45000);
	ob4.display_ford();
}
