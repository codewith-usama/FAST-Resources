#include<iostream>
using namespace std;
class node{
	public:
		node *left;
		node *right;
		string data;
		node(string val){
			this->left=NULL;
			this->right=NULL;
			val=data;
		}
};
class BinaryTree{
	private:
		node *root;
	public:
		void addnode(int key,string name){
			node *tmp;
			tmp=new node(name);
			if(root==NULL){
				return new node(name);
			}
			else if(root->data>name){
				root->left=addnode();
				 	
			}
		}
		
};
