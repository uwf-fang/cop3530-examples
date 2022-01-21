#include "threeintsfcts.hpp"
#include <cassert>

int main() {
  assert(ThreeIntsSum(10, 5, 6) == 21);
  assert(ThreeIntsSum(-10, 0, 6) == -4);
  assert(ThreeIntsAvg(10, 5, 6) == 7);
  assert(ThreeIntsAvg(-9, 0, 6) == -2);
}