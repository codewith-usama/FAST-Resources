#include<iostream>
#include<string.h>
using namespace std;
class product{
	int bar_code;
	string name;
	public:
		void display_product(){
			cout << "\nBar code: " << bar_code;
			cout << "\nName of product: " << name << endl;
		}
		void set_code(int code){
			bar_code = code;
		}
		void scan_name(string name){
			this->name = name;
		}
		string print_name(){
			return name;
		}
		int get_code(){
			return bar_code;
		}
		product(){
		}
		product(int code, string name){
			this->name = name;
			bar_code = code;
		}
};
class prepacked_food : public product{
	float unit_price;
	public:
		void display_prepacked(){
			display_product();
			cout << "Unit price: " << unit_price << endl;
		}
		void set_unitprice(float price){
			unit_price = price;
		}
		float get_unitprice(){
			return unit_price;
		}
		prepacked_food()
		{
		}
		prepacked_food(float price){
			unit_price = price;
		}
};
class fresh_food : public product{
	float weight;
	float price_per_kilo;
	public:
		void display_fresh(){
			prepacked_food ob5;
			ob5.display_prepacked();
			cout << "Weight : " << weight << endl;
			cout << "price per kilo :" << price_per_kilo;
		}
		void set_weight(float weight){
			this->weight = weight;
		}
		void set_kiloprice(float price){
			price_per_kilo = price;
		}
		float get_weight(){
			return weight;
		}
		float get_kiloprice(){
			return price_per_kilo;
		}
		fresh_food(){
		}
		fresh_food(float weight, float price){
			this->weight = weight;
			price_per_kilo = price;
		}
};
int main(){
	fresh_food ob1;
	prepacked_food ob2;
	product ob3;
	ob1.display_fresh();
	ob1.set_kiloprice(2.4f);
	ob1.set_weight(23);
	ob2.set_code(15);
	ob2.set_unitprice(25);
	ob3.set_code(54);
}
