// Demonstration of a list ADT implementation using a singly-linked list
// Header only module for class templates
#ifndef SINGLY_HPP
#define SINGLY_HPP

#include <iostream>
#include <stdexcept>

// Node structure for singly-linked list
template <typename T>
struct Node {
  T data;            // Data stored in the node
  Node<T> *next;     // Pointer to the next node
  Node(T val) : data(val), next(nullptr) {}
};

// Singly-linked list class
template <typename T>
class SinglyLinkedList {
  Node<T> *head;   // Pointer to the first node in the list
  int size_;       // Number of elements in the list

 public:
  // Default constructor: creates an empty list
  SinglyLinkedList() : head(nullptr), size_(0) {}

  // Copy constructor: creates a deep copy of another list
  SinglyLinkedList(const SinglyLinkedList<T> &other) : head(nullptr), size_(0) {
    if (other.isEmpty()) return;
    head = new Node<T>(other.head->data); // Copy first node
    ++size_;
    Node<T> *curr = head;
    Node<T> *otherCurr = other.head->next;
    // Copy the rest of the nodes
    while (otherCurr) {
      curr->next = new Node<T>(otherCurr->data);
      curr = curr->next;
      otherCurr = otherCurr->next;
      ++size_;
    }
  }

  // copy assignment operator
  // Copy assignment operator: deletes current list and copies from another
  SinglyLinkedList<T> &operator=(const SinglyLinkedList<T> &other) {
    if (this == &other) return *this; // Self-assignment check
    // Delete current list
    while (head) {
      Node<T> *tmp = head;
      head = head->next;
      delete tmp;
    }
    size_ = 0;
    if (!other.head) return *this;
    head = new Node<T>(other.head->data); // Copy first node
    ++size_;
    Node<T> *curr = head;
    Node<T> *otherCurr = other.head->next;
    // Copy the rest of the nodes
    while (otherCurr) {
      curr->next = new Node<T>(otherCurr->data);
      curr = curr->next;
      otherCurr = otherCurr->next;
      ++size_;
    }
    return *this;
  }

  // Destructor: deletes all nodes to free memory
  ~SinglyLinkedList() {
    while (head) {
      Node<T> *tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  // Appends a new node with given data to the end of the list
  void append(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (!head) {
      head = newNode; // List was empty
    } else {
      Node<T> *curr = head;
      while (curr->next) curr = curr->next; // Traverse to last node
      curr->next = newNode;
    }
    ++size_;
  }

  // Inserts a new node with given data before the specified index
  void insertBefore(int index, T data) {
    if (index < 0 || index > size_) return; // index out of bounds
    if (index == 0) {
      Node<T> *newNode = new Node<T>(data);
      newNode->next = head;
      head = newNode;
      ++size_;
      return;
    }
    Node<T> *curr = head;
    // Traverse to the node before the index
    for (int i = 0; i < index - 1; ++i) {
      curr = curr->next;
    }
    Node<T> *newNode = new Node<T>(data);
    newNode->next = curr->next;
    curr->next = newNode;
    ++size_;
  }

  // Removes the node at the specified index
  void remove(int index) {
    if (index < 0 || index >= size_) return; // index out of bounds
    if (!head) return; // List is empty
    if (index == 0) {
      Node<T> *tmp = head;
      head = head->next;
      delete tmp;
      --size_;
      return;
    }
    Node<T> *curr = head;
    // Traverse to the node before the one to remove
    for (int i = 0; i < index - 1; ++i) {
      curr = curr->next;
    }
    Node<T> *tmp = curr->next;
    curr->next = tmp->next;
    delete tmp;
    --size_;
  }

  // Searches for the first occurrence of value and returns its index, or -1 if not found
  int search(const T &value) const {
    Node<T> *curr = head;
    int idx = 0;
    while (curr) {
      if (curr->data == value) return idx;
      curr = curr->next;
      ++idx;
    }
    return -1; // not found
  }

  T get(int index) const {
    if (index < 0 || index >= size_) throw std::out_of_range("Index out of bounds");
    Node<T> *curr = head;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return curr->data;
  }

  int size() const { return size_; }

  bool isEmpty() const { return size_ == 0; }

  // Prints all elements in the list to standard output
  void traverse() const {
    Node<T> *curr = head;
    while (curr) {
      std::cout << curr->data << " ";
      curr = curr->next;
    }
    std::cout << std::endl;
  }
};
#endif // SINGLY_HPP
