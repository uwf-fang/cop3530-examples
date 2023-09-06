#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <utility>  // std::swap

template <class T>
class MinHeap {
  T *array;
  int length;
  int maxLength;
  void reAllocate();
  void percolateUp(int nodeIndex);
  void percolateDown(int nodeIndex);

 public:
  MinHeap();
  ~MinHeap();
  void insert(T value);
  T remove();
  T peek();
  bool isEmpty();
  int getLength();
};

template <class T>
MinHeap<T>::MinHeap() : array(new T[100]), length(0), maxLength(100) {}

template <class T>
MinHeap<T>::~MinHeap() {
  delete[] array;
}

template <class T>
void MinHeap<T>::reAllocate() {
  maxLength += 100;
  T *newArr = new T[maxLength];
  for (int i = 0; i < maxLength; ++i)
    newArr[i] = array[i];
  delete[] array;
  array = newArr;
}

template <class T>
void MinHeap<T>::percolateUp(int nodeIndex) {
  int parentIndex;
  while (nodeIndex > 0) {
    parentIndex = (nodeIndex - 1) / 2;
    if (array[nodeIndex] >= array[parentIndex])
      return;
    else {
      std::swap(array[nodeIndex], array[parentIndex]);
      nodeIndex = parentIndex;
    }
  }
}

template <class T>
void MinHeap<T>::percolateDown(int nodeIndex) {
  int minIndex;
  int minValue;
  int childIndex = 2 * nodeIndex + 1;
  T value = array[nodeIndex];
  while (childIndex < length) {
    minValue = value;
    minIndex = -1;
    for (int i = 0; i < 2 && i + childIndex < length; ++i) {
      if (array[i + childIndex] < minValue) {
        minValue = array[i + childIndex];
        minIndex = i + childIndex;
      }
    }

    if (minValue == value) {
      return;
    } else {
      std::swap(array[nodeIndex], array[minIndex]);
      nodeIndex = minIndex;
      childIndex = 2 * nodeIndex + 1;
    }
  }
}

template <class T>
void MinHeap<T>::insert(T value) {
  if (length >= maxLength) reAllocate();
  array[length] = value;
  percolateUp(length);
  ++length;
}

// Should always check not empty before calling dequeue
template <class T>
T MinHeap<T>::remove() {
  T value = array[0];
  array[0] = array[length - 1];
  --length;
  percolateDown(0);
  return value;
}

// Should always check not empty before calling dequeue
template <class T>
T MinHeap<T>::peek() {
  return array[0];
}

template <class T>
bool MinHeap<T>::isEmpty() {
  return length == 0;
}

template <class T>
int MinHeap<T>::getLength() {
  return length;
}

#endif // MIN_HEAP_HPP
