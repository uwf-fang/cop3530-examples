#include "set.hpp"
#include <sstream>

using std::stringstream;

Set::Set() {
    capacity = 100;
    size = 0;
    storage = new int[capacity];
}

Set::~Set() {
    delete [] storage;
}

void Set::add(int value) {
    if (size == capacity) {
        int * newStorage = new int[size + INCREMENT];
        // this is the major drawback of this implementation comparing to a linked list implementation
        for (int i = 0; i < size; i++)
            newStorage[i] = storage[i];
        delete [] storage;
        storage = newStorage;
    }
    if (!exist(value)) {
        storage[size] = value;
        size++;
    }
}

void Set::remove(int value) {
    for (int i = 0; i < size; i++)
        if (storage[i] == value) {
            storage[i] = storage[size - 1];
            size--;
            return;
        }
}

Set Set::intersect(Set &other) {
    Set result;
    for (int i = 0; i < size; i++)
        if (other.exist(storage[i]))
            result.add(storage[i]);
    return result;
}

Set Set::setAdd(Set &other) {
    int i;
    Set result;
    for (i = 0; i < size; i++)
        result.add(storage[i]);
    for (i = 0; i < other.size; i++)
        result.add(other.storage[i]);
    return result;
}

Set Set::difference(Set &other) {
    int i;
    Set result;
    for (i = 0; i < size; i++)
        if (!other.exist(storage[i]))
            result.add(storage[i]);
    return result;
}

bool Set::exist(int value) {
    int i;
    for (i = 0; i < size; i++)
        if (storage[i] == value)
            return true;
    return false;
}

string Set::to_str() {
    if (size == 0)
        return "";
    stringstream ss;
    for (int i = 0; i < size - 1; i++)
        ss << storage[i] << " ";
    ss << storage[size - 1];
    return ss.str();
}

