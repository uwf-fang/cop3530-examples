/*
 * Make a sample hash table
 * Use simple modulo hash function
 * Use simple linear probing
 */

#ifndef OPEN_ADDRESSING_HPP
#define OPEN_ADDRESSING_HPP

class Bucket {
  int key;
  int value;
  bool emptySinceStart;
  bool emptyAfterRemoval;
 public:
  Bucket();
  void set(int key, int value);
  void remove();
  bool isEmptySinceStart() const;
  bool isEmptyAfterRemoval() const;
  bool isEmpty() const;
  int getKey() const;
  int getValue() const;
};

// HashTable
// Linear probing
// To keep it simple, both key and value are non-negative
class HashMap {
  int capacity;
  int size_;
  Bucket *buckets;
  int hashFunction(int key) const;
  // probing algorithm
  int probe(int hash, int probed) const;

 public:
  HashMap(int capacity = 101);  // have default constructor covered
  ~HashMap();
  bool put(int key, int value);
  bool remove(int key);
  int get(int key) const;
  int size() const;
  void resize(int newCapacity); // rehashing
};

#endif  // OPEN_ADDRESSING_HPP
