#include <iostream>
using namespace std;

#include "BinarySearchTree.h"

void runTest() {
  BinarySearchTree hardcodedTree;

  hardcodedTree.makeHardcodedTree();
  cout << "Hardcoded tree:" << endl;
  hardcodedTree.printInOrder();
  hardcodedTree.print();

  cout << "Tree with insert:" << endl;
  BinarySearchTree tree;
  tree.insert(50);
  tree.insert(70);
  tree.insert(60);
  tree.insert(30);
  tree.insert(25);
  tree.insert(27);
  tree.insert(29);
  tree.insert(28);
  tree.insert(55);
  tree.insert(26);
  tree.insert(75);
  tree.insert(58);

  tree.printInOrder();
  tree.print();

  cout << "Contains:" << endl;
  cout << tree.contains(50) << " " << tree.contains(60) << " "
       << tree.contains(40) << endl;

  BinarySearchTree tree2;
  tree2.insert(50);
  tree2.insert(70);
  tree2.insert(60);
  tree2.insert(30);
  tree2.insert(24);
  tree2.insert(28);
  tree2.insert(30);
  tree2.insert(28);
  tree2.insert(56);
  tree2.insert(26);
  tree2.insert(74);
  tree2.insert(58);

  cout << "Only evens (on a new tree):" << endl;
  cout << hardcodedTree.onlyEvens() << " " << tree.onlyEvens() << " "
       << tree2.onlyEvens() << endl;
}

int main() {
  runTest();

  return 0;
}
