#include <cassert>
#include <iostream>

#include "doubly.hpp"
#include "singly.hpp"

void testSingly() {
  SinglyLinkedList<int> list;
  // Test empty list
  assert(list.size() == 0);
  assert(list.isEmpty());
  assert(list.search(42) == -1);

  // Test append
  list.append(10);
  list.append(20);
  list.append(30);
  assert(list.size() == 3);
  assert(!list.isEmpty());
  assert(list.search(10) == 0);
  assert(list.search(20) == 1);
  assert(list.search(30) == 2);
  assert(list.search(99) == -1);

  // Test insertBefore
  list.insertBefore(0, 5);  // Insert at head
  assert(list.size() == 4);
  assert(list.search(5) == 0);
  list.insertBefore(2, 15);  // Insert in middle
  assert(list.size() == 5);
  assert(list.search(15) == 2);

  // Test remove
  list.remove(0);  // Remove head
  assert(list.size() == 4);
  assert(list.search(5) == -1);
  list.remove(2);  // Remove middle
  assert(list.size() == 3);
  assert(list.search(20) == -1);
  list.remove(2);  // Remove last
  assert(list.size() == 2);
  assert(list.search(30) == -1);
  // Verify remaining elements
  assert(list.search(10) == 0);
  assert(list.search(15) == 1);

  // Test copy constructor
  SinglyLinkedList<int> copyList(list);
  assert(copyList.size() == list.size());
  assert(copyList.search(10) == 0);
  assert(copyList.search(15) == 1);

  // Test assignment operator
  SinglyLinkedList<int> assignList;
  assignList = list;
  assert(assignList.size() == list.size());
  assert(assignList.search(10) == 0);
  assert(assignList.search(15) == 1);
}

void testDoubly() {
  DoublyLinkedList<int> list;
  // Test empty list
  assert(list.size() == 0);
  assert(list.isEmpty());
  assert(list.search(42) == -1);

  // Test append
  list.append(10);
  list.append(20);
  list.append(30);
  assert(list.size() == 3);
  assert(!list.isEmpty());
  assert(list.search(10) == 0);
  assert(list.search(20) == 1);
  assert(list.search(30) == 2);
  assert(list.search(99) == -1);

  // Test insertBefore
  list.insertBefore(0, 5);  // Insert at head
  assert(list.size() == 4);
  assert(list.search(5) == 0);
  list.insertBefore(2, 15);  // Insert in middle
  assert(list.size() == 5);
  assert(list.search(15) == 2);

  // Test remove
  list.remove(0);  // Remove head
  assert(list.size() == 4);
  assert(list.search(5) == -1);
  list.remove(2);  // Remove middle
  assert(list.size() == 3);
  assert(list.search(20) == -1);
  list.remove(2);  // Remove last
  assert(list.size() == 2);
  assert(list.search(30) == -1);
  // Verify remaining elements
  assert(list.search(10) == 0);
  assert(list.search(15) == 1);

  // Test copy constructor
  DoublyLinkedList<int> copyList(list);
  assert(copyList.size() == list.size());
  assert(copyList.search(10) == 0);
  assert(copyList.search(15) == 1);

  // Test assignment operator
  DoublyLinkedList<int> assignList;
  assignList = list;
  assert(assignList.size() == list.size());
  assert(assignList.search(10) == 0);
  assert(assignList.search(15) == 1);
}

int main() {
  testSingly();
  testDoubly();
  std::cout << "All tests passed!\n";
  return 0;
}
