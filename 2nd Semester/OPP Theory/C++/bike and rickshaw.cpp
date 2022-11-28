#include<iostream>
using namespace std;
class Vehicle
{
	    public:
		static int acc;
		static int brake;
	    int speed;
	    int year;
	   string manufacturer;
	

	Vehicle& acceleration() // chain function
	{
		
		acc += 5;
		cout << acc << ".";
		brake = acc;
		return *this;
	}
	Vehicle& brk(){
		
		brake -= 5;
		cout << brake << ".";
		return *this;
	}
		Vehicle()
		{
		}
};
int Vehicle::acc = 0;
int Vehicle::brake = 0;

class bike : public Vehicle{
	public:
		bike()
		{
			cout << "Enter model year of bike: ";
			cin >> year;
			cout << "Enter Manufacturer name: ";
			fflush(stdin);
			getline(cin, manufacturer);
			cout << "Enter intial speed: ";
			cin >> speed;
			acc = speed;
		}
};
class rickshaw : public Vehicle
{
	public:
		rickshaw()
		{
			cout << "Enter model year of rickshaw: ";
			cin >> year;
			cout << "Enter Manafacturer name: ";
			fflush(stdin);
			getline(cin, manufacturer);
			cout << "Enter intial speed: ";
			cin >> speed;
			acc = speed;
		}
};
int main(void)
{
	int num;
	cout << "Enter num of wheels: ";
	cin >> num;
	if(num == 2){
		bike ob1;
		cout << "Accerating...";
		ob1.acceleration().acceleration().acceleration();
		cout << "\nApplying brake...";
		ob1.brk().brk();
	}
	else if(num == 3){
		rickshaw ob2;
		cout << "Accerating...";
		ob2.acceleration().acceleration().acceleration();
		cout << "\nApplying brake...";
		ob2.brk().brk();
	}
}
