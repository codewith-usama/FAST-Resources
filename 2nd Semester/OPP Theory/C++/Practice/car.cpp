#include<iostream>
using namespace std;
class car
{
	public:
	string color;
	int num_of_tyres;
	int seats;
//	car(string color, int num_of_tyres, int seats)
//	{
//		this->color = color;
//		this->num_of_tyres = num_of_tyres;
//		this->seats = seats;
//	}
};
class sport_car : public car
{
	public:
		int navigator;
		int alram;
	sport_car(int navigator, int alram, string color, int num_of_tyres, int seats)
	{
		this->navigator = navigator;
		this->alram = alram;
		this->color = color;
		this->num_of_tyres = num_of_tyres;
		this->seats = seats;
	}	
};
int main()
{
	string color;
	int tyres, seats;
	cout << "Enter color: ";
	getline(cin, color);
	cout << "Enter num of tyres: ";
	cin >> tyres;
	cout << "Enter seats: ";
	cin >> seats;
	int navi, alram;
	cout << "Enter navigator: ";
	cin >> navi;
	cout << "Enter alram: ";
	cin >> alram;
	sport_car ob1(navi, alram, color, tyres, seats);
}
