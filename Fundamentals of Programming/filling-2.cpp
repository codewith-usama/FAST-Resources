#include<iostream>
using namespace std;
int main() {
    for(int i = 1; i <= 100; i++) {
        // if(i == 2)
        //     cout << i << endl;
        if(i % i-1 == 1)
            cout << i << endl;
    }
}