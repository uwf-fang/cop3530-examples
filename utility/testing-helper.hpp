#ifndef TESTING_HELPER_HPP
#define TESTING_HELPER_HPP

#include <cmath>
#include <vector>

using std::vector;

bool isClose(double v1, double v2, double epsilon = 1e-4);

template<class T>
bool allPositive(const vector<T> &vec);

template<class T>
void printVector(const vector<T> &vec);

bool isClose(double v1, double v2, double epsilon) {
  return std::abs(v1 - v2) < epsilon;
}

template<class T>
bool allNotNegative(const vector<T> &vec) {
  for (auto v: vec)
    if (v < 0) return false;
  return true;
}

template<class T>
void printVector(const vector<T> &vec) {
  for (auto v: vec)
    std::cout << v << " ";
  std::cout << std::endl;
}
#endif // TESTING_HELPER_HPP
