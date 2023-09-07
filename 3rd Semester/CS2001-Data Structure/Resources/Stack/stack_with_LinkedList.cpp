#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

    Node() {
        data = 0;
        next = NULL;
    }


};

class StaticLinked: public Node {
    public:
        Node *head;
        Node *tail;

    StaticLinked() {
        head = NULL;
        tail = NULL;
    }

    void push(int x);
    void displaytop();
    void displayStack();
    bool isEmpty();
    int pop();
};


void StaticLinked::push(int x) {
    Node *n = new Node();
    if(head == NULL) {
        n->data = x;
        n->next = NULL;
        head = n;
    }
    else{
    n->data = x;
    n->next = head;
    head = n;
    }
}

int StaticLinked::pop() {
    int data;
    if(head==NULL) {
        cout<<"Stack underflow"<<endl;
        return 0;
    }
    else {
        Node *temp = head;
        data = head->data;
        head = head->next;
        delete temp;
    }
    return data;
}

void StaticLinked::displaytop() {
    if(head==NULL) {
        cout<<"Stack is empty"<<endl;
    }
    else
    cout<<head->data<<endl;
}

bool StaticLinked::isEmpty() {
    if(head==NULL) {
        return true;
    }
    else
        return false;
}

void StaticLinked::displayStack() {
    if(head==NULL) {
        cout<<"Stack is empty"<<endl;
    }
    else{
    Node *temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
        
    }
    }
}

int main(){

    StaticLinked s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.displayStack();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.displayStack();


    return 0;
}