#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

template <typename T>
class Node {
public:
	Node<T>* next;
	T data;
};

#endif