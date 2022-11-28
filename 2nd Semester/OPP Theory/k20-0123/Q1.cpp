#include<iostream>
using namespace std;
class team
{
	public:
		int x;
	int id;
	string name;
	double truns;
	double noofing;
	double avg;
	team()
	{
		id=20;
		name="masab";
		truns=2134;
		noofing=30;
		average(truns,noofing);
		display();
	}
	double average(double truns,double noofing)
	{
		avg=truns/noofing;
		return avg;
	}
		team(const team &o)
		{
			this->id=o.id;
	        this->name=o.name;
	        this->truns=o.truns;
	        this->noofing=o.noofing;
	        this->avg=o.avg;
		}
		void display()
		{
			cout<<"ID : "<<id<<endl;
			cout<<"name : "<<name<<endl;
			cout<<"total runs : "<<truns<<endl;
			cout<<"average : "<<avg<<endl;
			cout<<endl;
		}
};
int main()
{
	team t1;
	cout<<endl<<endl;
	team t2(t1);
	t2.display();
}
