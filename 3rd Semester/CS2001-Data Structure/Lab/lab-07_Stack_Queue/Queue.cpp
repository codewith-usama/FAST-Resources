#include<iostream>
using namespace std;
class node{
	public:
		node *next;
		int data;
		node(){
			this->next=NULL;
			data=0;
			
			
		}
		
		
};
class Queue{
	public:
		node *front;
		node *rear;
		Queue(){
		
		front=0;
		rear=0;
		
		}
		void enqueue(int n){
			node *tmp;
			tmp=new node;
			tmp->data=n;
			if(front==0 && rear==0){
				front=tmp;
				rear=tmp;
			}
			else{
				rear->next=tmp;
				rear=tmp;
				
			}
		}
		
		void display(){
			node *tmp;
			if(front==0&&rear==0){
				cout<<"Queue is empty ";
			}
			else{
				tmp=front;
				while(tmp!=NULL){
					cout<<tmp->data<<" ";
					tmp=tmp->next;
				}
			}
		}
		
};
int main(){
	Queue Q;
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);
	Q.enqueue(5);
	Q.display();
	cout<<endl;
	return 0;
}
