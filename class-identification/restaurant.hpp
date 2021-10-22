#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
#include "order.hpp"
#include "menu.hpp"

class Restaurant
{
private:
  Menu menu;
  std::vector<Order> orders;

public:
  Restaurant(std::string name);
  void showMenu();
  void placeOrder(Order order);
};

#endif
