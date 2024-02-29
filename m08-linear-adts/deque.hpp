#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <stdexcept>

// An example of a Deque implemented as a doubly-linked list
//
// Optional method: size()
//
// It has all functionalities of a Queue and a Stack
template <typename T>
class Deque {
  struct Node {
    T value;
    Node* next;
    Node* prev;

    Node(const T& value) : value(value), next(nullptr), prev(nullptr) {}
  };

  Node* head;
  Node* tail;
  int count;

 public:
  Deque() : head(nullptr), tail(nullptr), count(0) {}

  ~Deque() {
    while (!isEmpty())
      dequeueFront();
  }

  Deque(const Deque& other): 
      head(nullptr), 
      tail(nullptr), 
      count(0) {

    Node* curr = other.head;
    while (curr != nullptr) {
      enqueueBack(curr->value);
      curr = curr->next;
    }
  }

  Deque & operator=(const Deque& other) {
    clear();
    Node* curr = other.head;
    while (curr != nullptr) {
      enqueueBack(curr->value);
      curr = curr->next;
    }
    return *this;
  }

  bool isEmpty() const { return count == 0; }

  int size() const { return count; }

  void clear() {
    Node* curr = head;
    while (curr != nullptr) {
      Node* temp = curr;
      curr = curr->next;
      delete temp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
  }

  void enqueueFront(const T& val) {
    Node* new_node = new Node(val);
    if (isEmpty()) {
      head = new_node;
      tail = new_node;
    } else {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
    }
    ++count;
  }

  void enqueueBack(const T& val) {
    Node* new_node = new Node(val);
    if (isEmpty()) {
      head = new_node;
      tail = new_node;
    } else {
      new_node->prev = tail;
      tail->next = new_node;
      tail = new_node;
    }
    ++count;
  }

  T dequeueFront() {
    if (isEmpty())
      throw std::out_of_range("DoublyLinkedList is isEmpty");
    T value = head->value;
    Node* temp = head;
    head = head->next;
    if (head == nullptr)  // empty after dequeue
      tail = nullptr;
    else
      head->prev = nullptr;
    delete temp;
    --count;
    return value;
  }

  T dequeueBack() {
    if (isEmpty())
      throw std::out_of_range("DoublyLinkedList is isEmpty");
    T value = tail->value;
    Node* temp = tail;
    tail = tail->prev;
    if (tail == nullptr)  // empty after dequeue
      head = nullptr;
    else
      tail->next = nullptr;
    delete temp;
    --count;
    return value;
  }

  // Returning "const T&" will be more efficient but less intuitive
  T front() const {
    if (isEmpty())
      throw std::out_of_range("DoublyLinkedList is isEmpty");
    return head->value;
  }

  // Returning "const T&" will be more efficient but less intuitive
  T back() const {
    if (isEmpty())
      throw std::out_of_range("DoublyLinkedList is isEmpty");
    return tail->value;
  }

};

#endif // DEQUE_HPP
