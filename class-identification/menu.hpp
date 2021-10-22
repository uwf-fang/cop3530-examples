#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

class Menu
{
  // items on menu
  // list of name and price pairs
  std::vector<std::pair<std::string, double> > items;

public:
  Menu(std::vector<std::pair<std::string, double> > items);
  bool deliver();
  void print();
};

#endif