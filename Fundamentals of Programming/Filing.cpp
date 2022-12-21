#include<iostream>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int a = 1, b, n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a += 1;
    }
    cout << a;

    return 0; 
}