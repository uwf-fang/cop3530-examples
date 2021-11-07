#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include "menuitem.cpp"

using std::vector;
using std::string;

class Menu {
private:
  vector<MenuItem> items;
public:
  void add(string name, double price);
  void remove(string name);
  string show();
};

#endif