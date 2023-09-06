#include "vector.hpp"

#include <iostream>
#include <cassert>

int main() {
  Vector<int> v1(2, 1);  // repeat constructor

  assert(v1.getSize() == 2);
  assert(v1.at(0) == 1);
  assert(v1.at(1) == 1);

  v1.at(0) = 10;
  assert(v1.at(0) == 10);

  v1.push_back(4);
  v1.push_back(5);
  v1.push_back(6);  // trigger reallocation

  assert(v1.back() == 6);
  assert(v1.getSize() == 5);

  return 0;
}
