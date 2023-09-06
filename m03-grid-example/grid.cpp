#include "grid.hpp"

Node::Node() : value(0) {}
Node::Node(int value) : value(value) {}
void Node::setVal(int value) {
  this->value = value;
  // (*this).value = value;
}

Grid::Grid() : matrix(nullptr) {}

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
  matrix = new Node *[rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Node[cols];
    for (int j = 0; j < cols; ++j) {
      matrix[i][j].setVal(cols * i + j);
    }
  }
}

Grid::~Grid() {
  for (int i = 0; i < rows; ++i)
    delete [] matrix[i];
  delete [] matrix;
}

int Grid::getRows() {
  return rows;
}

int Grid::getCols() {
  return cols;
}