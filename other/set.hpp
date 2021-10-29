/**
 * Set implementation
 * Simplified by using dynamic array rather than linked list
 * NOT HASH TABLE BASED!
 */

#ifndef SANDBOX_SET_HPP
#define SANDBOX_SET_HPP

#include <string>

using std::string;

class Set {
    static const int INCREMENT = 100;
    int *storage;  // dynamic array
    int capacity;  // the max size
    int size;      // the effective size
public:
    Set();
    ~Set();
    void add(int value);
    void remove(int value);
    bool exist(int value);
    Set intersect(Set &other);  // return a new set
    Set setAdd(Set &other);  // union is a keyword in c++
    Set difference(Set &other);
    string to_str();
};

#endif //SANDBOX_SET_HPP
