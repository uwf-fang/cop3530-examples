#ifndef TESTING_HELPER_HPP
#define TESTING_HELPER_HPP

#include <cmath>
#include <iostream>

bool isClose(double v1, double v2, double epsilon = 1e-4);
bool isClose(double v1, double v2, double epsilon) {
  return std::abs(v1 - v2) < epsilon;
}

template<class IT>
bool isAllNotNegative(IT start, IT end) {
  for (IT it = start; it != end; ++it)
    if (*it < 0) return false;
  return true;
}

template<class IT>
bool isAscending(IT start, IT end) {
  for (IT it = start; it != end - 1; ++it)
    if (*it > *(it + 1)) return false;
  return true;
}

template<class IT>
void printSeq(IT start, IT end) {
  for (IT it = start; it != end; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

#endif // TESTING_HELPER_HPP
