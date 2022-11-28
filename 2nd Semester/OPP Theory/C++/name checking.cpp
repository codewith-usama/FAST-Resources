#include<iostream>
using namespace std;
class persontype{
	string f_name = "Mohammad";
	string l_name = "Kaim Khani";
	string m_name;
	public:
		persontype(string fname, string mname, string lname)
		{
			m_name = mname;
			if(f_name == fname || l_name == lname){
				cout << "Data matched\nError!\n";
			}
			else{
				f_name = fname;
				l_name = lname;
				cout << f_name << " " << m_name << " " << l_name << endl;
			}
		}
};
int main()
{
	persontype ob1("Ahmed", "Usama", "Kaim Khani");
	persontype ob2("Ali", "Ahmed", "Khan");
	persontype ob3("Rahib", "Hussain", "Mari");
}
