#include "order.hpp"

using namespace std;

Order::Order() {
}
Order::Order(std::vector<std::pair<std::string, int>> items) {
    // do work
}

void Order::deliver() {
  delivered = true;
}

void Order::print() {
    // print item list
}
