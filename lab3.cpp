// Kevin Bui
// lab3.cpp
// 5/6/22
// Purpose: To build a binary tree and print out inorder, 
// preorder, and postorder traversal
// Input: integers to build the tree
// Processing: recursion, linked lists, traversal
// Output: prints tree in inorder, preorder, and postorder traversal

#include <iostream>

using namespace std;

class BST {
    private:    
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;

// For this lab, you do not need to consider the situation when inserting the same values.
// Only insert different values when you test your program in the main function.

    TreeNode* insert(TreeNode * t, int x) 
    {
        if(t == nullptr){ // if spot is empty, create new node
            TreeNode *newNode = new TreeNode;
            newNode->val = x;
            newNode->left = nullptr;
            newNode->right = nullptr;
            if(root == nullptr){ // stores first node as root
                root = newNode;
                return root;
            }
            return newNode;
        }
        else if(x < t->val){ // if new node is to be left child
            t->left = insert(t->left, x);
        }else{ // if new node is to be a right child
            t->right = insert(t->right, x);
        }
        return t;
    }
    void inorder(TreeNode * t) { // inorder traversal
        // add your code here
        // ...
        if(t == nullptr){ // base case
            return;
        }
        inorder(t->left); // left
        cout << t->val << " "; // middle
        inorder(t->right); // right
    }

    void preorder(TreeNode * t) { // preorder traversal
        // add your code here
        // ...
        if(t == nullptr){ // base case
            return;
        }
        cout << t->val << " "; // middle
        preorder(t->left); // left
        preorder(t->right); // right
    }

    void postorder(TreeNode * t) { // postorder traversal
        // add your code here
        // ...
        if(t == nullptr){ // base case
            return;
        }
        postorder(t->left); // left
        postorder(t->right); // right
        cout << t->val << " "; // middle
    }

    public:
        BST() { // constructor
            root = nullptr;
        }

        ~BST() // destructor
        {
            destructor(root);
        }

        void destructor(TreeNode *node) // destroys all nodes at end
        {
            if(node != nullptr){
                destructor(node->left);
                destructor(node->right);
                delete node;
            }
        }

        void insertNode(int x){ // inserts a new node
            root = insert(root, x);
        }

        void inorderDisplay(){ // prints inorder traversal
            inorder(root);
        }

        void preorderDisplay(){ // prints preorder traversal
            preorder(root);
        }

        void postorderDisplay(){ // prints postorder traversal
            postorder(root);
        }
};

// in your main function, test your implementations. For example,  

int main() 
{
    BST t;
    t.insertNode (10);
    t.insertNode (7);
    t.insertNode (29);
    t.insertNode (30);
    t.insertNode (9);
    // inorder display
    t.inorderDisplay();  // the output should be: 7, 9, 10, 29, 30
    cout << endl;
    // preorder display
    t.preorderDisplay();  // the output should be: 10, 7, 9, 29, 30
    cout << endl;
    // postorder display
    t.postorderDisplay();  // the output should be: 9, 7, 30, 29, 10
    cout << endl;

    return 0; 
}