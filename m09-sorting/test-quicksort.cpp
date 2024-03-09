#include "quicksort.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>

using namespace std;

// Test that the mid formulas are equivalent
// (i + j) / 2 and i + (j - i) / 2
void testMidFormula() {
  for (int i = 0; i < 3; ++i)
    for (int j = 8; j < 11; ++j) {
      int mid1 = (i + j) / 2;
      int mid2 = i + (j - i) / 2;
      assert(mid1 == mid2);
    }
}

void testNoDup() {
  const int SIZE = 10;
  int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // no duplicates
  for (int run = 0; run < 3; ++ run) {
    shuffle(arr, arr + SIZE, default_random_engine(0));
    assert(!is_sorted(arr, arr + SIZE));
    quicksort(arr, SIZE);
    assert(is_sorted(arr, arr + SIZE));
    cout << "Test on array with no duplicate: run " <<
        run << " passed!" << endl;
  }
}

void testWithDup() {
  const int SIZE = 10;
  int arr[SIZE] = {1, 7, 3, 4, 5, 6, 7, 8, 3, 10};  // with duplicates
  for (int run = 0; run < 3; ++ run) {
    shuffle(arr, arr + SIZE, default_random_engine(0));
    assert(!is_sorted(arr, arr + SIZE));
    quicksort(arr, SIZE);
    assert(is_sorted(arr, arr + SIZE));
    cout << "Test on array with duplicates: run " <<
        run << " passed!" << endl;
  }
}

int main() {
  // testMidFormula();
  testNoDup();
  testWithDup();

  return EXIT_SUCCESS;
}