#include<iostream>
using namespace std;
class employee{
	string id;
	double salary;
	string desigination;
	public:
		void setid(string id)
		{
			this->id = id;
		}
		string getid()
		{
			return id;
		}
		void setsalary(double salary)
		{
			this->salary = salary;
		}
		double getsalary()
		{
			return salary;
		}
		void setdesigination(string desigination)
		{
			this->desigination = desigination;
		}
		string getdesigination()
		{
			return desigination;
		}
		employee(){}
		employee(string id, double s, string d)
		{
			this->id = id;
			salary = s;
			desigination = d;
		}
		void display_employee()
		{
			cout << id << " Works here " << desigination;
		}
};
class tpharma{
	string tagline;
	string ceo;
	double stock_value;
	employee e;
	public:
		void settagline(string tagline)
		{
			this->tagline = tagline;
		}
		string gettagline()
		{
			return tagline;
		}
		void setceo(string ceo)
		{
			this->ceo = ceo;
		}
		string getceo()
		{
			return ceo;
		}
		void setstock(double stock_value)
		{
			this->stock_value = stock_value;
		}
		double getstock()
		{
			return stock_value;
		}
		void display_pharma()
		{
			cout << e.getid() << " Works here.";
		}
		tpharma(string t, string c, double s, employee e1)
		{
			tagline = t;
			ceo = c;
			stock_value = s;
			e = e1;
		}
		tpharma(){}
};
int main()
{
	employee e2("123", 5000, "ABC");
	tpharma t1("ijk", "xyz", 251, e2);
	e2.display_employee();
}
