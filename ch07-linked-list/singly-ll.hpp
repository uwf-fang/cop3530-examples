#ifndef SINGLY_LL_HPP
#define SINGLY_LL_HPP

#include <iostream>

template<class T>
class Node {
 public:
  T value;
  Node<T> * next;
  Node<T>();
  Node<T>(T value): value(value) {};
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
  SinglyLinkedList(): head(nullptr), tail(nullptr) {}
  void append(Node<T> * node) {
    if (head == nullptr) {
      head = node;
      tail = node;
    }
    else {
      tail->next = node;
      tail = node;
    }
  }
  void prepend(Node<T> * node);
  void insertAfter(Node<T> * node, Node<T> * newNode);
  // remove the specified node
  void remove(Node<T> *node);
  Node<T> *search(T value);
  bool isEmpty() {
    return head == nullptr;
  }
  int length() {
    int count = 0;
    Node<T> * node = head;
    while (node != nullptr) {
      ++count;
      node = node->next;
    }
    return count;
  }
  void print() {
    Node<T> * node = head;
    while (node != nullptr) {
      std::cout << node->value << " ";
      node = node->next;
    }
    std::cout << std::endl;
  }
  ~SinglyLinkedList() {
    Node<T> *node = head;
    Node<T> *next;
    while (node != nullptr) {
      next = node->next;
      delete node;
      node = next;
    }
  }
};

template <class T>
void SinglyLinkedList<T>::prepend(Node<T> * node) {
  if (head == nullptr) append(node);
  else {
    node->next = head;
    head = node;
  }
}

template <class T>
void SinglyLinkedList<T>::insertAfter(Node<T> * node, Node<T> * newNode) {
  if (head == nullptr) append(node);
  else if (node == tail) {
    tail->next = newNode;
    tail = newNode;
  }
  else {
    newNode->next = node->next;
    node->next = newNode;
  }
}

template <class T>
void SinglyLinkedList<T>::remove(Node<T> * node) {
  if (node == head) {
    head = head->next;
    return;
  }
  Node<T> * prevNode = head;
  while (true) {
    if (prevNode -> next == nullptr)
      return;  // found no match, should not be here
    if (prevNode->next == node) {
      break;
    }
    prevNode = prevNode->next;
  }
  prevNode->next = node->next;
  if (node == tail) {
    tail = prevNode;
  }
  delete node;
}

template <class T>
Node<T> * SinglyLinkedList<T>::search(T value) {
  Node<T> * node = head;
  if (head == nullptr) return nullptr;
  while (node != nullptr) {
    if (node->value == value) return node;  // find a match
    node = node->next;
  }
  return nullptr;
}






#endif