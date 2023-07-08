#include "IntLinkedListLS.h"
#include <iostream>
using namespace std;

IntLinkedListLS::IntLinkedListLS() {
	head = NULL;
  size = 0;
}

IntLinkedListLS::~IntLinkedListLS() {
	if (head != NULL) {             
    IntNode* curr = head;
    IntNode* temp = head;
    while (temp != NULL) {
      temp = curr->next;      
      delete curr;
      curr = temp;
    }
  }    
}

void IntLinkedListLS::addToStart(int value) {
	IntNode* temp = new IntNode;
  temp->data = value;
  temp->next = head;
  head = temp;
  size++;
}

void IntLinkedListLS::addToIndex(int value, int index) {
  if (index > size || index < 0) {
		cout << "Invalid index " << index << " for list of size " << size << ". Add request ignored." << endl;
    return;
  }

  if (index == 0) {
    addToStart(value);
    return;
  }

  IntNode* temp = new IntNode;
  temp->data = value;

  IntNode* curr = head;
  for (int i = 0; i < index - 1; i++)
    curr = curr->next;

  temp->next = curr->next;
  curr->next = temp;
  
  size++;
}

int IntLinkedListLS::removeFromStart() {
	IntNode* temp = head;
  head = head->next;
  int data = temp->data;
  delete temp;
  size--;
  return data;
}

int IntLinkedListLS::removeFromIndex(int index) {
  if (index >= size || index < 0) {
		cout << "Invalid index " << index << " for list of size " << size << ". Remove request ignored." << endl;
    return -1;
  }

  if (index == 0)
    return removeFromStart();
  
  IntNode* curr = head;
  for (int i = 0; i < index - 1; i++)
    curr = curr->next;

  IntNode* curr2 = curr->next;
  curr->next = curr2->next;

  int data = curr2->data;
  delete curr2;
  size--;
  return data;
}

int IntLinkedListLS::getSize() {
	return size;
}

int IntLinkedListLS::get(int index) {
	if (size == 0) {
    cout << "Structure is empty!" << endl;
    return -1;
  }

  if (index >= size || index < 0) {
    cout << "Invalid index " << index << " for list of size " << size << ". Get request ignored." << endl;
    return -1;
  }
    
  IntNode* curr = head;
  for (int i = 0; i < index; i++)
    curr = curr->next;
  return curr->data;
}

void IntLinkedListLS::printAll() {
  if (size == 0) {
    cout << "Structure is empty! PrintAll ignored" << endl;
    return;
  }
  
  IntNode* curr = head;
  cout << "[";
  while(curr->next !=NULL) {
    cout << curr->data << ", ";
    curr = curr->next;
  }
  cout << curr->data << "] (size: " << size << ")" << endl;
}
