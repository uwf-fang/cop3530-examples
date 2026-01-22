#include "grid.hpp"
#include <iostream>

using namespace std;

// Node class
Node::Node() : value(0) {}

Node::Node(int value) : value(value) {}

void Node::setVal(int value) { this->value = value; }
int Node::getVal() { return value; }

// Grid class
Grid::Grid() : matrix(nullptr), rows(0), cols(0) {}

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
  // allocate memory for 2d array
  matrix = new Node*[rows];
  for (int i = 0; i < rows; ++i)
    matrix[i] = new Node[cols];

  // initialize values
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      matrix[i][j].setVal(cols * i + j);
}

Grid::~Grid() {
  if (matrix != nullptr) {
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;
  }
}

Grid::Grid(const Grid& other) {
  rows = other.rows;
  cols = other.cols;
  matrix = new Node*[rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Node[cols];
    for (int j = 0; j < cols; ++j)
      matrix[i][j].setVal(other.matrix[i][j].getVal());
  }
}

Grid& Grid::operator=(const Grid& other) {
  if (this == &other) return *this;  // self-assignment check
  // delete old data if old data exists
  if (matrix != nullptr) {
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;
  }

  // copy new data
  rows = other.rows;
  cols = other.cols;
  matrix = new Node*[rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Node[cols];
    for (int j = 0; j < cols; ++j)
      matrix[i][j].setVal(other.matrix[i][j].getVal());
  }

  return *this;
}

int Grid::getRows() { return rows; }

int Grid::getCols() { return cols; }

void Grid::print() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) cout << matrix[i][j].getVal() << " ";
    cout << endl;
  }
}
