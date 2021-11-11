#include <iostream>
using namespace std;


class Node {
 public:
  int value;
  Node *prev;
  Node *next;
};

class Queue {
 private:
  Node *head;
  Node *tail;
 public:
  Queue();
  ~Queue();
  void push(int value);
  int pop();
  int peek();
};

Queue::Queue() {
  head = nullptr;
  tail = nullptr;
}

Queue::~Queue() {
  Node *node = head;
  Node *next;
  while (node != nullptr) {
    next = node->next;
    delete node;
    node = next;
  }
}

void Queue::push(int value) {
  Node *node = new Node;
  node->value = value;
  node->next = nullptr;
  node->prev = nullptr;
  if (head == nullptr) {
    head = node;
    tail = node;
    return;
  }
  head->prev = node;
  node->next = head;
  head = node;
}

int Queue::pop() {
  if (head == nullptr)
    return -1;
  Node *secondLast = tail->prev;
  int value = tail->value;
  delete tail;
  tail = secondLast;
  if (tail == nullptr)  // if second last not exist, the queue is empty
    head = nullptr;
  else
    tail->next = nullptr;
  return value;
}

int Queue::peek() {
  if (head == nullptr)
    return -1;
  return tail->value;
}

// this is not part of the solution, just for testing
int main() {
  Queue myQ;
  cout << "pushing 1" << endl;
  myQ.push(100);
  cout << "pushing 2" << endl;
  myQ.push(200);
  cout << "peek 1 " << myQ.peek() << endl;
  cout << "pop 1 " << myQ.pop() << endl;
  cout << "pop 2 " << myQ.pop() << endl;
  cout << "pop 3 " << myQ.pop() << endl;
}