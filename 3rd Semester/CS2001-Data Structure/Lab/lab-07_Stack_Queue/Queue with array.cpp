#include<iostream>
#define n 4
using namespace std;

class Queue {

int front, rear, size;
public:
	int arr[n];
	Queue(){
		front=-1;
		rear=-1;
	}
	bool enqueue(int data){
		if(rear==n-1){
			cout<<"Overflow ";
			return 0;
		}
		
		else{
			rear++;
			arr[rear]=data;
		//	cout<<arr[rear];
			return true;
		}
	}
	int dequeue(){
		if(front==rear){
			cout<<"empty  ";
		}
		else{
//						front++;
							//		front++;
//
			cout<<"deleted element is "<<arr[rear]<<endl;
								//	front++;

			rear--;
			int s=arr[rear];
			cout<<"Now front is Pointing to "<<s<<endl;
			
			return s;
		}
	}
	int peek(){
		if(rear<0){
			cout<<"underflow ";
		}
		else{
			//cout<<arr[rear];
			int p=arr[rear];
			cout<<"Top element is "<<p<<endl;
		}
	}
	bool isfull(){
		if(rear==n){
			cout<<"oops Queue is Full ";
			return true;
		}
		else{
			 return false;	
		}
	}

};

int main(){
	Queue q;
	q.enqueue(2);
	q.enqueue(23);
	q.enqueue(245);
	q.isfull();
	q.enqueue(237);
	q.isfull();
	
	q.peek();
q.dequeue();

//q.peek();
}

