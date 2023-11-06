// implementation file for BST.h

#include <iostream>
#include "BST.h"
using namespace std;


///////////// PRIVATE FUNCTIONS //////////////

BST::TreeNode* BST::insert(TreeNode * t, int x) // inserts new node
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
    }else if(t->val == x){ // checks for duplicates
        cout << "\nThis value is already in the tree\n" ;
    }else if(x < t->val){ // if new node is to be left child
        t->left = insert(t->left, x);
    }else{ // if new node is to be a right child
        t->right = insert(t->right, x);
    }
    return t;
}

int BST::search(TreeNode* node, int num) // searches tree for value
{   
    if(node == nullptr) // base cases
    return -1;
    if(node->val == num)
    return 1;

    if(num < node->val){ // recursion
        return search(node->left, num);  
    }else{
        return search(node->right, num);  
    }

    return -1;
}

BST::TreeNode* BST::predecessor(TreeNode *node, TreeNode *prev, int num)
 // searches for predecessor
{
    if(root == nullptr) // base case
    return nullptr;

    if(node->val == num){ // predecessor is largest node in left subtree
        TreeNode *temp = nullptr;
        if(node->left != nullptr){
            temp = node->left;
            while(temp->right != nullptr){
                temp = temp->right;
            }
            return temp;
        }
    }else if(node->val < num){ // recursion
        prev = node;
        return predecessor(node->right, prev, num);
    }else{
        return predecessor(node->left, prev, num);
    }
    
    return prev; // returns parent if node is a right child
}

BST::TreeNode* BST::successor(TreeNode *node, TreeNode *prev, int num)
// finds successor for value
{
    if(root == nullptr) // base case
    return nullptr;

    if(node->val == num){ // successor is smallest node in right subtree
        TreeNode *temp = nullptr;
        if(node->right != nullptr){
            temp = node->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            return temp;
        }
    }else if(node->val < num){ // recursion
        return successor(node->right, prev, num);
    }else{
        prev = node;
        return successor(node->left, prev, num);
    }
    
    return prev; // returns parent if node is a left child
}

int BST::height(TreeNode *node) // finds height of tree
{   
    if(!node) // empty tree
    return -1;
    else{
        int left = height(node->left); // finds height of subtrees
        int right = height(node->right);
        
        if(left > right){ // chooses max subtree height
            return left + 1;
        }else{
            return right + 1;
        }
    }

}
int BST::totalNodes(TreeNode *node) // counts total nodes
{
    if(!node) // base case
        return 0;
    else{
        return 1 + totalNodes(node->left) + totalNodes(node->right);
    }

}

BST::TreeNode* BST::deleteLeaf(TreeNode *node, TreeNode *prev, int num)
// deletes leaf node (BE CAREFUL TO NOT DELETE INNER NODES)
{   
    if(root == nullptr){ // base cases
        return nullptr;
    }
    if(node == nullptr){ 
        return nullptr;
    }

    if(root->val == num){ // checks if root is the node to be deleted
        root->left = nullptr;
        root->right = nullptr;
        delete root;
        root = nullptr;
        return nullptr;
    }
    if(node->val == num){ // leaf node found
        if(prev->val > num){ // breaks link between parent and child node
            prev->left = nullptr;
        }else{
            prev->right = nullptr;
        }
        delete node;
        return nullptr;
    }else{ // recursion
        prev = node;
        if(node->val < num){
            return deleteLeaf(node->right, prev, num);
        }else{
            return deleteLeaf(node->left, prev, num);
        }
    }
    return nullptr;
}


void BST::inorder(TreeNode * t) { // inorder traversal
    if(t == nullptr){ // base case
        return;
    }
    inorder(t->left); // left
    cout << t->val << " "; // middle
    inorder(t->right); // right
}

void BST::preorder(TreeNode * t) { // preorder traversal
    if(t == nullptr){ // base case
        return;
    }
    cout << t->val << " "; // middle
    preorder(t->left); // left
    preorder(t->right); // right
}

void BST::postorder(TreeNode * t) { // postorder traversal
    if(t == nullptr){ // base case
        return;
    }
    postorder(t->left); // left
    postorder(t->right); // right
    cout << t->val << " "; // middle
}

int BST::isBalanced(TreeNode *node)
{
    if(node == nullptr) // base case
    return 1;

    int left = height(node->left);
    int right = height(node->right);
    // compares heights of trees and checks if subtrees are also balanced
    if(abs(left - right) <= 1 && isBalanced(node->left) == 1 && isBalanced(node->right) == 1)
    return 1;
    else
    return -1;
}

BST::TreeNode* BST::destructor(TreeNode *node) // destroys all nodes at end
{
    if(node != nullptr){ // searches through tree recursively to delete nodes
        destructor(node->left);
        destructor(node->right);
        delete node;
        node = nullptr;
    }
    root = nullptr;
    return nullptr;
}

///////////// PUBLIC FUNCTIONS //////////////

void BST::insertNode(int x)
{ // inserts a new node
    root = insert(root, x);
}

void BST::searchFor(int num)
{
    if(search(root, num) == 1){
        cout << "\n" << num << " is in the tree\n" ;
    }else{
        cout << "\n" << num << " is not in the tree\n" ;
    }
}

void BST::findPredecessor(int num)
{   
    TreeNode *temp = predecessor(root, nullptr, num);
    if(temp == nullptr){
        if(!root){ // checks why nullptr is returned
            cout << "\nEmpty tree\n" ;
        }else{
            cout << "\nNo predecessor\n" ;
        }
    }
    else{
        cout << "\nPredecessor is " << temp->val << endl;
    }
}

void BST::findSuccessor(int num)
{   
    TreeNode *temp = successor(root, nullptr, num);
    if(temp == nullptr){ // checks why temp is null
        if(!root){
            cout << "\nEmpty tree\n" ;
        }else{
            cout << "\nNo successor\n" ;
        }
    }
    else{
        cout << "\nSuccessor is " << temp->val << endl;
    }
}

void BST::getHeight()
{
    cout << "\nHeight is " << height(root) << endl;
}

void BST::getTotal()
{
    cout << "\nThe total number of nodes is " << totalNodes(root) << endl;
}

void BST::balanced()
{
    if(isBalanced(root) == 1){
        cout << "\nThe tree is balanced\n" ;
    }else{
        cout << "\nThe tree is not balanced\n" ;
    }
}

void BST::deleteNode(int num)
{
    deleteLeaf(root, nullptr, num);
}

void BST::destroy()
{
    destructor(root);
}

void BST::inorderDisplay()
{ // prints inorder traversal
    cout << endl;
    inorder(root);
    cout << endl;
}

void BST::preorderDisplay()
{ // prints preorder traversal
    cout << endl;
    preorder(root);
    cout << endl;
}

void BST::postorderDisplay()
{ // prints postorder traversal
    cout << endl;
    postorder(root);
    cout << endl;
}