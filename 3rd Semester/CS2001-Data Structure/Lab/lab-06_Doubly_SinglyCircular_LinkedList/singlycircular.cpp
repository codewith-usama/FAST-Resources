// #include<iostream>
// using namespace std;

// class Node {
//     public:
//         int data;
//         Node *next;

//     Node() {
//         data = 0;
//         next = NULL;
//     }
// };

// class linkedList: public Node {
//     public:
//         Node *head;
    
//     linkedList() {
//         head = NULL;
//     }

//     void insertFront(int data);
//     void display();

// };

// void linkedList::display() {
//     Node *p;
//     p = head;
//    do {
//       cout<<p->data <<" ";
//       p = p->next;
//    } while(p != head);
// }

// void linkedList::insertFront(int data) {
//     Node *p = new Node();
//     Node *ptr = head;
//     p->data = data;
//     p->next = head;
//     if (head!= NULL) {
//       while (ptr->next != head)
//       ptr = ptr->next;
//       ptr->next = p;
//    } else
//    p->next = p;
//    head = p;
// }


// int main(){
//     linkedList l1;
//     l1.insertFront(5);
//     l1.insertFront(6);
//     l1.insertFront(7);
//     l1.insertFront(8);
//     l1.insertFront(9);
//     l1.display();
    

//     return 0;
// }

#include<iostream>
using namespace std;
class node{
	public:
		node *next;
		int data;
		node *pre;
		node(){
			data=0;
			this->next=NULL;
			this->pre=	NULL;
		}
		node(int n){
			data=n;
			this->next=NULL;
		}
};
class circular{
	
	public:
		node *head,*tail;
		circular(){
			this->head=NULL;
			this->tail=NULL;
		}
		void front(int n){
			  node *tmp;
			  tmp=new node;
			  tmp->data=n;
			  if(head==NULL){
			  	head=tmp;
			  }
			  else{ 
				tmp->next=head;
				head=tmp;
				node *t;
				t=head;
				while(t!=NULL){
					
					t=t->next;
				}
				t->next=head; 
			  		
				
			  
			   
		}
	}
void insert_end(int n)   {
   node *tmp;
   tmp=new node;
   tmp->data=n;
   
  node *t=head;
   tmp->next = NULL;
  
   if (head == NULL) {
      head = tmp;
   }
   while (t->next != NULL)
   t = t->next;
  
   t->next = tmp;          
  
}
		
		
		
		
		void insert_at_any_position(int num, int pos){
     			node *tmp, *t;
    			int i;

    
    			if(pos == 1){
        			front(num);
    			}
    			else{
        			tmp = new node;
        			tmp->data = num;
        			t = head;
        			for(i=2; i<=pos-1; i++){
            			t = t->next;
        			}
        		tmp->next = t->next;
    			t->next	= tmp;
    }
} 





		void delete_head() { //delete first node
			if (head!=NULL){
			int delnode = head->data;
			node *tmp = head;
					if (head == tail){
							head = tail = NULL;}
					else{
						head = head->next;
						delete tmp;
						head->pre=NULL;
			}
}
		else{
			cout<<"list is empty";
		}
}

		void Display() {
  			// struct Node* last;
  			node *t;
  			node *tmp;
  			tmp=head;
   			while (tmp != NULL) {
      			cout<<tmp->data<<" ";
      			t = tmp;
      			tmp = tmp->next;
				   }
   		
   }
};
int main(){
	circular c;
	c.front(2);
	c.Display();
	c.insert_end(1);
	
	c.insert_at_any_position(3,2);
	c.delete_head();
	c.Display();
	
}