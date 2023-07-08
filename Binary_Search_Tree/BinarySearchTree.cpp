#include <iostream>
using namespace std;
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
  root = NULL;
}

void BinarySearchTree::makeHardcodedTree() {
  // ------------------------------------------
  // root
  root = new IntBTNode();
  root->data = 20;
  root->left = NULL;
  root->right = NULL;

  // ------------------------------------------
  // Children of root
  IntBTNode *leftOfRoot = new IntBTNode();
  leftOfRoot->data = 15;
  leftOfRoot->left = NULL;
  leftOfRoot->right = NULL;

  IntBTNode *rightOfRoot = new IntBTNode();
  rightOfRoot->data = 27;
  rightOfRoot->left = NULL;
  rightOfRoot->right = NULL;

  root->left = leftOfRoot;
  root->right = rightOfRoot;

  // ------------------------------------------
  // Children of root's left child
  IntBTNode *leftOfLeft = new IntBTNode();
  leftOfLeft->data = 12;
  leftOfLeft->left = NULL;
  leftOfLeft->right = NULL;

  IntBTNode *rightOfLeft = NULL; // no node here

  leftOfRoot->left = leftOfLeft;
  leftOfRoot->right = rightOfLeft;

  // ------------------------------------------
  // Children of root's right child
  IntBTNode *leftOfRight = new IntBTNode();
  leftOfRight->data = 23;
  leftOfRight->left = NULL;
  leftOfRight->right = NULL;

  IntBTNode *rightOfRight = new IntBTNode();
  rightOfRight->data = 29;
  rightOfRight->left = NULL;
  rightOfRight->right = NULL;

  rightOfRoot->left = leftOfRight;
  rightOfRoot->right = rightOfRight;

  // ------------------------------------------
  // One more child - a great grandchild of the root

  IntBTNode *last = new IntBTNode();
  last->data = 28;
  last->left = NULL;
  last->right = NULL;

  rightOfRight->left = last;
}

void BinarySearchTree::destructorHelper(IntBTNode *curr) {
  if (curr != NULL) {
    IntBTNode *left = curr->left;
    IntBTNode *right = curr->right;
    delete curr;
    destructorHelper(left);
    destructorHelper(right);
  }
}

BinarySearchTree::~BinarySearchTree() {
  destructorHelper(root);
}

void BinarySearchTree::printSpaces(int numSpaces) {
  for (int i = 0; i < numSpaces; i++)
    cout << " ";
}

void BinarySearchTree::printHelper(IntBTNode *curr, int depth, char header) {
  if (curr != NULL) {
    printSpaces(depth * 4);
    if (curr != root)
      cout << header << ": ";

    cout << curr->data << endl;
    printHelper(curr->left, depth + 1, 'L');
    printHelper(curr->right, depth + 1, 'R');
  }
}

void BinarySearchTree::print() {
  printHelper(root, 0, ' ');
}

void BinarySearchTree::printInOrderHelper(IntBTNode *curr){
  if (curr != NULL) {
    printInOrderHelper(curr->left);
    cout << curr->data << " ";
    printInOrderHelper(curr->right);
  }
}

void BinarySearchTree::printInOrder() {
  printInOrderHelper(root);
  cout << endl;
}

void BinarySearchTree::insertHelper(IntBTNode *&curr, int value) {
  if (curr == NULL) {
    curr = new IntBTNode();
    curr->data = value;
    curr->left = NULL;
    curr->right = NULL;
  } else if (value < curr->data) {
    insertHelper(curr->left, value);
  } else {
    insertHelper(curr->right, value);
  }
}

void BinarySearchTree::insert(int value) {
  insertHelper(root, value);
}

bool BinarySearchTree::contains(int value) {
    return containsHelper(root, value);
}

bool BinarySearchTree::containsHelper(IntBTNode *curr, int value) {
    if (curr == nullptr) {
        return false;
    }
    if (curr->data == value) {
        return true;
    }
    if (value < curr->data) {
        return containsHelper(curr->left, value);
    } else {
        return containsHelper(curr->right, value);
    }
}

bool BinarySearchTree::onlyEvens() {
    return onlyEvensHelper(root);
}

bool BinarySearchTree::onlyEvensHelper(IntBTNode *curr) {
    if (curr == nullptr) {
        return true;
    }
    if (curr->data % 2 == 1) {
        return false;
    }
    return onlyEvensHelper(curr->left) && onlyEvensHelper(curr->right);
}
/////////////////////////////////////////