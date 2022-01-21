#include "store.hpp"
#include "store-item.hpp"
#include <iostream>
using namespace std;

void testStoreItem() {
  StoreItem item1("Apple");
  item1.print();
  StoreItem item2("apple");
  item2.print();
  if (item1.equals(item2))
    cout << "They are equal!\n";
  else
    cout << "They are not equal!\n";
}

void testStore() {
  Store myStore("Test Store");
  myStore.addItem(StoreItem("Apple"));
  myStore.addItem(StoreItem("Banana"));
  myStore.print();
}

int main() {
  // testStoreItem();
  testStore();
  return 0;
}