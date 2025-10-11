// Demonstration of a list ADT implementation using a doubly-linked list
// Header only module for class templates
#ifndef DOUBLY_HPP
#define DOUBLY_HPP

#include <iostream>
#include <stdexcept>

// Node structure for doubly-linked list
template <typename T>
struct DNode {
  T data;          // Data stored in the node
  DNode<T>* prev;  // Pointer to the previous node
  DNode<T>* next;  // Pointer to the next node
  DNode(T val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly-linked list class
template <typename T>
class DoublyLinkedList {
  DNode<T>* head;  // Pointer to the first node
  DNode<T>* tail;  // Pointer to the last node
  int size_;       // Number of elements in the list

 public:
  // Default constructor: creates an empty list
  DoublyLinkedList() : head(nullptr), tail(nullptr), size_(0) {}

  // Copy constructor: deep copy
  DoublyLinkedList(const DoublyLinkedList<T>& other)
      : head(nullptr), tail(nullptr), size_(0) {
    DNode<T>* curr = other.head;
    while (curr) {
      append(curr->data);
      curr = curr->next;
    }
  }

  // Copy assignment operator
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other) {
    if (this == &other) return *this;
    while (head) {
      DNode<T>* tmp = head;
      head = head->next;
      delete tmp;
    }
    tail = nullptr;
    size_ = 0;
    DNode<T>* curr = other.head;
    while (curr) {
      append(curr->data);
      curr = curr->next;
    }
    return *this;
  }

  // Destructor
  ~DoublyLinkedList() {
    while (head) {
      DNode<T>* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  // Appends a new node with given data to the end of the list
  void append(T data) {
    DNode<T>* newNode = new DNode<T>(data);
    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    ++size_;
  }

  // Inserts a new node with given data before the specified index
  void insertBefore(int index, T data) {
    if (index < 0 || index > size_) return;  // index out of bounds
    if (index == 0) {
      DNode<T>* newNode = new DNode<T>(data);
      newNode->next = head;
      if (head) head->prev = newNode;
      head = newNode;
      if (!tail) tail = newNode;
      ++size_;
      return;
    }
    DNode<T>* curr = head;
    for (int i = 0; i < index - 1; ++i) {
      curr = curr->next;
    }
    DNode<T>* newNode = new DNode<T>(data);
    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next) curr->next->prev = newNode;
    curr->next = newNode;
    if (newNode->next == nullptr) tail = newNode;
    ++size_;
  }

  // Removes the node at the specified index
  void remove(int index) {
    if (index < 0 || index >= size_) return;  // index out of bounds
    if (!head) return;
    if (index == 0) {
      DNode<T>* tmp = head;
      head = head->next;
      if (head)
        head->prev = nullptr;
      else
        tail = nullptr;
      delete tmp;
      --size_;
      return;
    }
    DNode<T>* curr = head;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    if (curr->prev) curr->prev->next = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    if (curr == tail) tail = curr->prev;
    delete curr;
    --size_;
  }

  // Searches for the first occurrence of value and returns its index, or -1 if
  // not found
  int search(const T& value) const {
    DNode<T>* curr = head;
    int idx = 0;
    while (curr) {
      if (curr->data == value) return idx;
      curr = curr->next;
      ++idx;
    }
    return -1;
  }

  // Get the value at the specified index
  T get(int index) const {
    if (index < 0 || index >= size_)
      throw std::out_of_range("Index out of bounds");
    DNode<T>* curr = head;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return curr->data;
  }

  // Returns the number of elements in the list
  int size() const { return size_; }

  // Returns true if the list is empty
  bool isEmpty() const { return size_ == 0; }

  // Prints all elements in the list to standard output
  void traverse() const {
    DNode<T>* curr = head;
    while (curr) {
      std::cout << curr->data << " ";
      curr = curr->next;
    }
    std::cout << std::endl;
  }
};

#endif  // DOUBLY_HPP
