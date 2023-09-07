#include<iostream>
using namespace std;

class node{
	public:
		node *left;
		node *right;
		int data;
		node(int val){
			data=val;
			this->left=NULL;
			this->right=NULL;
		}
		
};



node *Insert(node *root,int data){
	if(root==NULL){
		return new node(data);
	}
	else if(root->data>data){
		root->left=Insert(root->left,data);
		
	} else{
		root->right=Insert(root->right,data);
	}
	return root;
}
void preorder(node *root){
	if(root==NULL){
		return;
	}
	else{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){

	node *root;
	root=NULL;
root=Insert(root,15);
	Insert(root,10);
	Insert(root,8);
	Insert(root,20);
	Insert(root,25);
	Insert(root,12);
	Insert(root,16);

	preorder(root);
	
}
