#ifndef DOUBLY_LL_HPP
#define DOUBLY_LL_HPP

template<class T>
class BidirectionalNode {
 public:
  T value;
  BidirectionalNode<T> * next;
  BidirectionalNode<T> * prev;
  BidirectionalNode<T>();
  BidirectionalNode<T>(T value): value(value) {}
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
  DoublyLinkedList(): head(nullptr), tail(nullptr) {}
  ~DoublyLinkedList();
  void append(Node<T> * node);
  void prepend(Node<T> * node);
  void insertBefore(Node<T> * refNode, Node<T> * nodeToInsert);
  void remove(Node<T> *node);
  Node<T> *search(T value);
  bool isEmpty();
  int length();
  void print();
};

#endif