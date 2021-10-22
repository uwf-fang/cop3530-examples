#include <iostream>
#include "grid.hpp"
using namespace std;


int main()
{
  Grid grid(5, 5);

  cout << "Rows: " << grid.getRows() << " Cols: " << grid.getCols() << endl;

  return 0;
}