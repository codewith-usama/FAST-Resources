#include<iostream>
using namespace std;
class mammals{
	public:
	void show_mam(){
		cout << "\nI am mammal.\n";
	}
};
class marine_mammals{
	public:
	void show_marine(){
		cout << "\nI am marine animal.\n";
	}
};
class blue_whale : public mammals, public marine_mammals{
	public:
	void show_blue(){
		cout << "\nI am of both categories.\n";
	}
};
int main(){
	mammals ob1;
	marine_mammals ob2;
	blue_whale ob3;
	ob1.show_mam();
	ob2.show_marine();
	ob3.show_blue();
	ob3.show_marine();
	ob3.show_mam();
}
