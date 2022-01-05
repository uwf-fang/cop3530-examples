#include <iostream>
#include "set.hpp"
#include "hashtable.hpp"

using namespace std;

void testHashTable();

int main() {
    testHashTable();
}

void testHashTable() {
    HashTable hash;
    hash.set(10, 20);
    hash.set(110, 30);  // collision
    cout << "Testing hash table class\n";
    cout << hash.lookUp(10) << endl;  // gives 20
    cout << hash.lookUp(110) << endl; // gives 30
    cout << hash.lookUp(11) << endl; // gives -1, no match
    hash.remove(110);
    cout << hash.lookUp(110) << endl; // gives -1, no match after removal

}
