#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_

#include "min-heap.hpp"

template <typename T>
class PriorityQueue {
  MinHeap<T> heap;  // MinHeap has the int type as its base type
public:
  void enqueue(T value);
  T dequeue();
  T peek();
  bool isEmpty();
  int getLength();
};

template <typename T>
void PriorityQueue<T>::enqueue(T value) {
  heap.insert(value);
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
