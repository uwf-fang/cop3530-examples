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
  bool emptySinceRemoval;
 public:
  Bucket();
  void set(int key, int value);
  void remove();
  bool isEmptySinceStart() const;
  bool isEmptySinceRemoval() const;
  bool isEmpty() const;
  int getKey() const;
  int getValue() const;
};

// HashTable
// Linear probing
class HashTable {
  int capacity;
  Bucket *buckets;
  int hashFunction(int key);
  // probing algorithm
  int probe(int hash, int probed);

 public:
  HashTable(int capacity = 101);  // have default constructor covered
  ~HashTable();
  bool set(int key, int value);
  bool remove(int key);
  int lookUp(int key);
};

#endif  // OPEN_ADDRESSING_HPP
