#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
#include "order.hpp"
#include "menu.hpp"

using std::string;
using std::vector;


class Restaurant
{
private:
  string name;
  Menu menu;
  vector<Order> pendingOrders;
  vector<Order> finishedOrders;

public:
  Restaurant();
  Restaurant(string name);
  void setName(sting name);
  string getName();
  void setMenu(Menu menu);
  string showMenu();
  void place(Order order);
  void deliver(Order order);
  void pay(Order order);
};

#endif
