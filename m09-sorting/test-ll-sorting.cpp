#include "llist.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;


// Make a vector of size 10 with values 1 to 10
// Shuffle the vector randomly
// Insert the values into the linked list
// Sort the linked list
// Convert the linked list to a vector and check if it is sorted
int main(int argc, char const *argv[]) {

  LinkedList<int> llist;

  int repeat = 3;
  int size = 10;
  vector<int> arr(size);

  // Test insertion sort
  for (int run = 0; run < repeat; ++run) {
    for (int i = 0; i < size; ++i) arr[i] = i + 1;
    shuffle(arr.begin(), arr.end(), default_random_engine(0));
    for (int i = 0; i < size; ++i) llist.append(arr.at(i));
    assert(!is_sorted(arr.begin(), arr.end()));
    llist.insertionSort();
    vector<int> llist_arr = llist.toVector();
    assert(is_sorted(llist_arr.begin(), llist_arr.end()));
    cout << "Insertion sort run " << run << " passed!" << endl;
  }

  // Test merge sort
  for (int run = 0; run < repeat; ++run) {
    for (int i = 0; i < size; ++i) arr[i] = i + 1;
    shuffle(arr.begin(), arr.end(), default_random_engine(0));
    for (int i = 0; i < size; ++i) llist.append(arr.at(i));
    assert(!is_sorted(arr.begin(), arr.end()));
    llist.mergeSort();
    vector<int> llist_arr = llist.toVector();
    assert(is_sorted(llist_arr.begin(), llist_arr.end()));
    cout << "Merge sort run " << run << " passed!" << endl;
  }

  return EXIT_SUCCESS;
}

