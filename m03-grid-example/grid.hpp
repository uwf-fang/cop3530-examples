#ifndef GRID_HPP
#define GRID_HPP
/**
 * Grid class to demonstrate 2d dynamic array
 *   rule of three methods are implemented
 */
#include <cmath>

class Node {
private:
  int value;
public:
  Node();
  explicit Node(int value);
  void setVal(int value);
  int getVal();
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
  Grid(const Grid & other);
  Grid& operator=(const Grid & other);
  int getRows();
  int getCols();
  void print();
};

#endif
