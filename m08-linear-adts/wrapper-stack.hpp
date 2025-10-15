#ifndef WRAPPER_STACK_HPP
#define WRAPPER_STACK_HPP

#include "deque.hpp"

// A Stack implemented as a wrapper of Deque
//   push/pop/peek from the front of the Deque
//   isEmpty() from the Deque

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


#endif // WRAPPER_STACK_HPP
