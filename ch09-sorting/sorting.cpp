#include <iostream>
#include "llist.hpp"

using namespace std;


int main(int argc, char const *argv[]) {

  LinkedList<int> llist;

  llist.append(5);
  llist.append(1);
  llist.append(9);
  llist.append(3);
  llist.append(6);
  cout << "Current size: " << llist.size() << endl;

  cout << "Unsorted: ";
  llist.printAll();
  llist.insertionSort();
  cout << "Sorted: ";
  llist.printAll();

  return EXIT_SUCCESS;
}

