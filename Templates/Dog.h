#ifndef __Dog_H
#define __Dog_H

#include <string>
#include <iostream>
using namespace std;

class Dog {
private:
  string name;
  int age;

public:
  Dog();
  Dog(string name, int age);

  void print(ostream & out) const;
};

ostream & operator<< (ostream & out, const Dog & d);

#endif
