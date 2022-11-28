#include<iostream>
using namespace std;
class shop
{
	public:
	int itemnum;
	string name;
	double price;
	double discount1;
	public:
		shop(){
			cout<<"enter item number : "<<endl;
			cin>>itemnum;
			cout<<"enter item name : "<<endl;
			cin>>name;
			cout<<"enter item price : "<<endl;
			cin>>price;
		cout<<"enter discount percentage : "<<endl;
			cin>>discount1;
			display();
		}
		void display()
		{
			cout<<"item number : "<<itemnum<<endl;
			cout<<"item name : "<<name<<endl;
			cout<<"item price : "<<price<<endl;
		}
};
class discount:public shop
{
	public:
		double count;
	double ans;
	double total;
	public:
 	    double dis(double price,double discount1)
		{
			count=discount1*0.01;
			ans=count*price;
			total=price-ans;
			return total;
		}
};
int main()
{
	discount s1;
	s1.dis(s1.price,s1.discount1);
	cout<<"the discounted price will be : "<<s1.total<<endl<<endl;
	cout<<endl;
	discount s2;
	s2.dis(s2.price,s2.discount1);
	cout<<"the discounted price will be : "<<s2.total<<endl<<endl;
	cout<<endl;
	discount s3;
	s3.dis(s3.price,s3.discount1);
	cout<<"the discounted price will be : "<<s3.total<<endl<<endl;
}
