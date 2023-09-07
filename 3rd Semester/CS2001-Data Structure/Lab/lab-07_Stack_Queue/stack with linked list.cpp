#include<iostream>
using namespace std;

class node{
	int top;
	public:
	
		node *next;
		int data;
		node(){
			top=0;
			next=NULL;
			data=0;
		}
		
};
class linked{
	public:
		node *top;
		linked(){
			top=NULL;
		}
		bool push(int n){
			node *tmp;
			tmp=new node;
			tmp->data=n;
			if(top==NULL){
				top=tmp;
				
			}
			else{
				tmp->next=top;
				top=tmp;
				
				
			}
		}
		int pop(){
			node *tmp;
			tmp=top;
			if(top==NULL){
				cout<<"stack is empty ";
			}
			else{
				top=top->next;
				delete top;
			}
		}
		int peek(){
			node *tmp;
			tmp=top;
			if(top==NULL){
				cout<<"Stack is empty ";
			}
			else{
				cout<<"top element is  "<<top->data<<" ";
				
			}
		}
		void dislay(){
			node *tmp;
			tmp=top;
			while(tmp!=NULL){
				cout<<tmp->data<<" ";
				tmp=tmp->next;
			}
		}
		
	void reverse()
	{
		
		node* current = top;
		node *prev = NULL, *next = NULL;

		while (current != NULL) {
			next = current->next;

			current->next = prev;

			prev = current;
			current = next;
		}
		top = prev;
	}

};
int main(){
	linked l;
	l.push(12);
	l.push(1);
	l.push(2);
	l.push(11);
	l.push(3);
	l.push(15);
	l.push(155);
	l.push(17);
	l.push(162);
	l.push(113);
	
	
	cout<<"before reversing the elements are "<<endl;
	
	l.dislay();
	cout<<endl;
	cout<<"after reversing the elements are "<<endl;
	l.reverse();
	l.dislay();
	cout<<endl;
	cout<<endl;
//	cout<<"after deleting all elements from stack "<<endl;
//	l.peek();
	l.pop();
	//l.peek();
	cout<<endl;
//	l.peek();
	l.pop();
	//l.pop();l.pop();l.pop();l.pop();l.pop();l.pop();l.pop();
	l.peek();
	l.peek();
}
