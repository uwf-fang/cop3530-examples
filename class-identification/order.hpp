#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>
#include "item.hpp"

using std::vector;
using std::string;

class Order {
  int id;
  vector<Item> items;
  bool ready;
  bool delivered;
  bool paid;

public:
  Order();
  void add(string name, int quantity);
  bool remove(string name, int quantity);
  void ready();
  void deliver();
  void pay();
  string show();
};
#endif