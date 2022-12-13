// assingment.cpp
/*
** Minh Nguyen
** Binary Search Tree Basic Operations Implementation
** Assignment 3, BST.cpp, CPSC 2430-02
** Xin Zhao
*/

#include <iostream>
#include "BST.h"
#include <stack>
using namespace std;

const int QUIT = 0; // const value for menu
const int INSERT = 1; // const value for menu
const int SEARCH = 2; // const value for menu
const int SUCCESSOR = 3; // const value for menu
const int PREDECESSOR = 4; // const value for menu
const int HEIGHT = 5; // const value for menu
const int NODES = 6; // const value for menu
const int DELETE = 7; // const value for menu
const int INORDER = 8; // const value for menu
const int PREORDER = 9; // const value for menu
const int POSTORDER = 10; // const value for menu
const int BALANCE = 11; // const value for menu
const int DESTROY = 12; // const value for menu
const char YES = 'y';
const char NO = 'n';

int main(){
  int menuChoice = -1;
  char ans = 'y';
  int value = 0;
  int found;
  BST Tree;
  int temp;
  
  while (menuChoice != QUIT){
    menuChoice = -1;
    // menu prompt
    while (menuChoice < QUIT || menuChoice > DESTROY){
      cout << endl;
      cout << "Menu" << endl;
      cout << QUIT << ". Quit" << endl;
      cout << INSERT << ". Insert a value" << endl;
      cout << SEARCH << ". Search for a value" << endl;
      cout << SUCCESSOR << ". Find successor" << endl;
      cout << PREDECESSOR << ". Find predecessor" << endl;
      cout << HEIGHT << ". Find height of the tree" << endl;
      cout << NODES << ". Find number of nodes in tree" << endl;
      cout << DELETE << ". Delete node based on value" << endl;
      cout << INORDER << ". Inorder traversal" << endl;
      cout << PREORDER << ". Preorder traversal" << endl;
      cout << POSTORDER << ". Postorder traversal" << endl;
      cout << BALANCE << ". Balance check" << endl;
      cout << DESTROY << ". return nullptr after tree is destroyed" << endl;
      cout << "Choose the number that corresponds with your choice. Choice? ";
      cin >> menuChoice;
      cin.get();
      cout << endl;
    }
    
    if (menuChoice == QUIT){
      return 0;
    }
    
    if (menuChoice == INSERT){
      while (ans == YES){
        cout << "Input value: ";
        cin >> value;
        Tree.insertValue(value);
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }

    if (menuChoice == SEARCH){
      while (ans == YES){
        found = 0;
        cout << "Value to search: ";
        cin >> value;
        found = Tree.findKeyHelper(value);
        cout << "return " << found << endl;
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }

    if (menuChoice == SUCCESSOR ){
      while (ans == YES){
        cout << "Find successor of value: ";
        cin >> value;
        value = Tree.successorHelper(value);
        cout << "Sucessor is " << value << endl;
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }

    if (menuChoice == PREDECESSOR){
      while (ans == YES){
        cout << "Find predecessor of value: ";
        cin >> value;
        value = Tree.printPredecessor(value);
        cout << "Predecessor is " << value << endl;
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }
    
    if (menuChoice == HEIGHT){
      temp = Tree.heightHelper();
      cout << "Tree height is " << temp << endl;
      menuChoice = -1;
    }
    
    if (menuChoice == NODES){
      temp = Tree.nodesHelper();
      cout << "Number of nodes in BST is " << temp << endl;
      menuChoice = -1;
    }
    
    if (menuChoice == DELETE){
      while (ans == YES){
        cout << "Value of node you want to delete: ";
        cin >> value;
        Tree.deleteNodeHelper(value);
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }
    
    if (menuChoice == INORDER){
      Tree.inOrderHelper();
      menuChoice = -1;
    }
    
    if (menuChoice == PREORDER){
      Tree.preOrderHelper();
      menuChoice = -1;
    }

    if (menuChoice == POSTORDER){
      Tree.postOrderHelper();
      menuChoice = -1;
    }

    if (menuChoice == BALANCE){
      if(Tree.balancedHelper())
        cout << "Tree is balanced" << endl;
      else
        cout << "Tree is not balanced" << endl;
      menuChoice = -1;
    }

    if (menuChoice == DESTROY){
      Tree.deleteNodesHelper();
      menuChoice = -1;
    }
  }
  return 0;
}
