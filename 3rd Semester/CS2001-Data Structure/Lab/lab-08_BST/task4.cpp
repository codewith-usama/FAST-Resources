#include<iostream>
using namespace std;

class node
{	public:
	int key;
	node *left;
	 node *right;
};

node* removeOutsideRange(node *root, int min, int max)
{
if (root == NULL)
	return NULL;
root->left = removeOutsideRange(root->left, min, max);
root->right = removeOutsideRange(root->right, min, max);


if (root->key < min)
{
	node *rChild = root->right;
	
	return rChild;
}
if (root->key > max)
{
	node *lChild = root->left;
	return lChild;
}
return root;
}
node* newNode(int num)
{
	node* temp = new node;
	temp->key = num;
	temp->left = temp->right = NULL;
	return temp;
}

node* insert(node* root, int key)
{
	if (root == NULL)
	return newNode(key);
	if (root->key > key)
	root->left = insert(root->left, key);
	else
	root->right = insert(root->right, key);
	return root;
}

void inorderTraversal(node* root)
{
	if (root)
	{
		inorderTraversal( root->left );
		cout << root->key << " ";
		inorderTraversal( root->right );
	}
}
int main()
{
	node* root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 12);
	root = insert(root, 18);
	root = insert(root, 25);
		root = insert(root, 18);


	cout << "Inorder traversal of the given tree is: ";
	inorderTraversal(root);

root = removeOutsideRange(root, 8, 10);

	cout << "\nInorder traversal after removing nodes tree is: ";
	inorderTraversal(root);

	return 0;
}

