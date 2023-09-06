#include "store-item.hpp"
#include <iostream>
using namespace std;

StoreItem::StoreItem(): name("") {}

StoreItem::StoreItem(const string & name) {
  this->name = name;
  // this->print();    // access member functions (methods)
}

string StoreItem::getName() const {
  return this->name;
}

void StoreItem::setName(string name) {
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