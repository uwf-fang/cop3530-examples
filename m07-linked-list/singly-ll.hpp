/**
 * Demonstration of a list ADT implementation using a singly-linked list
 *
 * Header only module for class templates
 * Both inline and out-of-line methods are shown for learning purpose
 */
#ifndef SINGLY_LL_HPP
#define SINGLY_LL_HPP

#include <iostream>

// A top-level class for a node in a singly-linked list
// Make instance variables private and provide public methods to access them
template <typename T>
class Node {
  T value;
  Node<T> *next;
 public:
  Node<T>();
  Node<T>(T value) : value(value), next(nullptr) {};
  void setNext(Node<T> *next) { this->next = next; }
  Node<T> *getNext() { return next; }
  T getValue() { return value; }
  void setValue(T value) { this->value = value; }
};

// A singly-linked list implementing List ADT
// a head pointer, a tail pointer
// a next pointer in node class
// Showing both inline and out-of-line methods for learning purpose
template <typename T>
class SinglyLinkedList {
  Node<T> *head;
  Node<T> *tail;

 public:
  // out-of-line methods
  void insertAfter(Node<T> *node, Node<T> *newNode);
  void prepend(Node<T> *node);
  void remove(Node<T> *node);
  Node<T> *search(T value);

  // inline methods
  SinglyLinkedList() : head(nullptr), tail(nullptr) {}

  SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr), tail(nullptr) {
    // Deep copy
    Node<T> *curr = head;
    Node<T> *otherCurr = other.head;

    if (otherCurr == nullptr) {
      return;
    }

    head = new Node<T>(otherCurr->getValue());
    curr = head;
    otherCurr = otherCurr->getNext();

    while (otherCurr != nullptr) {
      curr->setNext(new Node<T>(otherCurr->getValue()));
      curr = curr->getNext();
      otherCurr = otherCurr->getNext();
    }

    curr->setNext(nullptr);
    tail = curr;
  }

  SinglyLinkedList &operator=(const SinglyLinkedList &other) {
    if (this == &other) {
      return *this;
    }

    // delete all nodes in the current list
    while (!isEmpty())
      remove(head);
    head = nullptr;
    tail = nullptr;

    // deep copy
    Node<T> *otherCurr = other.head;

    if (otherCurr == nullptr) {
      return *this;
    }

    head = new Node<T>(otherCurr->getValue());
    Node<T> *curr = head;
    otherCurr = otherCurr->getNext();

    while (otherCurr != nullptr) {
      curr->setNext(new Node<T>(otherCurr->getValue()));
      curr = curr->getNext();
      otherCurr = otherCurr->getNext();
    }

    curr->setNext(nullptr);
    tail = curr;

    return *this;
  }

  ~SinglyLinkedList() {
    Node<T> *curr = head;
    Node<T> *temp;
    while (curr != nullptr) {
      temp = curr;
      curr = curr->getNext();
      delete temp;
    }

    // Alternative way to delete all nodes

    // while (!isEmpty()) {
    //   remove(head);
    // }
  }
  bool isEmpty() { return head == nullptr; }

  int size() {
    int count = 0;
    Node<T> *curr = head;
    while (curr != nullptr) {
      ++count;
      curr = curr->getNext();
    }
    return count;
  }

  void traverse() {
    Node<T> *curr = head;
    while (curr != nullptr) {
      std::cout << curr->getValue() << " ";
      curr = curr->getNext();
    }
    std::cout << std::endl;
  }

};

// Out-of-line method definitions
template <typename T>
void SinglyLinkedList<T>::prepend(Node<T> *node) {
  if (head == nullptr) {  // empty list
    head = node;
    tail = node;
  } else {
    node->setNext(head);
    head = node;
  }
}

template <typename T>
void SinglyLinkedList<T>::insertAfter(Node<T> *node, Node<T> *newNode) {
  newNode->setNext(node->getNext());
  node->setNext(newNode);
  if (node == tail) // inserting after the last node
    tail = newNode;
}

template <typename T>
void SinglyLinkedList<T>::remove(Node<T> *node) {
  // Assuming that the node exist in the list
  Node<T> *prevNode;
  if (node == head) {  // removing first node
    head = head->getNext();
  } else {
    prevNode = head;
    // find the previous node,
    // assuming always able to find a match
    while (prevNode->getNext() != node)
      prevNode = prevNode->getNext();
    prevNode->setNext(node->getNext());
  }

  // removing last node, can happen at the same time as the operations
  //   covered in the last if-else block
  if (node == tail)
    tail = prevNode;

  // ALWAYS delete the node
  delete node;
}

template <typename T>
Node<T> *SinglyLinkedList<T>::search(T value) {
  Node<T> *curr = head;
  while (curr != nullptr) {
    if (curr->getValue() == value)
      return curr;  // find a match
    curr = curr->getNext();
  }
  return nullptr;
}

#endif // SINGLY_LL_HPP
