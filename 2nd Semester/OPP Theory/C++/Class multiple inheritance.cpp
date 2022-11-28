#include<iostream>
using namespace std;
class A{
	private: int x = 1;
	public: int y = 2;
	protected: int z = 3;
};
class B : private A{
	public:
	void showA(){
//		cout << x;
		cout << " " << y;
		cout << " " << z;
	}
};
class C : public A{
	public:
	void showB(){
//		cout << x;
		cout << " " << y;
		cout << " " << z;
	}
};
int main(){
	class C ob1;
	class B ob2;
	ob2.showA();
	ob1.showB();
}
