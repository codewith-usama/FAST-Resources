
// CPP program to print smallest element 
// in each level of binary tree. 
#include <iostream> 
#include <vector> 
#define INT_MAX 10e6 
using namespace std; 



  
// A Binary Tree Node 
class Node { 
    public:
    int data; 
    Node *left, *right; 
}; 
  
// return height of tree 
int heightoftree(Node* root) 
{ 
  
    if (root == NULL) 
        return 0; 
  
    int left = heightoftree(root->left); 
    int right = heightoftree(root->right); 
  
    return ((left > right ? left : right) + 1); 
} 

void printPerLevelMaximum(Node* root,  
                  vector<int>& res, int level);
  
// Inorder Traversal 
// Search minimum element in each level and  
// store it into vector array. 
void printPerLevelMinimum(Node* root,  
                  vector<int>& res, int level) 
{ 
      
    if (root != NULL) { 
  
        printPerLevelMinimum(root->left, 
                              res, level + 1); 
  
        if (root->data < res[level]) 
            res[level] = root->data; 
  
        printPerLevelMinimum(root->right,  
                              res, level + 1); 
    } 
} 
  
void perLevelMinimumUtility(Node* root) 
{ 
      
    // height of tree for the size of  
    // vector array 
    int n = heightoftree(root), i; 
  
    // vector for store all minimum of  
    // every level 
    vector<int> res(n, INT_MAX); 
  
    // save every level minimum using  
    // inorder traversal 
    printPerLevelMinimum(root, res, 0); 
  
    // print every level minimum 
    // cout << "Every level minimum is "; 
    // for (i = 0; i < n; i++) { 
    //     // cout << "level " << i <<" min is = "
    //     cout<< res[i] << " "; 
    // } 


        int m = heightoftree(root), j; 
  
    // vector for store all minimum of  
    // every level 
    vector<int> ress(m, -10000); 
  
    // save every level minimum using  
    // inorder traversal 
    printPerLevelMaximum(root, ress, 0); 
  
    // print every level minimum 
    // cout << "Every level minimum is "; 
    for (i = 0; i < m; i++) { 
        // cout << "level " << i <<" min is = "
        cout<<res[i]<<" "<< ress[i] << endl; 
    } 
} 





///////////////////////////////////////////////////


void printPerLevelMaximum(Node* root,  
                  vector<int>& res, int level) 
{ 
      
    if (root != NULL) { 
  
        printPerLevelMaximum(root->left, 
                              res, level + 1); 
  
        if (root->data > res[level]) 
            res[level] = root->data; 
  
        printPerLevelMaximum(root->right,  
                              res, level + 1); 
    } 
} 

Node* insert(Node* n, int val) {
    if( n== NULL) {
        n = new Node;
        n->data = val;

        n->left = n->right = NULL;
    }


    else if(val < n->data) {
        n->left = insert(n->left, val);
    }

    else if(val > n->data) {
        n->right = insert(n->right, val);
    }

    return n;
}
  
Node* newNode(int data) 
{ 
    Node* temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
  
    // Let us create binary tree shown  
    // in above diagram 
    Node* root = newNode(34); 
    root = insert(root,29); 
    root = insert(root,65); 
    root = insert(root,21); 
    root = insert(root,31); 
    root = insert(root,43); 
    root = insert(root,87);
    root = insert(root,28);
    root = insert(root,30);
    root = insert(root,56); 
  
    /*       7 
         /  
        6     5 
       /      / 
      4   3 2   1         */
    // perLevelMaximumUtility(root);
    // cout<<endl;
    perLevelMinimumUtility(root); 
  
    return 0; 
} 
