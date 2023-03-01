#ifndef DOUBLY_LL_HPP
#define DOUBLY_LL_HPP

#include <cstddef>
#include <stdexcept>

// This implementation is an example of a Deque implemented as a
// doubly-linked list
// It has a functionalities required by a Deque with two additional methods:
//    size check, and remove by value
// It is not an exact Deque for that reason.
template <typename T>
class DoublyLinkedList {
 private:
  struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
  };

  Node* head;
  Node* tail;
  size_t count;  // unsigned int

 public:
  DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

  ~DoublyLinkedList() {
    Node* curr = head;
    while (curr) {
      Node* temp = curr;
      curr = curr->next;
      delete temp;
    }
  }

  bool empty() const { return count == 0; }

  size_t size() const { return count; }

  void clear() {
    Node* curr = head;
    while (curr) {
      Node* temp = curr;
      curr = curr->next;
      delete temp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
  }

  void push_front(const T& val) {
    Node* new_node = new Node(val);
    if (empty()) {
      head = tail = new_node;
    } else {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
    }
    count++;
  }

  void push_back(const T& val) {
    Node* new_node = new Node(val);
    if (empty()) {
      head = tail = new_node;
    } else {
      new_node->prev = tail;
      tail->next = new_node;
      tail = new_node;
    }
    count++;
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("DoublyLinkedList is empty");
    }
    Node* temp = head;
    head = head->next;
    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete temp;
    count--;
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("DoublyLinkedList is empty");
    }
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }
    delete temp;
    count--;
  }

  const T& front() const {
    if (empty()) {
      throw std::out_of_range("DoublyLinkedList is empty");
    }
    return head->data;
  }

  T& front() {
    if (empty()) {
      throw std::out_of_range("DoublyLinkedList is empty");
    }
    return head->data;
  }

  const T& back() const {
    if (empty()) {
      throw std::out_of_range("DoublyLinkedList is empty");
    }
    return tail->data;
  }

  T& back() {
    if (empty()) {
      throw std::out_of_range("DoublyLinkedList is empty");
    }
    return tail->data;
  }

  void remove(const T& val) {
    Node* curr = head;
    while (curr) {
      if (curr->data == val) {
        if (curr == head) {
          pop_front();
        } else if (curr == tail) {
          pop_back();
        } else {
          curr->prev->next = curr->next;
          curr->next->prev = curr->prev;
          delete curr;
          count--;
        }
        return;
      }
      curr = curr->next;
    }
  }
};

#endif