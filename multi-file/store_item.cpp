#include <iostream>
using namespace std;

#include "store_item.hpp"

StoreItem::StoreItem(): name("") {}

StoreItem::StoreItem(const string & name) {
  this->name = name;
  // this->print();    // access member functions (methods)
}

string StoreItem::GetName() const {
  return this->name;
}

void StoreItem::SetName(string name) {
  this->name = name;
}

StoreItem::~StoreItem() {
  // clean up dynamic data
}

bool StoreItem::equals(const StoreItem & other) const {
  return (this->name == other.name);
}

void StoreItem::print() const
{
  cout << "Item name: " << name << endl;
}