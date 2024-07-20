#include "llist.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>
#include <vector>
#include <iterator>

using namespace std;


// Make a vector of size 10 with values 1 to 10
// Shuffle the vector randomly
// Insert the values into the linked list
// Sort the linked list
// Convert the linked list to a vector and check if it is sorted
int main(int argc, char const *argv[]) {

  const int SIZE = 13;
  const int RUNS = 10;
  const int MAX_VAL = 9;  // less than SIZE to ensure duplicates

  // random numbers between 1 and SIZE inclusive
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, MAX_VAL);

  vector<int> initial(SIZE);
  LinkedList<int> llist1, llist2;

  // Test insertion sort
  for (int run = 0; run < RUNS; ++run) {
    for (int i = 0; i < SIZE; ++i) initial.at(i) = dis(gen);
    llist1.reset();
    llist2.reset();
    for (int i = 0; i < SIZE; ++i) {
      llist1.append(initial.at(i));
      llist2.append(initial.at(i));
    }
    // regenerate if the array is accidentally sorted
    if (is_sorted(initial.begin(), initial.end())) {
      --run;
      continue;
    }
    // copy(initial.begin(), initial.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    llist1.insertionSort();
    llist2.mergeSort();
    sort(initial.begin(), initial.end());
    vector<int> result1 = llist1.toVector();
    vector<int> result2 = llist2.toVector();

    // copy(initial.begin(), initial.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    // copy(result1.begin(), result1.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    // copy(result2.begin(), result2.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    assert(initial == result1);
    cout << "Insertion sort run " << run << " passed!" << endl;
    assert(initial == result2);
    cout << "Merge sort run " << run << " passed!" << endl;
  }

  return EXIT_SUCCESS;
}

