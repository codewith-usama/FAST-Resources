#include<iostream>
using namespace std;

#define MAX 5

class Stack {
    int top;

    public: 
        int a[MAX];
        Stack() {top=-1;}


        bool push(int x) {
            if(top>=(MAX-1)) {
                cout<<"Stack Overflow";
                return false;
            }
            else {
                a[++top] = x;
                cout<<x<<" Pushed into the stack";
                return true;
            }
        }

        int pop() {
            if(top<0) { cout<<"Stack underflow "; return 0;}

            else {int x = a[top--]; return x;}
        }

        int peek() {
            if(top<0) { cout<<"Stack is empty"; return 0;}

            else {return a[top];}
        }

    
};

int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // cout<<s.pop();
    // cout<<s.pop();
    // s.push(6);
    // cout<<s.pop();

    return 0;
}