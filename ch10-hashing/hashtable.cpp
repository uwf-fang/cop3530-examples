/*
 * Make a sample hash table
 * Use simple modulo hash function
 * Use simple linear probing
 */

#include <iostream>
#include "hashtable.hpp"

using std::cerr;

HashTable::HashTable() {
    buckets = new Bucket[NUM_BUCKETS];
}

HashTable::~HashTable() {
    delete [] buckets;
}

int HashTable::hashFunction(int key) {
    return key % NUM_BUCKETS;
}

void HashTable::set(int key, int value) {
    int bucketIdx = this->hashFunction(key);
    while (!buckets[bucketIdx].isEmpty()) {
        bucketIdx = nextIndex(bucketIdx);
        if (bucketIdx < 0) {
            cerr << "error, probing failed\n";
            return;
        }
    }
    buckets[bucketIdx].set(key, value);
}

void HashTable::remove(int key) {
    int bucketIdx = this->hashFunction(key);
    while (buckets[bucketIdx].getKey() != key && !buckets[bucketIdx].isEmptySinceStart())
        bucketIdx = nextIndex(bucketIdx);
    if (buckets[bucketIdx].isEmptySinceStart()) {
        cerr << "No match found!\n";
        return;
    }
    buckets[bucketIdx].remove();
}

int HashTable::lookUp(int key) {
    int bucketIdx = this->hashFunction(key);
    while (buckets[bucketIdx].getKey() != key && !buckets[bucketIdx].isEmptySinceStart())
        bucketIdx = nextIndex(bucketIdx);
    if (buckets[bucketIdx].isEmptySinceStart()) {
        cerr << "No match found!\n";
        return -1;
    }
    return buckets[bucketIdx].getValue();
}

int HashTable::nextIndex(int index) {
    if (index < NUM_BUCKETS - 1)
        return index + 1;
    return -1;  // reached the last bucket, linear probing failed
}

Bucket::Bucket() : key(0), value(0), emptySinceStart(true), emptySinceRemoval(false) {}

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

bool Bucket::isEmptySinceStart() const {
    return emptySinceStart;
}

bool Bucket::isEmptySinceRemoval() const {
    return emptySinceRemoval;
}

bool Bucket::isEmpty() const {
    return isEmptySinceStart() || isEmptySinceRemoval();
}

int Bucket::getKey() const {
    return key;
}

int Bucket::getValue() const {
    return value;
}



