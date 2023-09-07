// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>

#include<iostream>
using namespace std;
class Node
{
public:
int key;
Node *left;
Node *right;
int height;
};
int max(int a, int b);
int height(Node *N)
{
if (N == NULL)
return 0;
return N->height;
}
int max(int a, int b)
{
return (a > b)? a : b;
}
Node* newNode(int key)
{
Node* node = new Node();
node->key = key;
node->left = NULL;
node->right = NULL;
node->height = 1;
return(node);
}


void post_order(Node *root){
if(root==NULL){
return;
}
else{
post_order(root->right);
cout<<root->key<<" ";
post_order(root->left);
}
}
Node *rightRotate(Node *y)
{
Node *x = y->left;
Node *T2 = x->right;
x->right = y;
y->left = T2;
y->height = max(height(y->left),
height(y->right)) + 1;
x->height = max(height(x->left),
height(x->right)) + 1;
return x;
}
Node *leftRotate(Node *x)
{
Node *y = x->right;
Node *T2 = y->left;
y->left = x;
x->right = T2;
x->height = max(height(x->left),
height(x->right)) + 1;
y->height = max(height(y->left),
height(y->right)) + 1;
return y;
}
int getBalance(Node *N)
{
if (N == NULL)
return 0;
return height(N->left) - height(N->right);
}
Node* insert(Node* node, int key)
{
if (node == NULL)
return(newNode(key));

if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
else
return node;
node->height = 1 + max(height(node->left),
height(node->right));

int balance = getBalance(node);

if (balance > 1 && key < node->left->key)
return rightRotate(node);


if (balance < -1 && key > node->right->key)
return leftRotate(node);

if (balance > 1 && key > node->left->key)
{
node->left = leftRotate(node->left);
return rightRotate(node);
}
if (balance < -1 && key < node->right->key)
{
node->right = rightRotate(node->right);
return leftRotate(node);
}

return node;
}

void preOrder(Node *root)
{
if(root != NULL)
{
cout << root->key << " ";
preOrder(root->left);
preOrder(root->right);
}
}

bool AVLsearch( Node *root, int key)
{
    if (root == NULL)
        return false;
      else if (root->key == key)
        return true;

    else if (root->key > key) {
        bool val = AVLsearch(root->left, key);
        return val;
    }

    else {
        bool val = AVLsearch(root->right, key);
        return val;
    }
}
void inorder(Node *root){
if(root==NULL){
return;
}
else{
inorder(root->left);
cout<<root->key<<" ";
inorder(root->right);
}
}
 
int main()
{
Node *root = NULL;
root = insert(root, 55);
root = insert(root, 66);
root = insert(root, 77);
root = insert(root, 11);
root = insert(root, 33);
root = insert(root, 35);
root = insert(root, 25);
root = insert(root, 44);
root = insert(root, 88);
root = insert(root, 99);
cout<<endl;
cout<<"height: "<<height(root);
cout<<endl;
cout << "Preorder traversal of the "
"constructed AVL tree is \n";
preOrder(root);
cout<<endl;
cout<<"PostOrder Traversal "<<endl;
post_order(root);
cout<<endl;
cout<<"Inorder traversal "<<endl;
inorder(root);
cout<<endl;
bool found = AVLsearch(root, 66);
bool find=AVLsearch(root, 22);
bool search=AVLsearch(root, 44);
    if (found)
        cout << "value found";
    else
        cout << "value not found";
  cout<<endl;
  if(find)
  cout<<"22 : founded ";
  else
  cout<<" 22: Value Not found ";
  cout<<endl;
if(search)
cout<<"44: element founded ";
else
cout<<"44: value not founded ";
    return 0;
return 0;
}
