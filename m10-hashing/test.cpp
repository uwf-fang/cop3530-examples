#include <iostream>
#include <cassert>
#include "open-addressing.hpp"

using namespace std;

void testOpenAddressing();

int main() {
    testOpenAddressing();
}

void testOpenAddressing() {
    cout << "Testing open addressing hash map class\n";
    HashMap map;
    assert(!map.remove(1));  // remove fail on empty hash map
    assert(map.size() == 0);
    assert(map.put(10, 20));
    assert(map.put(110, 30));  // collision
    assert(map.size() == 2);
    assert(map.get(10) == 20);  // gives 20
    assert(map.get(110) == 30); // gives 30
    assert(map.get(11) == -1); // gives -1, no match
    assert(map.remove(110));  // found and succeed
    assert(map.size() == 1);
    assert(!map.remove(1));  // not found and fail
    assert(map.get(110) == -1); // gives -1, no match after removal
    cout << "All tests passed!\n";
}