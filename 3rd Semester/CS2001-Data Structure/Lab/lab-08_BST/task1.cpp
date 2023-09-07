// Task 1 to check whether it is bst or not
#include<iostream>
using namespace std;

class Node{
	public:
		Node *left;
		Node *right;
		int data;
		Node(int val){
			data=val;
			this->left=NULL;
			this->right=NULL;
		}
		
};
Node *Insert(Node *root,int data){
	if(root==NULL){
		return new Node(data);
	}
	else if(root->data>data){
		root->left=Insert(root->left,data);
		
	} else{
		root->right=Insert(root->right,data);
	}
	return root;
}



int check(Node *root){

	if(root->left!=NULL && root->left->data<root->data){
		return 0;
	}
	
	if(root->right!=NULL && root->right->data>root->data){
		return 0;
	}
	if(!check(root->left)|| !check(root->right)){
		return 0;
	}
	return 1;
}
int main(){
	Node *root;
	root=NULL;
	root=Insert(root,21);
	Insert(root,12);
	Insert(root,13);
	
	cout<<endl;
	if(check(root)==NULL){
		cout<<" Marks= 10 ";
	}
	else{
		cout<<" Marks=0 ";
	}
		cout<<endl;

}
