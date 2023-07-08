#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "IntBTNode.h"
#include <iostream>
using namespace std;

class BinarySearchTree {
  public:
    BinarySearchTree();
    ~BinarySearchTree();
    void makeHardcodedTree();
    void print();
    void printInOrder();
    void insert(int value);
    bool contains(int value);
    bool onlyEvens();

  private:
    IntBTNode *root;
    void destructorHelper(IntBTNode *curr);
    void printSpaces(int numSpaces);
    void printHelper(IntBTNode *curr, int depth, char header);
    void printInOrderHelper(IntBTNode *curr);
    void insertHelper(IntBTNode *&curr, int value);
    bool containsHelper(IntBTNode *curr, int value);
    bool onlyEvensHelper(IntBTNode *curr);
};

#endif
