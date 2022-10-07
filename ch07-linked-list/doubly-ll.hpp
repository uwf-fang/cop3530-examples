#ifndef DOUBLY_LL_HPP
#define DOUBLY_LL_HPP

template<class T>
class BidirectionalNode {
  T value;
  BidirectionalNode<T> * next;
  BidirectionalNode<T> * prev;
 public:
  BidirectionalNode<T>();
  BidirectionalNode<T>(T value): value(value) {}
  void setValue(T value);
  void setNext(BidirectionalNode<T> *next);
  void setPrev(BidirectionalNode<T> *prev);
  T getValue() const;
  BidirectionalNode<T> *getNext() const;
  BidirectionalNode<T> *getPrev() const;
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
  DoublyLinkedList();
  ~DoublyLinkedList();
  void append(Node<T> * node);
  void prepend(Node<T> * node);
  void insertBefore(Node<T> * refNode, Node<T> * nodeToInsert);
  void insertAfter(Node<T> * refNode, Node<T> * nodeToInsert);
  void remove(Node<T> *node);
  Node<T> *search(T value);
  int size();
  bool isEmpty();
  void print();
};

#endif