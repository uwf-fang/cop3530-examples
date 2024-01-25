#include "grid.hpp"
#include <iostream>
using namespace std;


int main()
{
  Grid grid(5, 5);

  cout << "Rows: " << grid.getRows() << " Cols: " << grid.getCols() << endl;
  grid.print();

  Grid grid2(grid);
  cout << "Printing grid2 from copy constructor" << endl;
  grid2.print();

  Grid grid3;
  grid3 = grid;
  cout << "Printing grid from copy assignment" << endl;
  grid3.print();

  return 0;
}