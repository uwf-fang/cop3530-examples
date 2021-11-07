#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <vector>
#include "menu.hpp"

using std::vector;
using std::string;

class Item {
private:
  int menuItemId;
  int quantity;
public:
  Item();
  Item(string name, int quantity);
  string show();
};

#endif