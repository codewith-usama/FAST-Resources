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

class CLL: public Node {
    public:
        Node *head;
        Node *tail;
        CLL() {
            head = NULL;
            tail = NULL;
        }

    void insertPosition(int p, int val);
    void insertFront(int val);
    void insertEnd(int val);
    void displayList();

    // delection

    void deleteFront();
    void deleteEnd();
    void deletePosition(int p);
};

void CLL:: insertFront(int val) {
    Node *temp = new Node();
    temp->data = val;

    if(head == NULL) {
        // temp->next = head;
        head = temp;
        tail = temp;
    }

    else {
        temp->next = head;
        // tail->next = temp;
        head = temp;
        tail->next = head;
    }
}

void CLL::insertEnd(int val) {
    Node *temp = new Node();
    temp->data = val;

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
}

void CLL::insertPosition(int p, int val) {
    Node *temp = new Node();
    temp->data = val;

    Node *t = head;

    for (int i = 1; i < (p-1); i++)
    {
        t = t->next;
    }

    temp->next = t->next;
    t->next = temp;
    
}

void CLL::displayList() {
    Node *t = head;
    


    do{
        cout<<t->data<<" ";
        t = t->next;
    }while(t!=head);
}

void CLL::deleteFront() {
    Node *temp = head;
    head = head->next;
    delete temp;
    tail->next = head;
}

void CLL::deleteEnd() {
    Node *temp = head->next;
    while(temp->next->next != head) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next=head;
}


void CLL::deletePosition(int p) {

    if(p==1) {
        deleteFront();
    }

    if(p!=1) {
    Node *t = head;

    for (int i = 1; i < (p-1); i++)
    {
        t = t->next;
    }

    Node *pp = t->next;

    t->next = t->next->next;

    delete pp;
    
}

}


int main(){

    CLL l;
    l.insertFront(8);
    l.insertFront(7);
    l.insertFront(8);
    l.insertEnd(9);
    l.insertEnd(10);
    l.insertEnd(11);
    l.deleteEnd();
    // l.deleteEnd();
    // l.deleteEnd();
    l.deleteFront();
    // l.insertEnd(6);
    l.insertPosition(2, 4);
    // l.insertPosition(4, 99);
    // l.deletePosition(4);
    // l.deletePosition(1);
    l.deletePosition(4);
    // l.deleteFront();
    l.displayList();

    return 0;
}