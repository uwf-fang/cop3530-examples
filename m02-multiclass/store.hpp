#ifndef STORE_H
#define STORE_H

#include "store-item.hpp"
#include <string>
#include <vector>

class Store
{
public:
  Store();
  explicit Store(std::string name);
  void addItem(StoreItem item);
  void print() const;

private:
  std::string name;
  std::vector<StoreItem> items;
};

#endif