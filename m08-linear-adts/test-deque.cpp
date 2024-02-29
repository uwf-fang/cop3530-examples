/**
 * @file test-doubly.cpp
 * @brief Test runner of the doubly-linked list
 *
 */
#include "deque.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testDoublyLinkedList();

int main() {
  testDoublyLinkedList();
}

void testDoublyLinkedList() {
  cout << "Testing doubly-linked list...\n";
  Deque<int> deque;

  assert(deque.isEmpty());
  assert(deque.size() == 0);
  assert(deque.isEmpty());
  deque.enqueueFront(1);
  assert(deque.size() == 1);
  assert(deque.front() == 1);
  assert(deque.back() == 1);
  deque.enqueueBack(2);
  assert(deque.size() == 2);
  assert(deque.front() == 1);
  assert(deque.back() == 2);
  deque.dequeueFront();
  assert(deque.size() == 1);
  assert(deque.front() == 2);
  assert(deque.back() == 2);
  deque.dequeueBack();
  assert(deque.size() == 0);
  assert(deque.isEmpty());

  deque.enqueueBack(1);
  deque.enqueueBack(2);
  deque.enqueueBack(3);
  assert(deque.size() == 3);

  Deque<int> d1(deque);
  assert(d1.size() == 3);
  assert(d1.front() == 1);
  assert(d1.back() == 3);

  Deque<int> d2;
  d2 = deque;
  assert(d1.size() == 3);
  assert(d1.front() == 1);
  assert(d1.back() == 3);
  
  cout << "All tests passed!\n";
}
