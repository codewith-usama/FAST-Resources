#include<iostream>
using namespace std;
int main() {
    int num1, num2;
    char oper;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter an operator(+, -, *, /, %) ";
    cin >> oper;
    
    switch(oper) {
        case '+':
            cout << "Output is: " << num1 + num2;
            break;
        case '-':
            cout << "Output is: " << num1 - num2;
            break;
        case '*':
            cout << "Output is: " << num1 * num2;
            break;
        case '/':
            cout << "Output is: " << num1 / num2;
            break;
        case '%':
            cout << "Output is: " << num1 % num2;
            break;
        default:
            cout << "Opeartor not avalaible"; 
    }
}