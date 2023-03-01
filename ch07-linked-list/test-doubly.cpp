/**
 * @file test-doubly.cpp
 * @brief Test runner of the doubly-linked list
 *
 */
#include "doubly-ll.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testDoublyLinkedList();

int main() {
  testDoublyLinkedList();
}

void testDoublyLinkedList() {
  cout << "Testing doubly-linked list...\n";
  DoublyLinkedList<int> l1;

  assert(l1.empty());
  assert(l1.size() == 0);
  l1.push_front(1);
  assert(l1.size() == 1);
  assert(l1.front() == 1);
  assert(l1.back() == 1);
  l1.push_back(2);
  assert(l1.size() == 2);
  assert(l1.front() == 1);
  assert(l1.back() == 2);
  l1.pop_front();
  assert(l1.size() == 1);
  assert(l1.front() == 2);
  assert(l1.back() == 2);
  l1.pop_back();
  assert(l1.size() == 0);

  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  assert(l1.size() == 3);
  l1.remove(3);
  assert(l1.size() == 2);

  cout << "All tests passed!\n";
}
