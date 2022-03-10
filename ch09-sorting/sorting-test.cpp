#include <iostream>
#include "llist.hpp"

using namespace std;


int main(int argc, char const *argv[]) {

  LinkedList<int> llist {5, 1, 9, 3, 6};

  cout << "Current size: " << llist.size() << endl;

  cout << "Unsorted: ";
  llist.printAll();
  // llist.insertionSort();
  llist.mergeSort();
  cout << "Sorted: ";
  llist.printAll();

  return EXIT_SUCCESS;
}

