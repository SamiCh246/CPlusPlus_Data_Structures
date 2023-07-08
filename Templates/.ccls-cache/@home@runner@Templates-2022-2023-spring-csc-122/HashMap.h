#ifndef HASHMAP_H
#define HASHMAP_H

#include "Entry.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T> 
class HashMap {
private:
  LinkedList<Entry<T>> **arr;
  int capacity;
  int hashcode(string k);

public:
  HashMap(int capacity);
  ~HashMap();
  void put(string k, T v);
  T get(string k);
  bool remove(string k);
  void printStructure();
};

template <typename T> 
HashMap<T>::HashMap(int capacity) {
  arr = new LinkedList<Entry<T>> *[capacity];
  this->capacity = capacity;
  for (int i = 0; i < capacity; i++)
    arr[i] = new LinkedList<Entry<T>>;
}

template <typename T> 
HashMap<T>::~HashMap() {
  for (int i = 0; i < capacity; i++)
    arr[i]->~LinkedList();
  delete arr;
}

template <typename T> 
int HashMap<T>::hashcode(string k) {
  int sum = 0;
  for (int i = 0; i < k.length(); i++)
    sum += (int) k[i];
  return sum % capacity;
}

template <typename T> 
void HashMap<T>::put(string k, T v) {
  Entry<T> e;
  e.key = k;
  e.value = v;
  arr[hashcode(k)]->addToStart(e);
}

template <typename T> 
T HashMap<T>::get(string k) {
  Entry<T> e;
  e.key = k;
  return arr[hashcode(k)]->findNode(e)->data.value; 
}

template <typename T>
bool HashMap<T>::remove(string k) {
  Entry<T> e;
  e.key = k;
  return arr[hashcode(k)]->removeElement(e);
}

template <typename T> 
void HashMap<T>::printStructure() {
  cout << "================" << endl;
  for (int i = 0; i < capacity; i++) {
    cout << "----------" << endl;
    cout << "Slot " << i << ":" << endl;
    arr[i]->printAll();
    cout << "----------" << endl;
  }
  cout << "================" << endl;
}
#endif