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
void Inorder(node *root){
	if(root==NULL){
		return;
	}
	else{
		Inorder(root->left);
		cout<<root->data<<" ";
		Inorder(root->right);
	}
}
void pre_order(node *root){
	if(root==NULL){
		return;
	}
	else{
		cout<<root->data<<" ";
		pre_order(root->left);
		pre_order(root->right);
	}
	
}


	
int main(){
	node *root;
	root=NULL;
	root=Insert(root,21);
	Insert(root,12);
	Insert(root,13);
	cout<<"Inorder "<<endl;
	Inorder(root);
	cout<<endl;
	//check(root);

		cout<<endl;
		cout<<"pre order "<<endl;
		pre_order(root);
		}

