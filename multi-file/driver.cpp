#include <iostream>
using namespace std;

#include "store.hpp"
#include "store_item.hpp"

void test_store_item() {
  StoreItem item1("Apple");
  item1.print();
  StoreItem item2("apple");
  item2.print();
  if (item1.equals(item2))
    cout << "They are equal!\n";
  else
    cout << "They are not equal!\n";
}

void test_store() {
  Store myStore("Test Store");
  myStore.addItem(StoreItem("Apple"));
  myStore.addItem(StoreItem("Banana"));

  myStore.print();
}

int main()
{
  test_store_item();
  // test_store();
  return 0;
}