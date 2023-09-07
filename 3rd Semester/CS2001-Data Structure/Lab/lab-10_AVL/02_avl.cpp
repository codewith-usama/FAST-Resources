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
 

Node *rightRotate(Node *y)
{
    Node *x = y->left;       // root left
    Node *T2 = x->right;     // root ke left ke right


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
 

 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 



// Search

bool avlSearch( Node *root, int key)
{
    if (root == NULL)
        return false;
      else if (root->key == key)
        return true;

    else if (root->key > key) {
        bool val = avlSearch(root->left, key);
        return val;
    }

    else {
        bool val = avlSearch(root->right, key);
        return val;
    }
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

// Inorder traversal

void InOrder(Node *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout << root->key << " ";
        InOrder(root->right);
    }
}


// PostOrder Traversal

void PostOrder(Node *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        InOrder(root->right);
        cout << root->key << " ";
    }
}
int main()
{
    Node *root = NULL;
//     as { 55, 66, 77, 11, 33, 22, 35, 25, 44, 88,99},

    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 33);
    root = insert(root, 22);
    root = insert(root, 35);
    root = insert(root, 25);
    root = insert(root, 44);
    root = insert(root, 8);
    root = insert(root, 9);
     
    cout<<"Height of the Tree: "<<height(root)<<endl;
    cout<<endl;

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
    
    //
    cout<<"\n"<<endl;
    
    cout << "InOrder traversal of the "
            "constructed AVL tree is \n";
    InOrder(root);
    
    // 
    cout<<"\n"<<endl;
    
    cout << "PostOrder traversal of the "
            "constructed AVL tree is \n";
    PostOrder(root);
    cout<<endl;

    cout<<"Searching Element: "<<endl;
    cout<<avlSearch(root, 32)<<" Value not found"<<endl;                                //returns true of false boolean value
    cout<<avlSearch(root, 22)<<" Value found"<<endl; 
    return 0;
}