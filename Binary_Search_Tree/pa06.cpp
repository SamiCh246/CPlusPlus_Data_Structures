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
  tree2.insert(51);
  tree2.insert(71);
  tree2.insert(61);
  tree2.insert(31);
  tree2.insert(21);
  tree2.insert(27);
  tree2.insert(39);
  tree2.insert(23);
  tree2.insert(51);
  tree2.insert(27);
  tree2.insert(7);
  tree2.insert(53);

  cout << "Only evens (on a new tree):" << endl;
  cout << hardcodedTree.onlyEvens() << " " << tree.onlyEvens() << " "
       << tree2.onlyEvens() << endl;
}

int main() {
  runTest();

  return 0;
}
