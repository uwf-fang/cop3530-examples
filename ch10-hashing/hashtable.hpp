/*
 * Make a sample hash table
 * Use simple modulo hash function
 * Use simple linear probing
 */

#ifndef SANDBOX_HASHTABLE_HPP
#define SANDBOX_HASHTABLE_HPP

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

class HashTable {
    static const int NUM_BUCKETS = 100;
    Bucket *buckets;
    int hashFunction(int key);
    int nextIndex(int index);
public:
    HashTable();
    ~HashTable();
    void set(int key, int value);
    void remove(int key);
    int lookUp(int key);
};


#endif //SANDBOX_HASHTABLE
