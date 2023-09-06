#include "three-ints.hpp"
#include <cassert>

int main() {
  assert(threeIntsSum(10, 5, 6) == 21);
  assert(threeIntsSum(-10, 0, 6) == -4);
  assert(threeIntsAvg(10, 5, 6) == 7);
  assert(threeIntsAvg(-9, 0, 6) == -2);
}