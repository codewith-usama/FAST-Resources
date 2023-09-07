// C++ program to implement iterative preorder traversal
#include <bits/stdc++.h>

using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}


void iterativePreorder(node* root)
{
	if (root == NULL)
		return;


	stack<node*> nodeStack;
	nodeStack.push(root);


	while (nodeStack.empty() == false) {
		struct node* node = nodeStack.top();
		printf("%d ", node->data);
		nodeStack.pop();

		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
}

int main()
{

	struct node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	iterativePreorder(root);
	return 0;
}

