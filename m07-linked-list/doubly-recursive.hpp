#ifndef DOUBLY_RECURSIVE_HPP
#define DOUBLY_RECURSIVE_HPP

# include <iostream>

template <typename T>
class DoublyLinkedList1 {

  struct DNode {
    T data;
    DNode* prev;
    DNode* next;
    DNode(T val) : data(val), prev(nullptr), next(nullptr) {}
  };

  DNode* head;
  DNode* tail;
  int size_;

  void deleteHelper(DNode* node) {
    if (node == nullptr) return;
    deleteHelper(node->next);
    delete node;
  }

  void traverseHelper(DNode* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    traverseHelper(node->next);
  }

  T getNodeHelper(DNode* node, int index) const {
    if (node == nullptr) return T(); // Return default value if node is null
    if (index == 0) return node->data;
    return getNodeHelper(node->next, index - 1);
  }

  DNode* deepCopyHelper(DNode* node) {
    if (node == nullptr) return nullptr;
    DNode* newNode = new DNode(node->data);
    newNode->next = deepCopyHelper(node->next);
    if (newNode->next != nullptr)
      newNode->next->prev = newNode;
    return newNode;
  }

  void insertHelper(DNode* node, int index, T data) {
    if (node == nullptr) return;

    if (index == 0) {
      DNode* newNode = new DNode(data);
      newNode->prev = node->prev;
      newNode->next = node;

      if (node->prev) {
        node->prev->next = newNode;
      } else {
        head = newNode;
      }

      node->prev = newNode;
      return;
    }

    insertHelper(node->next, index - 1, data);
  }

 public:
  DoublyLinkedList1() : head(nullptr), tail(nullptr), size_(0) {}

  void append(T data) {
    DNode* newNode = new DNode(data);
    if (head == nullptr) {
      head =  newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    ++size_;
  }

  void traverse() {
    traverseHelper(head);
    std::cout << std::endl;
  }

  T getNode(int index) const {
    if (index < 0 || index >= size_) return T(); // index out of bounds
    return getNodeHelper(head, index);
  }

  void insertBefore(int index, T data) {
    if (index < 0 || index > size_) return; // index out of bounds

    if (index == size_) {
      append(data);
      return;
    }

    insertHelper(head, index, data);
    ++size_;
  }

  int size() const {
    return size_;
  }

  ~DoublyLinkedList1() {
    deleteHelper(head);
  }

  // Copy constructor
  DoublyLinkedList1(const DoublyLinkedList1& other) : head(nullptr), tail(nullptr), size_(0) {
    head = deepCopyHelper(other.head);
    size_ = other.size_;
  }

  // Copy assignment operator
  DoublyLinkedList1& operator=(const DoublyLinkedList1& other) {
    if (this == &other) return *this;
    deleteHelper(head);
    head = deepCopyHelper(other.head);
    size_ = other.size_;
    return *this;
  }

};

#endif // DOUBLY_RECURSIVE_HPP
