#ifndef GRID_HPP
#define GRID_HPP
/**
 * Grid class to demonstrate 2d dynamic array
 *   rule of three methods are not all implemented
 */
#include <cmath>

class Node {
private:
  int value;
public:
  Node();
  explicit Node(int value);
  void setVal(int value);
};

class Grid {
private:
  Node ** matrix;
  int rows;
  int cols;
public:
  Grid();
  Grid(int rows, int cols);
  ~Grid();
  int getRows();
  int getCols();
};

#endif
