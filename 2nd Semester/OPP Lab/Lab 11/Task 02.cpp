#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class vehicle{
	string type_of_car;
	int make_year;
	string model;
	string color;
	int year;
	float miles_driven;
	public:
		vehicle(string type, int make_year, string model, string color, int year, float driven){
			type_of_car = type;
			this->make_year = make_year;
			this->model = model;
			this->color = color;
			this->year = year;
			miles_driven = driven;
		}
		void show_vehicle(){
			cout << "\nType of car: " << type_of_car;
			cout << "\nMake: " << make_year;
			cout << "\nModel: " << model;
			cout << "\nColor: " << color;
			cout << "\nYear: " << year;
			cout << "\nMiles Driven: " << miles_driven << endl;
		}
};
class electric_vehicle : virtual public vehicle{
	float energy_storage;
	public:
		electric_vehicle(float storage, string type, int make, string model, string color, int year, float miles) : vehicle(type, make, model, color, year, miles){
			energy_storage = storage;
		}
		void show_electric_vehicle(){
			show_vehicle();
			cout << "Energy Storage: " << energy_storage << endl;
		}
};
class gas_vehicle : virtual public vehicle{
	int fuel_tank_size;
	public:
		gas_vehicle(int size, string type, int make, string model, string color, int year, float miles) : vehicle(type, make, model, color, year, miles){
			fuel_tank_size = size;
		}
		void show_gas_vehicle(){
			cout << "Fuel Tank Size: " << fuel_tank_size << endl;
		}
};
class heavy_vehicle : public gas_vehicle, public electric_vehicle{
	float maxi_weight;
	int num_of_wheels;
	float length;
	public:
		heavy_vehicle(float weight, int wheels, float storage, float length, int size, string type, int make, string model, string color, int year, float miles):gas_vehicle(size, type, make, model, color, year, miles), electric_vehicle(storage, type, make, model, color, year, miles), vehicle(type, make, model, color, year, miles){
			this->length = length;
			num_of_wheels = wheels;
			maxi_weight = weight;
		}
		void show_heavy_vehicle(){
			show_electric_vehicle();
			show_gas_vehicle();
			cout << "Maxi Weight: " << maxi_weight;
			cout << "\nNum of wheels: " << num_of_wheels;
			cout << "\nLength: " << length << endl;
		}
};
class bus : public heavy_vehicle {
	int num_of_seats;
	public:
		bus(int num, float weight, int wheels, float storage, float length, int size, string type, int make, string model, string color, int year, float miles): heavy_vehicle(weight, wheels, storage, length, size, type, make, model, color, year, miles), vehicle(type, make, model, color, year, miles) {
			num_of_seats = num;
		}
		void show_bus() {
			show_heavy_vehicle();
			cout << "Num of Seats: " << num_of_seats << endl;
		}
};
class contruction_truck : public heavy_vehicle {
	string cargo;
	public:
		contruction_truck(string cargo, float weight, int wheels, float storage, float length, int size, string type, int make, string model, string color, int year, float miles): heavy_vehicle(weight, wheels, storage, length, size, type, make, model, color, year, miles), vehicle(type, make, model, color, year, miles) {
			this->cargo = cargo;
		}
		void show_contruction_truck() {
			show_heavy_vehicle();
			cout << "Cargo: " << cargo << endl;
		}
};
class high_performance : public gas_vehicle {
	int horse_power;
	int top_speed;
	public:
		high_performance(int power, int speed, int size, string type, int make, string model, string color, int year, float miles): gas_vehicle(size, type, make, model, color, year, miles), vehicle(type, make, model, color, year, miles) {
			horse_power = power;
			top_speed = speed;
		}
		void show_high_performance() {
			gas_vehicle::show_vehicle();
			show_gas_vehicle();
			cout << "Horse Power: " << horse_power;
			cout << "\nTop Speed: " << top_speed;
		}
};
class sport_car : public high_performance {
	string gear_box;
	string driven_system;
	public:
		sport_car(string gear, string system, int power, int speed, int size, string type, int make, string model, string color, int year, float miles): high_performance(power, speed, size, type, make, model, color, year, miles), vehicle(type, make, model, color, year, miles) {
			gear_box = gear;
			driven_system = system;
		}
		void show_sport_car() {
			show_high_performance();
			cout << "\nGear Box: " << gear_box;
			cout << "\nDriven System: " << driven_system;
		}
};
int main() {
	bus ob1(4, 12, 14, 1.2, 5.4, 54, "Sedan", 1998, "A8", "Grey", 1887, 17.2);
	cout << "****Data From Bus Object****" << endl;
	ob1.show_bus();
	contruction_truck ob2("Sand", 12, 14, 1.2, 5.4, 54, "Sedan", 1998, "A8", "Grey", 1887, 17.2);
	cout << "\n****Data From Construction Truck Object****" << endl;
	ob2.show_contruction_truck();
	sport_car ob3("Automatic", "4*4", 42, 550, 12, "SUV", 1998, "GTR", "White", 2001, 7.5);
	cout << "\n****Data From Sport Car Object****" << endl;
	ob3.show_sport_car();
}
