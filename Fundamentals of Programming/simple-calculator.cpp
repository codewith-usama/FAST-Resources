#include<iostream>
using namespace std;
int main() {
    int menu;
    cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Remainder\n6.Exit " << endl;
    cin >> menu;
    int num1, num2;
    cout << "Enter First Value: ";
    cin >> num1;
    cout << "Enter Secind Value: ";
    cin >> num2;
    switch(menu) {
        case 1:
            cout << "Addition is " << num1 + num2;
            break;
        case 2:
            cout << "Subtraction is " << num1 - num2;
            break;
        case 3:
            cout << "Multiplication is " << num1 * num2;
            break;
        case 4:
            if(num1 > num2)
                cout << "Division is " << num1 / num2;
            else
                cout << "Division is " << num2 / num1;    
            break;
        case 5:
            cout << "Remainder is ";
            break;
        case 6:
            cout << "Thank you for using.";
            break;    
    }
}