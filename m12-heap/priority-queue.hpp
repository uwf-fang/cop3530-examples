/**
 * @file priority-queue.hpp
 * @author Ian Fang
 * @brief Min heap based min priority queue, wrapper class
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_

#include "min-heap.hpp"

template <typename T>
class PriorityQueue {
  MinHeap<T> heap;
public:
  void enqueue(T value);
  T dequeue();
  T peek();
  bool isEmpty();
  int getLength();  // Not required by the ADT, but useful for testing
};

template <typename T>
void PriorityQueue<T>::enqueue(T value) {
  heap.add(value);
}

template <typename T>
T PriorityQueue<T>::dequeue() {
  return heap.remove();
}

template <typename T>
T PriorityQueue<T>::peek() {
  return heap.peek();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
  return heap.isEmpty();
}

template <typename T>
int PriorityQueue<T>::getLength() {
  return heap.getLength();
}

#endif // PRIORITYQUEUE_HPP_
