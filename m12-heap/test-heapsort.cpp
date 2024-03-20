#include <algorithm>
#include <iostream>
#include <cassert>
#include "heapsort.hpp"

using namespace std;

int main() {

  cout << "Testing heapsort" << endl;

  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  assert(!is_sorted(arr, arr + size));
  heapsort(arr, size);
  assert(is_sorted(arr, arr + size));

  cout << "Tests passed" << endl;

  return EXIT_SUCCESS;
}