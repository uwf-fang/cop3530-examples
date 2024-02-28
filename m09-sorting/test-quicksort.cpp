#include "quicksort.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>

using namespace std;

int main() {
  int size = 10;
  int *arr = new int[size];

  for (int run = 0; run < 3; ++ run) {
    for (int i = 0; i < size; ++i) arr[i] = i + 1;
    shuffle(arr, arr + size, default_random_engine(0));
    assert(!is_sorted(arr, arr + size));
    quicksort(arr, size);
    assert(is_sorted(arr, arr + size));
    cout << "Run " << run << " passed!" << endl;
  }

  return EXIT_SUCCESS;
}