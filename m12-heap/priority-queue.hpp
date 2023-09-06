#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_

#include "min-heap.hpp"

template <class T>
class PriorityQueue {
  MinHeap<T> heap;  // MinHeap has the int type as its base type
public:
  void enqueue(T value);
  T dequeue();
  T peek();
  bool isEmpty();
  int getLength();
};

template <class T>
void PriorityQueue<T>::enqueue(T value) {
  heap.insert(value);
}

template <class T>
T PriorityQueue<T>::dequeue() {
  return heap.remove();
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
