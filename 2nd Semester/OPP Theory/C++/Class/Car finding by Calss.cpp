#include<iostream>
using namespace std;
class Car
{
	public:
	string model, name;
	int capacity;
	void fun(void)
	{
		cout << "Car find.\n";
		void car(void)
		{
			cout << "\nMehran.";
		}
	}
};
int main()
{
	int data;
	cout << "How many Car's data you want to enter: ";
	cin >> data;
	
	Car ob[data];
	
	for(int i = 0; i < data; i++)
	{
		cout << "\nCar "<< i+1 << "Data:";
		cout << "\nEnter Model: ";
		fflush(stdin);
		getline(cin,ob[i].model);
		
		cout << "Enter Car Name: ";
		getline(cin,ob[i].name);
		
		cout << "Enter Seating capacity: ";
		cin >> ob[i].capacity;
		
		if(ob[i].model == "Suzuki" || ob[i].model == "SUZUKI" || ob[i].model == "suzuki")
		{
			if(ob[i].name == "Mehran" || ob[i].name == "mehran" || ob[i].name == "MEHRAN")
			{
				if(ob[i].capacity == 5 || ob[i].capacity == 4)
				{
					ob[i].fun();
//					ob[i]
					if(i < 5)
					continue;
					else
					break;
				}
			}
		}
	}
}
