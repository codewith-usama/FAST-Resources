#include<iostream>
using namespace std;
class shape {
    public:
    virtual void get_area() {}

};
class rectangle : public shape {
    float height, width;
    public:
    rectangle(float height, float width) {
        this->height =height;
        this->width = width; 
    }
        void get_area() {
            cout << "Area of Rectangle: " << height * width << endl;
        }
};
class triangle : public shape {
    float height, base;
    public:
    triangle(float height, float base) {
        this->height = height;
        this->base = base;
    }
    void get_area() {
            cout << "Area of Triangle: " << ((height * base ) / 2) << endl;
        }
};
int main() {
    triangle ob1(5, 2.3);
    rectangle ob2(8, 7.4);
    ob1.get_area();
    ob2.get_area();
}
