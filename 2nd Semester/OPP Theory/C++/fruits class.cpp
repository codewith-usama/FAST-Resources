#include<iostream>
using namespace std;
class fruit{
	protected:
	int num_of_fruit;
	public:
		fruit(){
		}
		fruit(int num){
			num_of_fruit = num;
		}
	
};
class apples : public fruit{
	int num_of_apples;
	public:
		apples(){
		}
		void display_apple(){
			cout << "\nApples are: " << num_of_apples;
		}
		apples(int num){
			num_of_apples = num;
		}
};
class mangoes : public fruit{
	int num_of_mangoes;
	public:
		mangoes(int num, int num_of_fruits) : fruit(num_of_fruits){
			num_of_mangoes = num;
		}
		void display(){
			cout << "Total fruits are: " << num_of_fruit;
			cout << "\nMangoes are: " << num_of_mangoes;
			apples::display_apple();
		}
};
int main(){
	mangoes ob1(12, 50);
	apples ob2(38);
	ob1.display();
}
