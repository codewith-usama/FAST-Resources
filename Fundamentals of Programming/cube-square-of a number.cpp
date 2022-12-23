#include <iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int square = 1, cube = 1;
    for(int i = 0; i < 3; i++) {
        cube *= num;
        if(i == 2) {
            square = num * num;
        }
            
    }
    cout << "Cube is: " << cube << " Square is " << square;
}