#include<iostream>
using namespace std;
int main() {
    int num;
    cout << "Type a Number: ";
    cin >> num;
    if(num >= 1 && num <= 20)
        if(num == 3 || num == 5 || num == 19 || num == 19)
            cout << "You Won! Take your gift from the counter";
        else
            cout << "Sorry! Try Again";
}