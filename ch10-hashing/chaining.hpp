/*
 * Make a sample hash table
 * Use simple modulo hash function
 * Use chaining
 */

#ifndef CHAINING_HPP
#define CHAINING_HPP

class Node {
  int key;
  int value;
  Node *next;
 public:
  Node(int key, int value);
  int getKey() const;
  int getValue() const;
  void setNext(Node *next);
  Node *getNext() const;
};

// HashTable
// chaining
class HashTable {
  int capacity;
  Node **buckets;  // 1D array of pointers to linked lists
  int hashFunction(int key);
 public:
  HashTable(int capacity = 100);
  ~HashTable();
  void set(int key, int value);
  bool remove(int key);
  int lookUp(int key);
};

#endif  // CHAINING_HPP
