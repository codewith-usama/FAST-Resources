#include<iostream>
using namespace std;
class Node {
	private:
		int data;
		Node *next;
	public:
		Node():next(NULL) { }
		Node(int d):data(d) { }
		friend class StackLinkedList;
};
class StackLinkedList {
	private:
		Node *head, *tail;
	public:
		Node* Get_Head() { return head; }
		StackLinkedList():head(NULL), tail(NULL) { }
		StackLinkedList& push(int);
		int pop();
		int peek();
		void Display(Node* p);
};
/* For inserting Node in Stack. Push function insert every Node at the beginning so we are reading
   from stack in will be LIFO(First In Last Out) */
StackLinkedList& StackLinkedList::push(int data) {
	Node *temp = new Node(data);
	if(head == NULL) {
		temp->next = NULL;
		head = tail = temp;
		cout << temp->data << " PUSHED\n";
		return *this;
	}
	temp->next = head;
	head = temp;
	cout << temp->data << " PUSHED\n";
	return *this;
}
/* Deleting the last inserted Node from Stack and returning back */
int StackLinkedList::pop() {
	if(head) {
		Node *p = head;
		int x = head->data;
		head = head->next;
		delete p;
		return x;
	}
	cout << "Stack is UnderFlow\n";
}
/* For Displaying Stack recursively */
void StackLinkedList::Display(Node *p) {
	if(p) {
		cout << p->data <<  " ";	
		Display(p->next);
	}
}
int StackLinkedList::peek() {
	if(head) {
		int x = head->data;
		return x;
	}
	cout << "Stack Is Empty\n";
}
int main() {
	StackLinkedList ob1;
//	 ob1.peek();
//	 ob1.pop();
	ob1.push(12).push(13).push(14).push(15).push(16);
	ob1.Display(ob1.Get_Head());
	cout << endl << ob1.pop() << " poped\n";
	ob1.Display(ob1.Get_Head());
	cout << endl << ob1.peek() << endl;
	return 0;
}
