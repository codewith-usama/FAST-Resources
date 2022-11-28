#include<iostream>
using namespace std;
class student
{
	string name;
	int roll_num;
	string phone_num;n
	string address;
	
	public:
		string getname()
		{
			return name;
		}
		void setname(string name)
		{
			this->name = name;
		}
		int getnum()
		{
			return roll_num;
		}
		void setnum(int num)
		{
			roll_num = num;
		}
		string getphone_num()
		{
			return phone_num;
		}
		string getall()
		{
			string name;
			int roll_num;
			string phone_num;
			string address;
		}
		void setphone_num(string num)
		{
			phone_num = num;
		}
		string getaddress()
		{
			return address;
		}
		void setadress(string address)
		{
			this -> address = address;
		}
		student()
		{
			string name;
			int roll_num;
			string phone_num;
			string address;
		}
		student(string a, int b, string c, string d)
		{
			name = a;
			roll_num = b;
			phone_num = c;
			address = d;
		}
};
int main()
{
	student ob1("Usama", 12, "03123898090", "House No 66/9 Qaim Khani Mohallah Samaro Twon District Umerkot, Sindh, Pakistan");
	cout << ob1.getname() << endl;
	cout << ob1.getnum() << endl;
	cout << ob1.getphone_num() << endl;
	cout << ob1.getaddress() << endl;
}
