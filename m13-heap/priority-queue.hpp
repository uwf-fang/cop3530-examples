#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_

#include "min-heap.hpp"

template <class T>
class PriorityQueue {
  MinHeap<T> heap;  // MinHeap has the int type as its base type
public:
  void push(T value);
  T pop();
  T peek();
  bool isEmpty();
  int getLength();
};

template <class T>
void PriorityQueue<T>::push(T value) {
  heap.push(value);
}

template <class T>
T PriorityQueue<T>::pop() {
  return heap.pop();
}

template <class T>
T PriorityQueue<T>::peek() {
  return heap.peek();
}

template <class T>
bool PriorityQueue<T>::isEmpty() {
  return heap.isEmpty();
}

template <class T>
int PriorityQueue<T>::getLength() {
  return heap.getLength();
}

#endif // PRIORITYQUEUE_HPP_
