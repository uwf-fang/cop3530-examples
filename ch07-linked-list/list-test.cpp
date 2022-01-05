#include <iostream>

#include "list.hpp"

using namespace std;

void testSinglyLinkedList();

int main() {
  testSinglyLinkedList();
}

void testSinglyLinkedList() {
  SinglyLinkedList<int> l1;

  assert(l1.isEmpty());
  l1.append(new Node<int>(3));
  l1.prepend(new Node<int>(2));
  l1.print();  // 2 3

  assert(l1.search(2) != nullptr);
  assert(l1.length() == 2);
  l1.insert(l1.search(3), new Node<int>(4));
  l1.print();  // 2 3 4
  l1.insert(l1.search(2), new Node<int>(5));
  l1.print();  // 2 5 3 4
  assert(l1.length() == 4);
  l1.remove(l1.search(5));
  l1.print();  // 2 3 4
  assert(l1.length() == 3);
}