#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>

class Order
{
  // items on menu
  // list of name and quantity pairs
  std::vector<std::pair<std::string, int> > items;
  // order ready flag
  bool ready;
  // order delivered flag
  bool delivered;

public:
  Order();
  Order(std::vector<std::pair<std::string, int> > items);
  void deliver();
  void print();
};
#endif