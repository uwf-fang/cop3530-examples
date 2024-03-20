/**
 * @file test-pq.cpp
 * @author Ian Fang
 * @brief Test the priority queue
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <utility>
#include <iostream>
#include <cassert>
#include "priority-queue.hpp"

using namespace std;

int main() {

  // Test enqueue, dequeue, peek, isEmpty, getLength
  PriorityQueue<int> q;
  q.enqueue(23);
  assert(q.peek() == 23);
  assert(q.getLength() == 1);
  q.enqueue(34);
  assert(q.peek() == 23);
  assert(q.getLength() == 2);
  q.enqueue(15);
  assert(q.peek() == 15);
  assert(q.getLength() == 3);
  q.enqueue(10);
  assert(q.peek() == 10);
  assert(q.getLength() == 4);

  assert(q.dequeue() == 10);
  assert(q.peek() == 15);
  assert(q.getLength() == 3);
  assert(q.dequeue() == 15);
  assert(q.peek() == 23);
  assert(q.getLength() == 2);
  assert(q.dequeue() == 23);
  assert(q.peek() == 34);
  assert(q.getLength() == 1);
  assert(!q.isEmpty());
  assert(q.dequeue() == 34);
  assert(q.getLength() == 0);
  assert(q.isEmpty());

  cout << "Tests on enqueue, dequeue, peek, isEmpty, getLength passed" << endl;


  // Test big three
  PriorityQueue<int> q1;
  q1.enqueue(23);
  q1.enqueue(10);
  q1.enqueue(15);
  q1.enqueue(34);
  PriorityQueue<int> q2(q1);
  assert(q2.dequeue() == 10);
  assert(q2.peek() == 15);
  assert(q2.getLength() == 3);
  PriorityQueue<int> q3;
  q3 = q1;
  assert(q3.dequeue() == 10);
  assert(q3.peek() == 15);
  assert(q3.getLength() == 3);

  cout << "Tests on big three passed" << endl;

  cout << "All tests passed" << endl;

}


