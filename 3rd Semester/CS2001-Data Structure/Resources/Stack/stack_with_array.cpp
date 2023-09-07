#include<iostream>
using namespace std;

/// The size of the stack
#define SIZE 5

class Stack {
    public:
    int top;
    int a[SIZE];

    Stack() {
        top = -1;
    }

    void __push(int val);
    int __pop();
    int __peek();
    bool __isEmpty();
    bool __isFull();
    // void __display(Stack obj);

};


void Stack::__push(int val) {
    if(top >= SIZE-1) {
        cout<<"Stack is full";
    }

    else {
        top++;
        a[top] = val;
    }
}


int Stack::__pop() {
    if(top==-1) {
        cout<<"The stack is Empty";
        return 0;
    }
    int x = a[top];
    top--;
    return x;
}

int Stack::__peek() {
    return a[top];
}   

bool Stack::__isEmpty()  {
    if(top==-1) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::__isFull() {
    if(top == SIZE-1) {
        return true;
    }

    else {
        return false;
    }
}

void __display(Stack obj) {
    // for (int i = 0; i < top+1; i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    while(!obj.__isEmpty()) {
        cout<<obj.__pop()<<" ";
    }
    
}



int main()

{

    Stack s1;
    s1.__push(5);
    s1.__push(2);
    s1.__push(3);
    __display(s1);
    //////////


    cout<<s1.__peek()<<endl;
    cout<<s1.__isEmpty()<<endl;
    cout<<s1.__isFull()<<endl;

    s1.__pop();
    __display(s1);

    return 0;
}