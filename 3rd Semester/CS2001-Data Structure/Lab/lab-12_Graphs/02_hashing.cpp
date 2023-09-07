#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node() {};
};

class linkedList : public Node {
    
    public:
        Node *head;

    linkedList() {head == NULL;}

    void front(int n);
    void pussh(int n);
    void display();
};


void linkedList::front(int n) {
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
}


void linkedList::pussh(int n) {
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *t = head;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = temp;

    }
}


void linkedList::display()
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    
}