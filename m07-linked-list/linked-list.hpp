#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
/**
 * All linked list (templated)
 *   All linked list has one value of type T in each
 *   Incomplete class template, for demonstration
 */

template<typename T>
class Node {
  T value;
  Node<T> * next;
 public:
  //...
};

template<typename T>
class BidirectionalNode {
  T value;
  BidirectionalNode<T> * next;
  BidirectionalNode<T> * prev;
 public:
  //...
};

// minimal linked list
// a single head pointer
template <typename T>
class MinLinkedList {
 private:
  Node<T> * head;
 public:
  //...
};

// singly-linked list
// a head pointer, a tail pointer
// a next pointer in node class
template <typename T>
class SinglyLinkedList {
 private:
  Node<T> * head;
  Node<T> * tail;
 public:
  //...
};

// doubly-linked list
// a head pointer, a tail pointer
// a next pointer, a prev pointer in node class
template <typename T>
class DoublyLinkedList {
 private:
  BidirectionalNode<T> * head;
  BidirectionalNode<T> * tail;
 public:
  // ...
};

#endif
