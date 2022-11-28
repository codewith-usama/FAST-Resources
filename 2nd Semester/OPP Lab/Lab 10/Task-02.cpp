#include<iostream>
using namespace std;
class car {
    string model;
    double price;
    public:
        void set_model(string model) {
            this->model = model;
        }
        void set_price(double price) {
            this->price = price;
        }
        string get_model() {
            return model;
        }
        double get_price() {
            return price;
        }
};
class color : public car {

};
class company : public car {

};