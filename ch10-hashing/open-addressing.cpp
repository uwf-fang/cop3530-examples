/*
 * Make a sample hash table
 * Use simple modulo hash function
 * Use simple linear probing
 */

#include "open-addressing.hpp"

#include <iostream>

HashMap::HashMap(int capacity):
    capacity(capacity),
    size_(0),
    buckets(new Bucket[capacity])
    {}

HashMap::~HashMap() { delete[] buckets; }

int HashMap::hashFunction(int key) const {
  return key % capacity;
}

bool HashMap::put(int key, int value) {
  if (size_ == capacity) return false; // full hash table
  if (get(key) != -1) return false; // key already exist
  int probed = 0;
  int hash = hashFunction(key);
  int bucketIdx = hash;
  while (probed < capacity) {
    if (buckets[bucketIdx].isEmpty()) {
      buckets[bucketIdx].set(key, value);
      ++size_;
      return true;
    }
    ++probed;
    bucketIdx = probe(hash, probed);
  }
  return false;
}

bool HashMap::remove(int key) {
  if (size_ == 0) return false; // empty hash table
  int probed = 0;
  int hash = hashFunction(key);
  int bucketIdx = hash;
  while (!buckets[bucketIdx].isEmptySinceStart() && probed < capacity) {
    if (!buckets[bucketIdx].isEmpty() && buckets[bucketIdx].getKey() == key) {
      buckets[bucketIdx].remove();
      --size_;
      return true;
    }
    ++probed;
    bucketIdx = probe(hash, probed);
  }
  return false;  // cannot find
}

int HashMap::get(int key) const {
  int probed = 0;
  int hash = hashFunction(key);
  int bucketIdx = hash;
  while (!buckets[bucketIdx].isEmptySinceStart() && probed < capacity) {
    if (!buckets[bucketIdx].isEmpty() && buckets[bucketIdx].getKey() == key)
      return buckets[bucketIdx].getValue();
    ++probed;
    bucketIdx = probe(hash, probed);
  }
  return -1;  // special value to encode "key not found error"
}

int HashMap::size() const { return size_; }

// simplest linear probing
// probed is i in the formula
int HashMap::probe(int hash, int probed) const {
  return (hash + 1 * probed) % capacity;
}

Bucket::Bucket()
    : key(0), value(0), emptySinceStart(true), emptyAfterRemoval(false) {}

void Bucket::set(int key, int value) {
  this->key = key;
  this->value = value;
  emptySinceStart = false;
}

void Bucket::remove() {
  key = 0;
  value = 0;
  emptyAfterRemoval = true;
}

bool Bucket::isEmptySinceStart() const { return emptySinceStart; }

bool Bucket::isEmptyAfterRemoval() const { return emptyAfterRemoval; }

bool Bucket::isEmpty() const {
  return isEmptySinceStart() || isEmptyAfterRemoval();
}

int Bucket::getKey() const { return key; }

int Bucket::getValue() const { return value; }
