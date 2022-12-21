#include<iostream>
using namespace std;
int main() {
    int menu;
    cout << "1.Mark Sheet\n2.ATM\n3.Salary Sheet\n4.Exit" << endl;
    cin >> menu;
    switch(menu) {
        case 1:
            cout << "Mark Sheet";
            break;
        case 2:
            cout << "ATM";
            break;
        case 3:
            cout << "Salary Sheet";
            break;
        case 4:
            cout << "Thanks for using";
            break;
        default:
            cout << "Invalid";
    }
}