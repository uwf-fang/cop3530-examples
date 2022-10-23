#include <iostream>
#include <cassert>
#include "open-addressing.hpp"

using namespace std;

void testOpenAddressing();

int main() {
    testOpenAddressing();
}

void testOpenAddressing() {
    cout << "Testing open addressing hash table class\n";
    HashTable hash;
    assert(hash.set(10, 20));
    assert(hash.set(110, 30));  // collision
    assert(hash.lookUp(10) == 20);  // gives 20
    assert(hash.lookUp(110) == 30); // gives 30
    assert(hash.lookUp(11) == -1); // gives -1, no match
    assert(hash.remove(110));  // found and succeed
    assert(!hash.remove(1));  // not found and fail
    assert(hash.lookUp(110)); // gives -1, no match after removal
    cout << "All tests passed!\n";
}