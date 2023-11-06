// header file for BST

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BST {
    private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;

    TreeNode* insert(TreeNode *, int); // inserts node
    int search(TreeNode *, int); // searches for value
    TreeNode* predecessor(TreeNode *, TreeNode *, int); // finds predecessor value
    TreeNode* successor(TreeNode *, TreeNode *, int); // finds successor value
    int height(TreeNode *); // finds height
    int totalNodes(TreeNode *); // finds total nodes
    TreeNode* deleteLeaf(TreeNode *, TreeNode *, int); // deletes leaf node
    void inorder(TreeNode *); // inorder traversal
    void preorder(TreeNode *); // preorder traversal
    void postorder(TreeNode *); // postorder traversal
    int isBalanced(TreeNode *); // checks if tree is balanced
    TreeNode* destructor(TreeNode *); // destroys all nodes

    public:
    BST() // constructor
    {
        root = nullptr;
    }

    ~BST() // destructor
    {
        destructor(root);
    }
    // public functions to access private functions
    void insertNode(int); 
    void searchFor(int);
    void findPredecessor(int);
    void findSuccessor(int);
    void getHeight();
    void getTotal();
    void balanced();
    void deleteNode(int);
    void destroy();
    void inorderDisplay(); 
    void preorderDisplay();
    void postorderDisplay(); 
};

#endif