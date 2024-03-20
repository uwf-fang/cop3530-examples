/**
 * @brief A singly-linked list class template demonstrating
 *    insertion sort
 *    merge sort
 */
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <vector>

template <typename T>
struct Node {
  T value;
  Node<T> *next;
  Node() : value(), next(nullptr) {}
};

template <typename T>
class LinkedList {
  Node<T> *head;
  // insertion sort helper
  void sortedInsert(Node<T> *node);
  // merge sort helpers
  Node<T> *splitMiddle(Node<T> *head);
  Node<T> *sortedMerge(Node<T> *l1, Node<T> *l2);
  Node<T> *mergeSortHelper(Node<T> *head);
  void printAll(Node<T> *head) const;

 public:
  LinkedList();
  // This method allows initialization using {}
  ~LinkedList();
  bool isEmpty() const;
  void append(T value);
  void insertionSort();
  void mergeSort();
  void printAll() const;
  std::vector<T> toVector() const;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
bool LinkedList<T>::isEmpty() const {
  return head == nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T> *current = head;
  Node<T> *next;
  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const {
  std::vector<T> result;
  Node<T> *current = head;
  while (current != nullptr) {
    result.push_back(current->value);
    current = current->next;
  }
  return result;
}

template <typename T>
void LinkedList<T>::printAll() const {
  printAll(head);
}

template <typename T>
void LinkedList<T>::printAll(Node<T> *head) const {
  Node<T> *current = head;
  while (current != nullptr) {
    std::cout << (current->value) << ' ';
    current = current->next;
  }
  std::cout << std::endl;
}

// Inefficient but works
// Ideally, we should use doubly linked list with a tail pointer
template <typename T>
void LinkedList<T>::append(T value) {
  Node<T> *node;
  node = new Node<T>();
  node->value = value;
  node->next = nullptr;
  // empty list
  if (head == nullptr) {
    head = node;
  } else {
    Node<T> *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = node;
  }
}

// Insertion sort for linked list
//   is out-of-place
template <typename T>
void LinkedList<T>::insertionSort() {
  Node<T> *newHead = head;
  head = nullptr;
  Node<T> *current = newHead;
  Node<T> *next;

  // Repeatedly insert current head node to the new list
  while (current != nullptr) {
    next = current->next;
    current->next = nullptr;
    sortedInsert(current);
    current = next;
  }
}

// An essential part of insertion sort
// Useful in other algorithms as well
template <typename T>
void LinkedList<T>::sortedInsert(Node<T> *node) {
  // insert to empty list or insert before the first node
  if (head == nullptr || node->value <= head->value) {
    node->next = head;
    head = node;
  } else {
    Node<T> *current = head;
    // find the node to insert after or the tail node
    while (current->next != nullptr && current->next->value < node->value)
      current = current->next;
    node->next = current->next;
    current->next = node;
  }
}

template <typename T>
void LinkedList<T>::mergeSort() {
  head = mergeSortHelper(head);
}

template <typename T>
Node<T> *LinkedList<T>::mergeSortHelper(Node<T> *head) {
  if (head == nullptr || head->next == nullptr) return head;
  Node<T> *middle = splitMiddle(head);
  head = mergeSortHelper(head);
  // std::cout << "head: ";
  // printAll(head);
  middle = mergeSortHelper(middle);
  // std::cout << "middle: ";
  // printAll(middle);
  Node<T> *result = sortedMerge(head, middle);
  // std::cout << "result: ";
  // printAll(result);
  return result;
}

// Split the list into two halves
//  return the head of the second half
//  the first half is the original list
template <typename T>
Node<T> *LinkedList<T>::splitMiddle(Node<T> *head) {
  Node<T> *slow = head;
  Node<T> *fast = head->next;
  Node<T> *result;

  while (fast != nullptr) {
    fast = fast->next;
    if (fast == nullptr) break;
    fast = fast->next;
    slow = slow->next;
  }
  result = slow->next;
  slow->next = nullptr;
  return result;
}

// Recursive sorted merge
template <typename T>
Node<T> *LinkedList<T>::sortedMerge(Node<T> *l1, Node<T> *l2) {
  Node<T> *result = nullptr;

  if (l1 == nullptr) return l2;
  if (l2 == nullptr) return l1;

  if (l1->value <= l2->value) {
    result = l1;
    result->next = sortedMerge(l1->next, l2);
  } else {
    result = l2;
    result->next = sortedMerge(l1, l2->next);
  }
  return result;
}

#endif
