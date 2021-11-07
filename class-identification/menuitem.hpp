#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <string>
#include <vector>

using std::vector;
using std::string;

class MenuItem {
private:
  int id;
  string name;
  double price;
public:
  MenuItem();
  MenuItem(string name, double price);
  string show();
};

#endif