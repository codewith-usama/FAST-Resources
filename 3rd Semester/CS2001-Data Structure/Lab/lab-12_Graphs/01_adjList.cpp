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



class Graph {
    public:
        int v;
        linkedList *obj = NULL;

    Graph(int v) {
        this->v = v;
        obj = new linkedList[v+1];
    }


    void addEdge(int x, int y) {
        obj[x].pussh(y);
        obj[y].pussh(x);
    }



    void diplay() {
        for (int i = 1; i <= v; i++)
        {
            cout<<"Vertex " << i << " -> ";
            Node *temp = obj[i].head;

            while (temp!=NULL)
            {
                cout<< temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
            
        }
        
    }
};

int main() {

    int v;
    Graph obj(6);

    obj.addEdge(1,5);
    obj.addEdge(1,2);
    // obj.addEdge(2,1);
    obj.addEdge(2,3);
    obj.addEdge(2,5);
    obj.addEdge(3,4);
    obj.diplay();
    return 0;
}