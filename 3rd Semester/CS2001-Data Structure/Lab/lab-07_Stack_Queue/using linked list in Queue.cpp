#include<iostream>
#define CAPACITY 100 
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
		int size=0;
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
			size++;
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
		void dequeue(){
			node *tmp;
			tmp=front;
			if(front==0 && rear==0){
				cout<<"QUEUE is alread empty "<<endl;
			}
			else{
				
			
			tmp=front;
			front=front->next;
			cout<<"deleted data is "<<tmp->data<<" "<<endl;
			
			delete tmp;}
		}
	
	int isFull(){
    return (size > CAPACITY);
}

		
};
int main(){
	Queue Q;
	Q.enqueue(2);
	Q.enqueue(1);
	Q.display();
	cout<<endl;
	Q.dequeue();
	Q.display();
}
