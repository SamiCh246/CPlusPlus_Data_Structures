#include "IntArrayLS.h"
#include "IntLinkedListLS.h"
#include <iostream>
using namespace std;

void testArrayLS() {
  cout << "================= testArrayLS =================" << endl;
  cout << "-----" << endl;
  IntArrayLS arr(3);
  arr.addToStart(1);
  arr.addToStart(2);
  arr.addToStart(3);
  arr.addToStart(4);
  arr.addToStart(5);
  arr.printAll();
  cout << "The last element is: " << arr.get(4) << endl;

  cout << "-----" << endl;
  IntArrayLS arr2(3);
  arr2.addToIndex(1, 0);
  arr2.printAll();
  arr2.addToIndex(99, 2); // invalid index
  cout << "Size is still: " << arr2.getSize() << endl;
  arr2.addToIndex(10, 1);
  arr2.addToIndex(9, 1);
  arr2.addToIndex(8, 1);
  arr2.addToIndex(7, 1);
  arr2.addToIndex(6, 1);
  arr2.addToIndex(5, 1);
  arr2.addToIndex(4, 1);
  arr2.addToIndex(3, 1);
  arr2.addToIndex(2, 1);
  arr2.printAll();

  arr2.addToStart(50);
  arr2.printAll();

  cout << "Removing first element:" << endl;
  cout << "Removed: " << arr2.removeFromStart() << endl;
  arr2.printAll();

  cout << "Removing index 1 twice:" << endl;
  cout << "Removed: " << arr2.removeFromIndex(1) << endl;
  cout << "Removed: " << arr2.removeFromIndex(1) << endl;
  arr2.printAll();

  cout << "Removing index 0:" << endl;
  cout << "Removed: " << arr2.removeFromIndex(0) << endl;
  arr2.printAll();

  cout << "Removing index 5:" << endl;
  cout << "Removed: " << arr2.removeFromIndex(5) << endl;
  arr2.printAll();
}

void testLinkedListLS() {
  	cout << "================= testLinkedListLS =================" << endl;
    cout << "-----" << endl;
    IntLinkedListLS ls;
    ls.addToStart(1);
    ls.addToStart(2);
    ls.addToStart(3);
    ls.addToStart(4);
    ls.addToStart(5);
    ls.printAll();
    cout << "The last element is: " << ls.get(4) << endl;

    cout << "-----" << endl;
    IntLinkedListLS ls2;
    ls2.addToIndex(1, 0);
    ls2.printAll();
    ls2.addToIndex(99, 2); // invalid index
    cout << "Size is still: " << ls2.getSize() << endl;
    ls2.addToIndex(10, 1);
    ls2.addToIndex(9, 1);
    ls2.addToIndex(8, 1);
    ls2.addToIndex(7, 1);
    ls2.addToIndex(6, 1);
    ls2.addToIndex(5, 1);
    ls2.addToIndex(4, 1);
    ls2.addToIndex(3, 1);
    ls2.addToIndex(2, 1);
    ls2.printAll();

    ls2.addToStart(50);
    ls2.printAll();

    cout << "Removing first element:" << endl;
    cout << "Removed: " << ls2.removeFromStart() << endl;
    ls2.printAll();

    cout << "Removing index 1 twice:" << endl;
    cout << "Removed: " << ls2.removeFromIndex(1) << endl;
    cout << "Removed: " << ls2.removeFromIndex(1) << endl;
    ls2.printAll();

    cout << "Removing index 0:" << endl;
    cout << "Removed: " << ls2.removeFromIndex(0) << endl;
    ls2.printAll();

    cout << "Removing index 5:" << endl;
    cout << "Removed: " << ls2.removeFromIndex(5) << endl;
    ls2.printAll();
}

int main() {
  testArrayLS();
  testLinkedListLS();

  return 0;
}