#include "Dog.h"
#include <string>
#include <iostream>
using namespace std;

Dog::Dog() {
  this->name = "";
  this->age = -1;
}

Dog::Dog(string name, int age) {
  this->name = name;
  this->age = age;
}

void Dog::print(ostream & out) const {
  out << "(" << name << ", " << age << ")";
}

ostream & operator<< (ostream & out, const Dog & d) {
  d.print(out);
  return out;
}
