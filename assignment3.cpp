// Kevin Bui
// assignment3.cpp
// 5/16/22
// Purpose: To use recursion to create a binary search tree and find data
// Input: user inputs menu choice and input
// Processing: recursion, linked lists, switch case, BSTs
// Output: creating and displaying data about binary search trees

#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST t;
    int choice = 1, input = 0;

    while (choice != 0) {
        cout << "Please select an operation to test:\n" << endl;
        cout << "1. Insert a node" << endl
        << "2. Search for a value" << endl
        << "3. Find predecessor for an existing value" << endl
        << "4. Find successor for an existing value" << endl
        << "5. Find height of tree" << endl
        << "6. Find total number of nodes in tree" << endl
        << "7. Delete a node" << endl
        << "8. Traverse inorder and display" << endl
        << "9. Traverse preorder and display" << endl
        << "10. Traverse postorder and display" << endl
        << "11. Check if tree is balanced" << endl
        << "12. Destroy tree" << endl
        << "0. Quit" << endl << endl;

        cin >> choice;

        switch(choice){
            case 1:
                cout << "\nPlease choose a value to insert into the tree: ";
                cin >> input;
                t.insertNode(input);
                break;
            case 2:
                cout << "\nPlease input a value to search for: ";
                cin >> input;
                t.searchFor(input);
                break;
            case 3:
                cout << "\nPlease input an existing value: ";
                cin >> input;
                t.findPredecessor(input);
                break;
            case 4:
                cout << "\nPlease input an existing value: ";
                cin >> input;
                t.findSuccessor(input);
                break;
            case 5:

                t.getHeight();
                break;
            case 6:
                t.getTotal();
                break;
            case 7:
                cout << "\nPlease input a leaf node to delete: ";
                cin >> input;
                t.deleteNode(input);
                break;
            case 8:
                cout << "\nThe inorder traversal is: ";
                t.inorderDisplay();
                break;
            case 9:
                cout << "\nThe preorder traversal is: ";
                t.preorderDisplay();
                break;
            case 10:
                cout << "\nThe postorder traversal is: ";
                t.postorderDisplay();
                break;
            case 11:
            t.balanced();
                break;
            case 12:
                t.destroy();
                cout << "\nThe tree has been deleted\n" ;
                break;
            case 0:
                break;    
            default:
                cout <<"\nInvalid input, please try again\n\n";
        }
    }

    return 0;
}