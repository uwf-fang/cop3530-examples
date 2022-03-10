/**
 * @brief A linked list class template with insertion sort
 */
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <initializer_list>

template <class T>
struct Node {
  T value;
  Node<T> *next;
};

template <class T>
class LinkedList {
 private:
  Node<T> *head;
  // insertion sort helper
  void sortedInsert(Node<T> *node);
  // merge sort helper
  Node<T> *splitMiddle(Node<T> *head);
  Node<T> *sortedMerge(Node<T> *l1, Node<T> *l2);
  Node<T> *mergeSortHelper(Node<T> *head);
  void printAll(Node<T> *head);

 public:
  LinkedList();
  LinkedList(std::initializer_list<T> l);
  ~LinkedList();
  void append(T value);
  int size();
  void insertionSort();
  void mergeSort();
  void printAll();
};

template <class T>
LinkedList<T>::LinkedList(): head(nullptr){}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> l): head(nullptr) {
  for (T v: l)
    append(v);
}

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

template <class T>
Node<T> *LinkedList<T>::splitMiddle(Node<T> *head) {
  Node<T> *slow = head;
  Node<T> *fast = head->next;
  Node<T> *result;

  while (fast != nullptr) {
    fast = fast->next;
    if (fast == nullptr)
      break;
    fast = fast->next;
    slow = slow->next;
  }
  result = slow->next;
  slow->next = nullptr;
  return result;
}

template <class T>
Node<T> *LinkedList<T>::sortedMerge(Node<T> *l1, Node<T> *l2) {
  Node<T> *result = nullptr;

  if (l1 == nullptr)
    return l2;
  if (l2 == nullptr)
    return l1;

  if (l1->value <= l2->value) {
    result = l1;
    result->next = sortedMerge(l1->next, l2);
  } else {
    result = l2;
    result->next = sortedMerge(l1, l2->next);
  }
  return result;
}

template <class T>
Node<T> *LinkedList<T>::mergeSortHelper(Node<T> *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
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

template <class T>
void LinkedList<T>::mergeSort() {
  head = mergeSortHelper(head);
}

template <class T>
void LinkedList<T>::printAll(Node<T> *head) {
  Node<T> *current = head;
  while (current != nullptr) {
    std::cout << (current->value) << ' ';
    current = current->next;
  }
  std::cout << std::endl;
}

#endif
