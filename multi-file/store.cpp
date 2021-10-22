#include <iostream>
using namespace std;

#include "store.hpp"

Store::Store(): name("") {}

Store::Store(string name): name(name) {}

void Store::addItem(StoreItem item) {
  items.push_back(item);
}

void Store::print() const {
  cout << "Store: " << name << endl;
  cout << "----------------\n";
  for (StoreItem item : items)
    item.print();
}

