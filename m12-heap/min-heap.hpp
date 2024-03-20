#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <utility>  // std::swap

template <typename T>
class MinHeap {
  T *array;
  int length;
  int capacity;
  void reAllocate();
  void percolateUp(int nodeIndex);
  void percolateDown(int nodeIndex);

 public:
  MinHeap();
  MinHeap(const MinHeap &other);
  MinHeap &operator=(const MinHeap &other);
  ~MinHeap();
  void insert(T value);
  T remove();
  T peek();
  bool isEmpty();
  int getLength();
};

template <typename T>
MinHeap<T>::MinHeap() : array(new T[100]), length(0), capacity(100) {}

template <typename T>
MinHeap<T>::~MinHeap() {
  delete[] array;
}

template <typename T>
MinHeap<T>::MinHeap(const MinHeap &other)
    : array(new T[other.capacity]), length(other.length), capacity(other.capacity) {
  for (int i = 0; i < length; ++i)
    array[i] = other.array[i];
}

template <typename T>
MinHeap<T> &MinHeap<T>::operator=(const MinHeap &other) {
  if (this != &other) {
    delete[] array;
    length = other.length;
    capacity = other.capacity;
    array = new T[capacity];
    for (int i = 0; i < length; ++i)
      array[i] = other.array[i];
  }
  return *this;
}

template <typename T>
void MinHeap<T>::reAllocate() {
  capacity += 100;
  T *newArr = new T[capacity];
  for (int i = 0; i < capacity; ++i)
    newArr[i] = array[i];
  delete[] array;
  array = newArr;
}

template <typename T>
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

template <typename T>
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

template <typename T>
void MinHeap<T>::insert(T value) {
  if (length >= capacity) reAllocate();
  array[length] = value;
  percolateUp(length);
  ++length;
}

// Should always check not empty before calling dequeue
template <typename T>
T MinHeap<T>::remove() {
  T value = array[0];
  array[0] = array[length - 1];
  --length;
  percolateDown(0);
  return value;
}

// Should always check not empty before calling dequeue
template <typename T>
T MinHeap<T>::peek() {
  return array[0];
}

template <typename T>
bool MinHeap<T>::isEmpty() {
  return length == 0;
}

template <typename T>
int MinHeap<T>::getLength() {
  return length;
}

#endif // MIN_HEAP_HPP
