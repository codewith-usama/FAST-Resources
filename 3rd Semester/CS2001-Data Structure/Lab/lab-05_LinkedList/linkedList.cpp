#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

    Node(const int data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

class linkedList {
    
    public:
        Node *head;
        Node *tail;
        
    
    linkedList() {
        this->head = NULL;
    }


    // Operations on a Linked list


    void addElementFront(int n);
    void addElementLast(int n);
    bool search(int val);
    void insertIndex(int in, int v);
    void reverse();
    void countNodes();

    // delete
    void deleteFront();
    void deleteEnd();
    void deleteAtIndex(int in);

    void sortt(); 
    
    void display();
};












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





void linkedList::addElementFront(int n) {

    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;

}





void linkedList::addElementLast(int n) {


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




void linkedList::insertIndex(int in, int v)
{

    Node *temp = new Node;
    temp->data = v;

    if(head == NULL)
    {
        head = temp;
    }

    if(in == 0) {
        addElementFront(v);

    }



    else
    {

        Node *p = head;

        for (int i = 0; i < (in-1) ; i++)
        {

            p = p->next;

        }

        temp->next = p->next;
        p->next = temp;

        
    }

}




void linkedList:: reverse(){


    Node *current = head;
    Node *prev = NULL, *next = NULL;    

    while (current != NULL) {


        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
        head = prev;
}





void linkedList::countNodes()
{

    int sum = 0;
    Node *temp = head;

    while (temp!=NULL)
    {

        sum++;
        temp = temp->next;

    }

    cout<<sum<<endl;
    
}





void linkedList::deleteFront()
{

    Node *temp= head;
    head = head->next;
    delete temp;

}




bool linkedList::search(int val)
{
    
    Node *temp = head;

    while(temp!=NULL)
    {


        if(temp->data==val)
            return true;

        else
            temp = temp->next;


    }

        return false;


}




void linkedList::deleteEnd()
{


    Node *temp = head;
    Node *pre = head;

    while(temp->next!=NULL)
    {

        pre = temp;
        temp = temp->next;

    }

    delete temp;
    pre->next = NULL;
}




void linkedList::deleteAtIndex(int in)
{


    Node *p = head, *n = head;
    for (int i = 1; i < in; i++)
    {
        p = n;
        n = n->next;
    }

    p->next = n->next;
    delete n;
    
}




void linkedList::sortt()
{

    Node *temp, *temp2;
    temp = head;
    int num;

    while (temp!=NULL)
    {

        temp2 = temp->next;

        while (temp2!=NULL)
        {


            if(temp->data>temp2->data)
            {

                num = temp->data;
                temp->data = temp2->data;
                temp2->data = num;
            }
            temp2 = temp2->next;
        }


        temp = temp->next;
         
    }
    
}









int main(){

    linkedList l2;
    
    l2.addElementLast(3);
    l2.addElementFront(2);
    l2.addElementFront(1);
    
    l2.addElementLast(5);
    l2.addElementLast(6);
    l2.insertIndex(5, 7);    // Index starts from 0
    
    cout<<l2.search(7);
    
    l2.display();
    
    
    // cout<<endl;
    // cout<<"After Reverse the linked list"<<endl;
    // l2.reverse();
    
    // l2.display();
    
    // l2.countNodes();
    
    // Deletion
    
    // l2.deleteFront();
    // l2.display();
    
    // l2.deleteEnd();
    // l2.display();
    
    l2.deleteAtIndex(1);
    l2.display();
    
    return 0;
}