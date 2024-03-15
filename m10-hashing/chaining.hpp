/**
 * A hash map (hash table implementation of Map ADT) using chaining
 * Use simple modulo hash function
 *
 * WARNING: Declarations only! Not implemented!
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
  HashMap(int capacity = 101);  // prime number
  HashMap(const HashMap &other);
  HashMap &operator=(const HashMap &other);
  ~HashMap();
  void resize(int newCapacity); // rehashing
  void put(int key, int value);
  bool remove(int key);
  int get(int key) const;
  int size() const;
};

#endif  // CHAINING_HPP
