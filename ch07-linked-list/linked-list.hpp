/**
 * All linked list (templated)
 *   All linked list has one value of type T in each
 *   Incomplete class template, for demonstration
 */

template<class T>
class Node {
  T value;
  Node * next;
 public:
  //...
};

template<class T>
class BidirectionalNode {
  T value;
  BidirectionalNode * next;
  BidirectionalNode * prev;
 public:
  //...
};

// minimal linked list
// a single head pointer
template <class T>
class MinLinkedList {
 private:
  Node<T> * head;
 public:
  //...
};

// singly-linked list
// a head pointer, a tail pointer
// a next pointer in node class
template <class T>
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
template <class T>
class DoublyLinkedList {
 private:
  BidirectionalNode<T> * head;
  BidirectionalNode<T> * tail;
 public:
  // ...
};

