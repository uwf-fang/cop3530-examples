#include <iostream>
#include "set.hpp"

using namespace std;

void testSet();

int main() {
    testSet();
}

void testSet() {
    Set set1;
    set1.add(10);
    set1.add(50);
    set1.add(5);

    Set set2;
    set2.add(1);
    set2.add(20);
    set2.add(5);

    cout << "Testing set class\n";
    cout << set1.intersect(set2).to_str() << endl;  // 5
    cout << set1.setAdd(set2).to_str() << endl;     // 10 50 5 1 20
    cout << set1.difference(set2).to_str() << endl; // 10 50
    set1.remove(50);
    cout << set1.to_str() << endl;                  // 10 5
}