/**
 * @file test-singly.cpp
 * @brief Test runner of the singly-linked list
 *
 */
#include "singly-ll.hpp"
// #include "doubly-ll.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testSinglyLinkedList();
// void testDoublyLinkedList();

int main() {
  testSinglyLinkedList();
}

void testSinglyLinkedList() {
  cout << "Testing singly-linked list...\n";
  SinglyLinkedList<int> l1;

  assert(l1.isEmpty());
  assert(!l1.size());
  l1.prepend(new Node<int>(3));
  assert(l1.size() == 1);
  l1.prepend(new Node<int>(2));
  assert(l1.size() == 2);

  assert(l1.search(2) != nullptr);
  Node<int> *new1 = new Node<int>(4);
  l1.insertAfter(l1.search(3), new1);
  assert(l1.search(4) == new1);
  Node<int> *new2 = new Node<int>(5);
  l1.insertAfter(l1.search(2), new2);
  assert(l1.search(5) == new2);
  // l1.print();  // 2 5 3 4
  assert(l1.size() == 4);
  l1.remove(l1.search(5));
  assert(l1.search(5) == nullptr);
  // l1.print();  // 2 3 4
  assert(l1.size() == 3);
  cout << "All tests passed!\n";
}
