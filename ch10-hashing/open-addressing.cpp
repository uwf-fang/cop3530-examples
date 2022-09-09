/*
 * Make a sample hash table
 * Use simple modulo hash function
 * Use simple linear probing
 */

#include "open-addressing.hpp"

#include <iostream>

using std::cerr;

HashTable::HashTable(int capacity): capacity(capacity), buckets(new Bucket[capacity]) {}

HashTable::~HashTable() { delete[] buckets; }

int HashTable::hashFunction(int key) { return key % capacity; }

bool HashTable::set(int key, int value) {
  int probed = 0;
  int hash = this->hashFunction(key);
  int bucketIdx = probe(hash, probed);
  while (probed < capacity) {
    if (buckets[bucketIdx].isEmpty()) {
      buckets[bucketIdx].set(key, value);
      return true;
    }
    ++probed;
    bucketIdx = probe(bucketIdx, probed);
  }
  return false;
}

bool HashTable::remove(int key) {
  int probed = 0;
  int hash = this->hashFunction(key);
  int bucketIdx = probe(hash, probed);
  while (!buckets[bucketIdx].isEmptySinceStart() && probed < capacity) {
    if (!buckets[bucketIdx].isEmpty() && buckets[bucketIdx].getKey() == key) {
      buckets[bucketIdx].remove();
      return true;
    }
    ++probed;
    bucketIdx = probe(bucketIdx, probed);
  }
  return false;
}

int HashTable::lookUp(int key) {
  int probed = 0;
  int hash = this->hashFunction(key);
  int bucketIdx = probe(hash, probed);
  while (!buckets[bucketIdx].isEmptySinceStart() && probed < capacity) {
    if (!buckets[bucketIdx].isEmpty() && buckets[bucketIdx].getKey() == key)
      return buckets[bucketIdx].getValue();
    ++probed;
    bucketIdx = probe(bucketIdx, probed);
  }
  return -1;
}

int HashTable::probe(int hash, int probed) {
  return (hash + 1 * probed) % capacity;
}

Bucket::Bucket()
    : key(0), value(0), emptySinceStart(true), emptySinceRemoval(false) {}

void Bucket::set(int key, int value) {
  this->key = key;
  this->value = value;
  emptySinceStart = false;
}

void Bucket::remove() {
  key = 0;
  value = 0;
  emptySinceRemoval = true;
}

bool Bucket::isEmptySinceStart() const { return emptySinceStart; }

bool Bucket::isEmptySinceRemoval() const { return emptySinceRemoval; }

bool Bucket::isEmpty() const {
  return isEmptySinceStart() || isEmptySinceRemoval();
}

int Bucket::getKey() const { return key; }

int Bucket::getValue() const { return value; }
