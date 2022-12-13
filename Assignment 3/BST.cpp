// Minh Nguyen
// BST.cpp

#include <iostream>
#include "BST.h"
#include <stack>
using namespace std;

BST::BST()
{
  root = nullptr;
}

BST::~BST()
{
  deleteNodes(root);
}

void BST::deleteNodes(BSTNode*& root)
{
  if (root == nullptr){
    return;
  }
  else{
    deleteNodes(root->left);
    deleteNodes(root->right);
    // Case 1:  No child
    if(root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    }
    //Case 2: One child
    else if(root->left == nullptr) {
      BSTNode* temp = root;
      root = root->right;
      delete temp;
    }
    else if(root->right == nullptr) {
      BSTNode* temp = root;
      root = root->left;
      delete temp;
    }
    // case 3: 2 children
    else {
      BSTNode* temp = minVal(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,temp->key);
    }
  }
}

void BST::deleteNodesHelper()
{
  deleteNodes(root);
}

void BST::copyHelper(BSTNode* copyTree, BSTNode* node)
{
  if(node == nullptr){
    return;
  }
  else{
    copyTree = new BSTNode;
    copyTree->key = node->key;
    copyHelper(copyTree->left, node->left);
    copyHelper(copyTree->right, node->right);
  }
}

BST::BST(const BST& orig):root{nullptr}
{
  copyHelper(this->root, orig.root);
}

BST& BST::operator=(const BST& orig)
{
  if(this!=& orig){
    deleteNodes(root);
    copyHelper(this->root, orig.root);
  }
  return *this;
}
  
void BST::insertHelper(BSTNode*& node, int num)
{
  if(node == nullptr){
    node = new BSTNode();
    node->key = num;
    node->left = nullptr;
    node->right = nullptr;
  }
  else if (node->key > num){
    insertHelper(node->left, num);
  }
  else if(node->key < num){
    insertHelper(node->right, num);
  }
}

void BST::insertValue(int num)
{
  insertHelper(root, num);
}

void BST::postOrder(BSTNode* node)
{
  if(node!=nullptr){
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << ' ';
  }
}

void BST::postOrderHelper()
{
  postOrder(root);
}

void BST::preOrder(BSTNode* root)
{
  if( root != nullptr){
    cout << root->key << ' ';
    preOrder(root->left);
    preOrder(root->right);
  }
}

void BST::preOrderHelper()
{
  preOrder(root);
}

void BST::inOrder(BSTNode* root)
{
  stack <BSTNode*> t;
  BSTNode* index = root;
  while(index!= nullptr || !t.empty()){
    if(index != nullptr){
      t.push(index);
      index = index->left;
    }
    else{
      index = t.top();
      t.pop();
      cout << index->key << ' ';
      index = index->right;
    }
  }
}

void BST::inOrderHelper()
{
  inOrder(root);
}

int BST::getHeight(BSTNode* node)
{
  if(node == nullptr){
    return 0;
  }
  else{
    int ldepth = getHeight(node->left);
    int rdepth = getHeight(node->right);
    if(ldepth > rdepth){
      return(ldepth + 1);
    }
    else{
      return(rdepth + 1);
    }
  }
}

int BST::heightHelper()
{
  int height = getHeight(this->root);
  return height;
}

struct BST::BSTNode* BST::minVal(BSTNode* root)
{
  while(root->left != nullptr)
    root = root->left;
  return root;
}

struct BST::BSTNode* BST::find(BSTNode* root, int num) {
  if(root == nullptr)
    return nullptr;
  else if(root->key == num)
    return root;
  else if(root->key < num)
    return find(root->right, num);
  else
    return find(root->left, num);
}

struct BST::BSTNode* BST::getSuccessor(BSTNode* node, int num)
{
  BSTNode* curr = find(root, num);
  if(curr == nullptr)
    return nullptr;
  if(curr->right != nullptr){
    return minVal(curr->right);
  }else{
    BSTNode* succ = NULL;
    BSTNode* ancestor = root;
    while(ancestor != curr) {
      if(curr->key < ancestor->key) {
        succ = ancestor;
        ancestor = ancestor->left;
      }
      else
        ancestor = ancestor->right;
    }
    return succ;
  }
}

int BST::successorHelper(int num)
{
  BSTNode* succ;
  succ = getSuccessor(root, num);
  return succ->key;
}

int BST::findKey(BSTNode* root, int num)
{
  if(root->key == num)
    return 1;
  else if(root->key >= num)
    {
      if(root->left == nullptr)
        return -1;
      else
        return findKey(root->left, num);
    }
  else
    {
      if(root->right == nullptr)
        return -1;
      else
        return findKey(root->right, num);
    }
}

int BST::findKeyHelper(int num)
{
  return findKey(root, num);
}

void BST::findMax(BSTNode* root, BSTNode*& pre)
{
  while (root->right) {
    root = root->right;
  }
  pre = root;
}

void BST::findPredecessor(BSTNode* root, BSTNode*& pre, int target)
{
  if (root == nullptr){
    pre = nullptr;
    return;
  }
  if (root->key == target){
    if (root->left) {
      findMax(root->left, pre);
    }
  }else if (target < root->key) {
    findPredecessor(root->left, pre, target);
  }else {
    pre = root;
    findPredecessor(root->right, pre, target);
  }
}

int BST::printPredecessor(int num)
{
  BSTNode* pre = nullptr;
  findPredecessor(root, pre, num);
  return pre->key;
}

int BST::nodes(BSTNode* root){
  if(root == nullptr){
    return 0;
  }else{
    return 1 + nodes(root->left) + nodes(root->right);
  }
}

int BST::nodesHelper()
{
  return nodes(root);
}
/*
struct BST::BSTNode* BST::deleteNode(BSTNode* root, int num)
{
  if (root == nullptr)
    return root;
  if (num < root->key)
    root->left = deleteNode(root->left, num);
  else if (num > root->key)
    root->right = deleteNode(root->right, num);
  else {
    if (root->left == nullptr && root->right == nullptr)
      return nullptr;
    else if (root->left == nullptr) {
      BSTNode* temp = root->right;
      free(root);
    }
    else if (root->right == nullptr) {
      BSTNode* temp = root->left;
      free(root);
    }
    BSTNode* temp;
    minVal(root->right, temp);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
}
*/
struct BST::BSTNode* BST::deleteNode(BSTNode* root, int num)
{
  if(root == nullptr)
    return root; 
  else if(num < root->key)
    root->left = deleteNode(root->left, num);
  else if(num > root->key)
    root->right = deleteNode(root->right, num);
  else {
    // Case 1:  No child
    if(root->left == nullptr && root->right == nullptr) { 
      delete root;
      root = nullptr;
    }
    //Case 2: One child 
    else if(root->left == nullptr) {
      BSTNode* temp = root;
      root = root->right;
      delete temp;
    }
    else if(root->right == nullptr) {
      BSTNode* temp = root;
      root = root->left;
      delete temp;
    }
    // case 3: 2 children
    else { 
      BSTNode* temp = minVal(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,temp->key);
    }
  }
  return root;
}

void BST::deleteNodeHelper(int num)
{
  deleteNode(root, num);
}

bool BST::balanced(BSTNode* root)
{
  int lh;
  int rh;

  if (root == nullptr)
    return 1;

  lh = getHeight(root->left);
  rh = getHeight(root->right);

  if (abs(lh - rh) <= 1 && balanced(root->left) && balanced(root->right))
    return 1;

  return 0;
}

bool BST::balancedHelper()
{
  return balanced(root);
}
