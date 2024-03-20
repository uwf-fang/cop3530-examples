#ifndef LINEAR_ADT_HPP
#define LINEAR_ADT_HPP

/**
 * Describe Linear ADTs as C++ class template
 *   Only public methods
 *   Incomplete class template, for demonstration
 *
 * One wrapper class example
 */

template <typename T>
class List {
 public:
  // Prepend + insertAfter can cover all cases
  //  append + insertBefore can also cover all cases
  void prepend(T value);
  void insertAfter(int index, T value);
  void remove(T value);
  int search(T value);
  T get(int index);
  bool isEmpty();
};

template <typename T>
class Stack {
 public:
  void push(T value);
  T pop();
  T peek();
  bool isEmpty();
};

template <typename T>
class Queue {
 public:
  void enqueue(T value);
  T dequeue();
  T peek();
  bool isEmpty();
};

template <typename T>
class Deque {
 public:
  void push_back(T value);
  T pop_back();
  void push_front(T value);
  T pop_front();
  T peek_front();
  T peek_back();
  bool isEmpty();
};

template <typename T>
class WrapperStack {
  Deque<T> deque;
 public:
  void push(T value) {
    deque.push_front(value);
  }
  T pop() {
    return deque.pop_front();
  }
  T peek() {
    return deque.peek_front();
  }
  bool isEmpty() {
    return deque.isEmpty();
  }
};

#endif // LINEAR_ADT_HPP
