#ifndef INTARRAYLS_H
#define INTARRAYLS_H

class IntArrayLS {
private:
	int size;
	int capacity;
	int* elements; // pointer to the beginning of the array

	void expandArray();
	void shiftRight(int lowIndex);
	void shiftLeft(int lowIndex);

public:
	IntArrayLS(int initialCapacity);
	~IntArrayLS();

	void addToStart(int value);
	void addToIndex(int value, int index);

	int removeFromStart();
	int removeFromIndex(int index);

	int getSize();

	int get(int index);

	void printAll();
};

#endif
