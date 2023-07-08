#include "IntLinkedListLS.h"
#include "IntNode.h"
#include <iostream>
using namespace std;

IntLinkedListLS::IntLinkedListLS() {
	head = NULL;
	size = 0;
}

IntLinkedListLS::~IntLinkedListLS() {
	IntNode* curr = head;
	IntNode* toDelete;

	while (curr != NULL) {
		toDelete = curr;
		curr = curr->next;
		delete toDelete;
		toDelete = NULL;
	}
	head = NULL;
}

void IntLinkedListLS::addToStart(int value) {
	IntNode* node = new IntNode;
	node->data = value;
	node->next = head;
	head = node;
	size++;
}

void IntLinkedListLS::addToIndex(int value, int index) {
	if (index > size)
		cout << "Invalid index " << index << " for array of size " << size << ". Add request ignored." << endl;
	else if (index == 0)
		addToStart(value);
	else {
		int i = 0;
		IntNode* before = NULL;
		IntNode* after = head;
		while ((after != NULL) && (i < index)) {
			i++;
			before = after;
			after = after->next;
		}

		IntNode* toAdd = new IntNode;
		toAdd->data = value;
		toAdd->next = after;
		before->next = toAdd;

		size++;
	}
}

int IntLinkedListLS::removeFromStart() {
	int retVal = head->data;
	IntNode* toDelete = head;
	head = head->next;
	delete toDelete;
	size--;
	return retVal;
}

int IntLinkedListLS::removeFromIndex(int index) {
	if (index >= size) {
		cout << "Invalid index " << index << " for array of size " << size << ". Remove request ignored." << endl;
		return -1;
	}
	else if (index == 0)
		return removeFromStart();
	else {
		int i = 0;
		IntNode* before = NULL;
		IntNode* toRemove = head;
		while ((toRemove != NULL) && (i < index)) {
			i++;
			before = toRemove;
			toRemove = toRemove->next;
		}
		int toReturn = toRemove->data;
		before->next = toRemove->next;

		delete toRemove;
		size--;

		return toReturn;
	}
}

int IntLinkedListLS::getSize() {
	return size;
}

int IntLinkedListLS::get(int index) {
	int currIndex = 0;
	IntNode* currNode = head;

	while ((currNode != NULL) && (currIndex < index)) {
		currNode = currNode->next;
		currIndex++;
	}

	if ((currNode != NULL) && (currIndex == index))
		return currNode->data;
	else
		return -1; // Or signal an error, or ???
}

void IntLinkedListLS::printAll() {
	if (head == NULL)
		cout << "[] (size: " << size << ")" << endl;
	else {
		cout << "[";
		IntNode* curr = head;
		while (curr->next != NULL) {
			cout << curr->data << ", ";
			curr = curr->next;
		}
		cout << curr->data << "]" << " (size: " << size << ")" << endl;
	}
}

