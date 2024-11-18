/**
 * A hash map (hash table implementation of Map ADT) using chaining
 * Use simple modulo hash function
 *
 * WARNING: Declarations only! Not implemented!
 */

#ifndef CHAINING_HPP
#define CHAINING_HPP

#include <list>
#include <vector>

// HashMap
// chaining
class HashMap1 {
  struct Node {
    int key;
    int value;
    Node *next;
  };
  int capacity;
  int size;
  Node **buckets;  // 1D array of pointers to linked lists
  int hashFunction(int key) const;
 public:
  HashMap1(int capacity = 101);  // prime number
  HashMap1(const HashMap1 &other);
  HashMap1 &operator=(const HashMap1 &other);
  ~HashMap1();
  void resize(int newCapacity); // rehashing
  void put(int key, int value);
  bool remove(int key);
  int get(int key) const;
  int size() const;
};

// HashMap
// chaining using vector and lists
class HashMap2 {
  std::vector<std::list<std::pair<int, int>>> buckets;
  int capacity;
  int size;
  int hashFunction(int key) const;
 public:
  HashMap2(int capacity = 101);  // prime number
  ~HashMap2();
  void resize(int newCapacity); // rehashing
  void put(int key, int value);
  bool remove(int key);
  int get(int key) const;
  int size() const;
};

#endif  // CHAINING_HPP
