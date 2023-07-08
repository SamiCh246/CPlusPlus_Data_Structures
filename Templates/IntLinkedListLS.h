#ifndef INTLINKEDLISTLS_H
#define INTLINKEDLISTLS_H

#include "IntNode.h"

class IntLinkedListLS {
private:
	IntNode* head;
	int size;

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
