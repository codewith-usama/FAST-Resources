#include<iostream>
using namespace std;
class Glass
{
	public:
		int LiquidLevel;
			void Drink(int militers)
			{
				if(militers < 100)
				{
					Refill();
				}
			}
			void Refill()
			{
				LiquidLevel = 200;
				cout << "Liquid is galss is : "<< LiquidLevel<< "militers.";
			}
};
int main()
{
	Glass ob1;
	char m = 'y';
	ob1.LiquidLevel = 200;
	while(m == 'y' || m == 'Y')
	{
		cout << "Enter Quantity of liquid in Glass (Militers): ";
		cin >> ob1.LiquidLevel;
		ob1.Drink(ob1.LiquidLevel);
		cout << "\nCheck more glass y/n??";
		cin >> m;
		if(m == 'n' || m == 'N')
			m = 'n';
			else 
			system("cls");
			continue;
	}
}
