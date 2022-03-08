// Linked list with sorting algorithm

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <class T>
class Node {
 public:
  T value;
  Node<T> *next;
};

template <class T>
class LinkedList {
 private:
  Node<T> *head;
  // insert node
  void sortedInsert(Node<T> *node);
 public:
  LinkedList();
  ~LinkedList();
  void append(T value);
  int size();
  // insertion sort
  void insertionSort();
  void printAll();
};

template <class T>
LinkedList<T>::LinkedList(): head(nullptr){}

template <class T>
LinkedList<T>::~LinkedList() {
  Node<T> *current = head;
  Node<T> *next;
  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }
}

template <class T>
int LinkedList<T>::size() {
  int size = 0;
  Node<T> *current = head;
  while (current != nullptr) {
    size++;
    current = current->next;
  }
  return size;
}

template <class T>
void LinkedList<T>::printAll() {
  Node<T> *current = head;
  while (current->next != nullptr) {
    std::cout << (current->value) << ' ';
    current = current->next;
  }
  std::cout << (current->value) << std::endl;
}

template <class T>
void LinkedList<T>::append(T value) {
  Node<T> *node;
  node = new Node<T>();
  node->value = value;
  node->next = nullptr;
  // empty list
  if (head == nullptr) {
    head = node;
  }
  else {
    Node<T> *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = node;
  }
}

template <class T>
void LinkedList<T>::insertionSort() {
  Node<T> * newHead = head;
  head = nullptr;
  Node<T> * current = newHead;
  Node<T> * next;

  while (current != nullptr) {
    next = current->next;
    current->next = nullptr;
    sortedInsert(current);
    current = next;
  }
}

template <class T>
void LinkedList<T>::sortedInsert(Node<T> * node) {
  // insert to empty list or insert before the first node
  if (head == nullptr || node->value <= head->value) {
    node->next = head;
    head = node;
  }
  else {
    Node<T> *current = head;
    // find the node to insert after or the tail node
    while (current->next != nullptr && current->next->value < node->value)
      current = current->next;
    node->next = current->next;
    current->next = node;
  }
}

#endif
