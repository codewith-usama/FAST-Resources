#include<iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter month order/number for the Season: ";
    cin >> num;
    if(num >= 2 && num <= 4)
        cout << "Its Spring Season";
    else if(num >= 5 && num <= 7)
        cout << "Its Summmer Season";
    else if(num >=8  && num <= 10)
        cout << "Its Autumn Season";
    else if(num == 1 || num == 11 || num == 12)
        cout << "Its Winter Season";
    else
        cout << "Invalid Order";    
}