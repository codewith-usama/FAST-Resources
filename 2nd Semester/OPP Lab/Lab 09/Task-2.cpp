#include<iostream>
using namespace std;
class shape {
    int x;
    int y;
    public:
        shape() {}
        shape(int x, int y) {
            this->x = x;
            this->y = y;
        }
        shape operator + (const shape& o) {
            shape temp;
            temp.x = x + o.x;
            temp.y = y + o.y;
            return temp;
        }
        void get_Area() {
            cout << "Width: "  << x << " Length: " << y << endl;
        }
};
int main() {
    shape ob1(2, 5);
    shape ob2(5, 7);
    shape ob3;
    ob3 = ob1 + ob2;
    ob2.get_Area();

}