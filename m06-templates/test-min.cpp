#include "min.hpp"
#include <iostream>
using namespace std;

int main() {
  // test myMin function, the function template
  cout << "min(2, 3) = " << myMin(2, 3) << endl;  // myMin(int, int)
  cout << "min(2.0, 3.0) = " << myMin(2.0, 3.0) << endl;  // myMin(double, double)
  // myMin(2, 3.0) cannot compile because types much match
  // Self-test: now to delare the function to make myMin(2, 3.0) work?

  // test Min class, the class template
  Min<int> myMin1(2, 3);
  Min<double> myMin2(2.0, 3.0);

  cout << "The min from the class Min<int>(2, 3) " << myMin1.getMin() << endl;
  cout << "The min from the class Min<double>(2.0, 3.0) " << fixed
    << myMin2.getMin() << endl;

}