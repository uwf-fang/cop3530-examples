#include "llist.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {

  LinkedList<int> llist;

  int size = 10;
  vector<int> arr(size);

  for (int run = 0; run < 3; ++ run) {
    for (int i = 0; i < size; ++i) arr[i] = i + 1;
    shuffle(arr.begin(), arr.end(), default_random_engine(0));
    for (int i = 0; i < size; ++i) llist.append(arr.at(i));
    assert(!is_sorted(arr.begin(), arr.end()));
    llist.insertionSort();
    auto llist_arr = llist.toVector();
    assert(is_sorted(llist_arr.begin(), llist_arr.end()));
    cout << "Insertion sort run " << run << " passed!" << endl;
  }

  for (int run = 0; run < 3; ++ run) {
    for (int i = 0; i < size; ++i) arr[i] = i + 1;
    shuffle(arr.begin(), arr.end(), default_random_engine(0));
    for (int i = 0; i < size; ++i) llist.append(arr.at(i));
    assert(!is_sorted(arr.begin(), arr.end()));
    llist.mergeSort();
    auto llist_arr = llist.toVector();
    assert(is_sorted(llist_arr.begin(), llist_arr.end()));
    cout << "Merge sort run " << run << " passed!" << endl;
  }

  return EXIT_SUCCESS;
}

