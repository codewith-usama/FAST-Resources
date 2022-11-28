#include<iostream>
using namespace std;
class perimeter;
class print_class {
    float length, width;
    public:
    	print_class() { }
        print_class(float x, float y) {
            length = x;
            width = y;
        }
        friend class perimeter;
};
class perimeter {
    float length, width, total;
    friend class print_class;
    public:
       perimeter(print_class & o) {
       		length = o.length;
       		width = o.width;
	   }
       float get_permimeter() {
           total = ((2 * length) + (2 * width));
           return total;
       }
       void display() {
           cout << "Perimeter: " << total << endl;
       }
};
int main() {
	print_class ob1(5, 8);
	perimeter ob2(ob1);
	ob2.get_permimeter();
	ob2.display();
}