#include<iostream>
using namespace std;
class decrement {
    float x;
    public:
        decrement(float x) {
            this->x = x;
        }
        decrement operator -- (int) {
            x /= 4;
        }
        decrement operator -- () {
            x *= 4;
        }
        float get_x() {
            return x;
        }
};
int main() {
    decrement ob1(5);
    ob1--;
    cout << ob1.get_x();
    --ob1;
    cout << endl << ob1.get_x();
}