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
  Node();
  Node(int key, int value);
  int getKey() const;
  int getValue() const;
  void setNext(Node *next);
  Node *getNext() const;
};

// HashMap
// chaining
class HashMap {
  int capacity;
  int size;
  Node **buckets;  // 1D array of pointers to linked lists
  int hashFunction(int key) const;
 public:
  HashMap(int capacity = 101);
  ~HashMap();
  void resize(int newCapacity); // rehashing
  void put(int key, int value);
  bool remove(int key);
  int get(int key) const;
  int size() const;
};

#endif  // CHAINING_HPP
