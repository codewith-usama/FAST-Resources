#include<iostream>
using namespace std;
int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    if(ch == 'a' || ch == 'A')
        cout << ch << " for Apple";
    else if(ch == 'b' || ch == 'B')
        cout << ch << " for Ball";    
}