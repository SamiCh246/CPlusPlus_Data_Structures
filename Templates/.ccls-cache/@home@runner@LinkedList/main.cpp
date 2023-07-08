//#include "LinkedList.h"
// #include "HashMap.h"
#include "Dog.h"
#include <string>
#include <iostream>
using namespace std;

/*
void testHM1() {
	cout << "================= testHashMap1 =================" << endl;
	cout << "-----" << endl;

	HashMap<int> hm(2); // small capacity so its easier to test collisions
	hm.put("a", 5);    // 1
	hm.put("b", 6);    // 0
	hm.put("c", 7);    // 1
	hm.put("d", 8);    // 0
	hm.put("e", 9);    // 1
	hm.put("f", 10);   // 0
	hm.put("g", 11);   // 1

	hm.printStructure();

	cout << "a is mapped to: " << hm.get("a") << endl;
	cout << "b is mapped to: " << hm.get("b") << endl;
	cout << "c is mapped to: " << hm.get("c") << endl;
	cout << "d is mapped to: " << hm.get("d") << endl;
	cout << "e is mapped to: " << hm.get("e") << endl;
	cout << "f is mapped to: " << hm.get("f") << endl;
	cout << "g is mapped to: " << hm.get("g") << endl;

	hm.remove("d");
	cout << "d removed" << endl;
	hm.printStructure();

	hm.remove("f");
	hm.remove("b");
	cout << "f and b removed" << endl;
	hm.printStructure();

	hm.put("h", 12);   // 0
	cout << "h added" << endl;
	hm.printStructure();
}

void testHM2() {
	cout << "================= testHashMap2 =================" << endl;
	cout << "-----" << endl;

	HashMap<Dog> hm(2); // small capacity so its easier to test collisions
	hm.put("a", Dog("aDog", 1));    // 1
	hm.put("b", Dog("bDog", 2));    // 0
	hm.put("c", Dog("cDog", 3));    // 1
	hm.put("d", Dog("dDog", 4));    // 0
	hm.put("e", Dog("eDog", 5));    // 1
	hm.put("f", Dog("fDog", 6));   // 0
	hm.put("g", Dog("gDog", 7));   // 1

	hm.printStructure();

	cout << "a is mapped to: " << hm.get("a") << endl;
	cout << "b is mapped to: " << hm.get("b") << endl;
	cout << "c is mapped to: " << hm.get("c") << endl;
	cout << "d is mapped to: " << hm.get("d") << endl;
	cout << "e is mapped to: " << hm.get("e") << endl;
	cout << "f is mapped to: " << hm.get("f") << endl;
	cout << "g is mapped to: " << hm.get("g") << endl;

	hm.remove("d");
	cout << "d removed" << endl;
	hm.printStructure();

	hm.remove("f");
	hm.remove("b");
	cout << "f and b removed" << endl;
	hm.printStructure();

	hm.put("h", Dog("hDog", 8));   // 0
	cout << "h added" << endl;
	hm.printStructure();
}
*/

/*
void testLL() {
	cout << "================= testLinkedList =================" << endl;
	cout << "-----" << endl;
	LinkedList<int> ls;
	ls.addToStart(1);
	ls.addToStart(2);
	ls.addToStart(3);
	ls.addToStart(4);
	ls.addToStart(5);
	ls.printAll();
	cout << "The last element is: " << ls.get(4) << endl;

	cout << "-----" << endl;
	LinkedList<string> ls2;
	ls2.addToIndex("a", 0);
	ls2.printAll();
	// ls2.addToIndex("bbb", 2); // invalid index
	cout << "Size is still: " << ls2.getSize() << endl;
	ls2.addToIndex("k", 1);
	ls2.addToIndex("j", 1);
	ls2.addToIndex("i", 1);
	ls2.addToIndex("h", 1);
	ls2.addToIndex("g", 1);
	ls2.addToIndex("f", 1);
	ls2.addToIndex("e", 1);
	ls2.addToIndex("d", 1);
	ls2.addToIndex("c", 1);
	ls2.addToIndex("b", 1);
	ls2.printAll();

	ls2.addToStart("aaaa");
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
*/
	
int main() {
  cout << "Uncomment what you need to in main.cpp to test your code." << endl;
  
	// testLL();

	// testHM1();

	// testHM2();

	return 0;
}

