#ifndef LINEAR_ADT_HPP
#define LINEAR_ADT_HPP

/**
 * Describe Linear ADTs as C++ class template
 *   Only public methods
 *   Incomplete class template, for demonstration
 *
 * One wrapper class example
 */

template <class T>
class Stack {
 public:
  void push(T value);
  T pop();
  bool isEmpty();
};

template <class T>
class Queue {
 public:
  void enqueue(T value);
  T dequeue();
  bool isEmpty();
};

template <class T>
class Deque {
 public:
  void push_back(T value);
  T pop_back();
  void push_front(T value);
  T pop_front();
  bool isEmpty();
};

template <class T>
class WrapperStack {
  Deque<T> deque;
 public:
  void push(T value) {
    deque.push_front(value);
  }
  T pop() {
    return deque.pop_front();
  }
  bool isEmpty() {
    return deque.isEmpty();
  }
};

#endif // LINEAR_ADT_HPP
