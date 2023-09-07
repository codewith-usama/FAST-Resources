#include <iostream>
using namespace std;

#define MAX 5


class Stack {
    int top;
    
    public:
        int a[MAX];  // Maximum size of an stack
        
        Stack() {
            top = -1;
        }
        
        bool push (int x) {
            if (top>=(MAX-1)) {
                cout<<"Stack Overflow";
                return false;
            }
            else {
                a[++top] = x;
                cout<<x<<" pushed into the stack";
                return true;
            }
        }
        
        
        int pop() {
            if(top<0) {
                cout<<"Stack underflow";
                return 0;
            }
            
            else {
//                cout<<"Hey! Value poped succussfully"<<endl;
                int x = a[top--];
                return x;
            }
        }
        
        
        int peek() {
            if (top<0) {
                cout<<"Stack is Empty";
                return 0;
            }
            
            else {
                int x = a[top];
                return x;
            }
        }
        
        bool isEmpty()   // here
        {
          if(top<0) {
            return false;
        }
        else
          return true;
        }
};


int main()
 {
     Stack s1;
     s1.push(4);
     s1.push(5);
     s1.push(6);
     s1.push(7);
     s1.push(8);


    cout<<endl;

// Display Elements using for loop

    // for(int i=0; i<MAX; i++) {
    //     cout<<s1.peek()<<" ";
    //     s1.pop();
    // }


//  Display Elements using while loop
// s1.push(8);
   while (s1.isEmpty()) {
       cout<<s1.peek()<<" ";
       s1.pop();
   }
     return 0;
 }