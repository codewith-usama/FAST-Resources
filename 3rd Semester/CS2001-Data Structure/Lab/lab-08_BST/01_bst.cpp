#include<iostream>
#include<list>
#include<queue>
using namespace std;

class BST{
    public:
        int data;
        BST *left, *right;

    BST(){left=right=NULL;}

    BST(int data) {
        this->data = data;
        left= NULL;
        right= NULL;
    }
};

BST* __insert(int v, BST* root) {
    if(root == NULL) {
        BST* n = new BST(v);
        return n;
    }

    else if(v>root->data) {
        root->right = __insert(v, root->right);
    }

    else if(v<root->data) {
        root->left = __insert(v, root->left);
    }
    return root;
}



void __inorder(BST* root) {
    if(root==NULL) return;
    __inorder(root->left);
    cout<<root->data<<" ";
    __inorder(root->right);
}


bool __search(int v, BST* root) {
    if(root == NULL) return false;

    else if(v < root->data) {
        return __search(v, root->left);
    }

    else if(v > root->data) {
        return __search(v, root->right);
    
    }
    else
        return true;
}


int __min(BST* root) {
    if(root == NULL) return 0;

    else if(root->left == NULL){
        return root->data;
    }
    else
    return __min(root->left);
}


// int height(BST* node);
// void printCurrentLevel(BST* root, int level);


// void printLevelOrder(BST* root)
// {
//     int h = height(root);
//     int i;
//     for (i = 1; i <= h; i++)
//         printCurrentLevel(root, i);
// }
 
// /* Print nodes at a current level */
// void printCurrentLevel(BST* root, int level)
// {
//     if (root == NULL)
//         return;
//     if (level == 1)
//         cout << root->data << " ";
//     else if (level > 1) {
//         printCurrentLevel(root->left, level - 1);
//         printCurrentLevel(root->right, level - 1);
//     }
// }
 
// /* Compute the "height" of a tree -- the number of
//     nodes along the longest path from the root node
//     down to the farthest leaf node.*/
// int height(BST* node)
// {
//     if (node == NULL)
//         return 0;
//     else {
//         /* compute the height of each subtree */
//         int lheight = height(node->left);
//         int rheight = height(node->right);
 
//         /* use the larger one */
//         if (lheight > rheight) {
//             return (lheight + 1);
//         }
//         else {
//             return (rheight + 1);
//         }
//     }
// }

int __height(BST* root);
void __currentLevel(BST* root, int level);

void __BFS(BST *root) {
    int h = __height(root);
    
    for (int i = 1; i <= h; i++)
    {
        __currentLevel(root, i);
    }
    
}


void __currentLevel(BST* root, int level) {
    if(root == NULL ) {
        return ;
    }
    if(level == 1) {
        cout<<root->data<<" ";
    }
    else if(level > 1) {
        __currentLevel(root->left, level-1);
        __currentLevel(root->right, level-1);
    }
}


int __height(BST* root) {
    if(root == NULL) {
        return 0;
    }
    else {
        int __lefth = __height(root->left);
        int __righth = __height(root->right);

        if(__lefth > __righth){
            return __lefth+1;
        }
        else {
            return __righth+1;
        }
    }
}


void __queuelevel(BST* root) {
    if(root == NULL) {
        return;
    }

    queue<BST*> q;
    q.push(root);

    while(!q.empty()) {
        BST *n = q.front();
        cout<<n->data<<" ";
        q.pop();

        if(n->left!= NULL) {
            q.push(n->left);
        }

        if(n->right != NULL) {
            q.push(n->right);
        }
    }
}



bool __isBST(BST* root) {
    if(root == NULL) {
        return true;
    }

    if(root->left != NULL && root->left->data > root->data) {
        return false;
    }

    if(root->right != NULL && root->right->data < root->data) {
        return false;
    }

    if(!__isBST(root->left) || !__isBST(root->right)){
        return false;
    }
    else
    return true;
}



int main() {
    BST *root;
    root = __insert(100, root);
    root = __insert(200, root);
    root = __insert(-100, root);
    // root = __insert(20, root);

    __inorder(root);

    // cout<<__search(10, root);
    cout<<endl;
    // cout<<__min(root)<<endl;
    // __search(100, root);
    // __BFS(root);
    // __queuelevel(root);

    cout<<__isBST(root)<<endl;
    return 0;
}