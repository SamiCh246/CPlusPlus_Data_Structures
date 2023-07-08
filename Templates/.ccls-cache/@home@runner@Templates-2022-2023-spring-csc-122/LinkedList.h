#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList {
private:
  Node<T> *head;
  int size;

public:
  LinkedList();
  ~LinkedList();

  void addToStart(T data);
  void addToIndex(T data, int index);

  T removeFromStart();
  T removeFromIndex(int index);

  int getSize();
  T get(int index);

  void printAll();

  Node<T> *findNode(T target);
  int findNodeIndex(T target);
  bool removeElement(T target);
};

template <typename T>
LinkedList<T>::LinkedList() {
  head = NULL;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList<T>() {
  Node<T>* curr = head;
  Node<T>* toDelete;

  while (curr != NULL) {
    toDelete = curr;
    curr = curr->next;
    delete toDelete;
    toDelete = NULL;
  }
  head = NULL;
}

template <typename T>
void LinkedList<T>::addToStart(T value) {
  Node<T>* node = new Node<T>;
  node->data = value;
  node->next = head;
  head = node;
  size++;
}

template <typename T>
void LinkedList<T>::addToIndex(T value, int index) {
  if (index > size)
    cout << "Invalid index " << index << " for array of size " << size
         << ". Add request ignored." << endl;
  else if (index == 0)
    addToStart(value);
  else {
    int i = 0;
    Node<T>* before = NULL;
    Node<T>* after = head;
    while ((after != NULL) && (i < index)) {
      i++;
      before = after;
      after = after->next;
    }

    Node<T>* toAdd = new Node<T>;
    toAdd->data = value;
    toAdd->next = after;
    before->next = toAdd;

    size++;
  }
}

template <typename T>
T LinkedList<T>::removeFromStart() {
  T retVal = head->data;
  Node<T>* toDelete = head;
  head = head->next;
  delete toDelete;
  size--;
  return retVal;
}

template <typename T>
T LinkedList<T>::removeFromIndex(int index) {
  if (index >= size) {
    cout << "Invalid index " << index << " for array of size " << size
         << ". Remove request ignored." << endl;
    cout.flush();
    throw "Error";
  }
  else if (index == 0)
    return removeFromStart();
  else {
    int i = 0;
    Node<T>* before = NULL;
    Node<T>* toRemove = head;
    while ((toRemove != NULL) && (i < index)) {
      i++;
      before = toRemove;
      toRemove = toRemove->next;
    }
    T toReturn = toRemove->data;
    before->next = toRemove->next;

    delete toRemove;
    size--;

    return toReturn;
  }
}

template <typename T>
int LinkedList<T>::getSize() {
  return size;
}

template <typename T>
T LinkedList<T>::get(int index) {
  int currIndex = 0;
  Node<T>* currNode = head;

  while ((currNode != NULL) && (currIndex < index)) {
    currNode = currNode->next;
    currIndex++;
  }

  if ((currNode != NULL) && (currIndex == index))
    return currNode->data;
  else
    throw "Error"; // Or signal an error, or ???
}

template <typename T>
void LinkedList<T>::printAll() {
  if (head == NULL)
    cout << "[] (size: " << size << ")" << endl;
  else {
    cout << "[";
    Node<T>* curr = head;
    while (curr->next != NULL) {
      cout << curr->data << ", ";
      curr = curr->next;
    }
    cout << curr->data << "]"
         << " (size: " << size << ")" << endl;
  }
}

template <typename T>
Node<T>* LinkedList<T>::findNode(T target) {
  Node<T>* currNode = head;
  while (currNode != NULL) {
    if (currNode->data == target)
      return currNode;
    currNode = currNode->next;
  }
  return NULL;
}

template <typename T>
int LinkedList<T>::findNodeIndex(T target) {
  Node<T>* currNode = head;
  int index = 0;
  while (currNode != NULL) {
    if (currNode->data == target)
      return index;
    currNode = currNode->next;
    index++;
  }
  return -1;
}

template <typename T>
bool LinkedList<T>::removeElement(T target) {
  Node<T>* toRemove = findNode(target);
  if (toRemove == NULL)
    return false;
  if (toRemove == head) {
    removeFromStart();
    return true;
  }
  removeFromIndex(findNodeIndex(target));
  return true;
}

#endif
