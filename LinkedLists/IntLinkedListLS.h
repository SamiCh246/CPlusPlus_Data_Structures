#ifndef INTLINKEDLISTLS_H
#define INTLINKEDLISTLS_H

#include "IntNode.h"
#include <iostream>
using namespace std;

class IntLinkedListLS {
private:
  int size;
	IntNode* head;

public:
	IntLinkedListLS();
	~IntLinkedListLS();

	void addToStart(int value);
	void addToIndex(int value, int index);

	int removeFromStart();
	int removeFromIndex(int index);

	int getSize();

	int get(int index);

	void printAll();
};

#endif
