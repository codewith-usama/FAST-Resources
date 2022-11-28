#include<iostream>
using namespace std;
class demo
{
	public:
	void show_message()
	{
		cout << "Inside show message function.";
	}
	void const display()
	{
		cout << "Inside the display function.\n";
	}
};
int main()
{
	demo ob1;
	ob1.display();
	ob1.show_message();
}
