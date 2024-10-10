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
  Node<T>(): next(nullptr) {}
  Node<T>(T value) : value(value), next(nullptr) {}
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
    if (other.head == nullptr) return;
    deepCopy(other.head);
  }

  void deepCopy(Node<T> *srcHead) {
    // Deep copy
    Node<T> *curr = head;
    Node<T> *otherCurr = srcHead;

    head = new Node<T>(otherCurr->getValue());
    curr = head;
    otherCurr = otherCurr->getNext();

    while (otherCurr != nullptr) {
      T v = otherCurr->getValue();
      Node<T> *newNode = new Node<T>(v);
      curr->setNext(newNode);
      curr = newNode;
      otherCurr = otherCurr->getNext();
    }

    tail = curr;
  }

  void deleteList(Node<T> *head) {
    if (head == nullptr) return;
    Node<T> *next = head->getNext();
    delete head;
    deleteList(next);
  }

  SinglyLinkedList &operator=(const SinglyLinkedList &other) {
    if (this == &other) {
      return *this;
    }
    deleteList(head);
    deepCopy(other.head);
    return *this;
  }

  ~SinglyLinkedList() {
    deleteList(head);

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

  Node<T> *at(int index) {
    Node<T> *curr = head;
    for (int i = 0; i < index; ++i) {
      if (curr == nullptr) return nullptr;
      curr = curr -> getNext();
    }
    return curr;
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

  // node->setNext(head);
  // head = node;
  // if (tail == nullptr)
  //   tail = node;

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
  Node<T> *prevNode = nullptr;
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
