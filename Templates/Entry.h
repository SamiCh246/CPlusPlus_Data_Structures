#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

template <typename T>
class Entry {
public:
	string key;
	T value;
};

template <typename T>
ostream & operator<< (ostream & out, const Entry<T> & e) {
	out << e.key << ":" << e.value;
	return out;
}

template <typename T>
bool operator==(const Entry<T> &left, const Entry<T> &right) {
	return left.key == right.key;
}

template <typename T>
bool operator!=(const Entry<T> &left, const Entry<T> &right) {
	return !(left == right);
}

#endif
