// Minh Nguyen
// BST.h

#ifndef BST_H
#define BST_H
#include <stack>
using namespace std;

class BST {
public:
  BST();
  ~BST();
  BST& operator=(const BST& obj);
  BST(const BST&);
  void insertValue(int num);
  int findKeyHelper(int num);
  void postOrderHelper();
  void inOrderHelper();
  void preOrderHelper();
  int heightHelper();
  int successorHelper(int num);
  int printPredecessor(int num);
  int nodesHelper();
  void deleteNodeHelper(int num);
  void deleteNodesHelper();
  bool balancedHelper();
private:
  struct BSTNode
  {
    int key;
    BSTNode* left;
    BSTNode* right;
  };
  BSTNode* root;
  void insertHelper(BSTNode*& node, int num);
  void deleteNodes(BSTNode*& node);
  void postOrder(BSTNode* node);
  void preOrder(BSTNode* node);
  void inOrder(BSTNode* node);
  void copyHelper(BSTNode* copyTree, BSTNode* node);
  BSTNode* getSuccessor(BSTNode* node, int num);
  void findPredecessor(BSTNode* node, BSTNode*& pre, int target);
  int getHeight(BSTNode* node);
  int findKey(BSTNode* node, int num);
  void findMax(BSTNode* root, BSTNode*& pre);
  int nodes(BSTNode* root);
  BSTNode* deleteNode(BSTNode* root, int num);
  BSTNode* minVal(BSTNode* root);
  BSTNode* find(BSTNode* root, int num);
  bool balanced(BSTNode* root);
};
#endif
