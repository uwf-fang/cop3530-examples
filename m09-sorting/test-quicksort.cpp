#include "quicksort.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>

using namespace std;

int main() {

  const int SIZE = 11;
  const int RUNS = 10;
  const int MAX_VAL = 9;  // less than SIZE to ensure duplicates

  // random numbers between 1 and SIZE inclusive
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, MAX_VAL);

  int *arr = new int[SIZE];

  // Test quicksort
  cout << "Testing quicksort..." << endl;
  for (int run = 0; run < RUNS; ++ run) {
    for (int i = 0; i < SIZE; ++i) arr[i] = dis(gen);
    // regenerate if the array is accidentally sorted
    if (is_sorted(arr, arr + SIZE)) {
      run--;
      continue;
    }
    quicksort(arr, SIZE);
    assert(is_sorted(arr, arr + SIZE));
    cout << "Run " << run << " passed!" << endl;
  }

  delete[] arr;

  return EXIT_SUCCESS;
}