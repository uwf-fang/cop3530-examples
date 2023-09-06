#include "three-ints.hpp"
#include <iostream>

using namespace std;

int main() {

  cout << "Testing three int sum and three int avg function " <<
      "on 5, 10, 20" << endl;
  cout << threeIntsSum(5, 10, 20) << endl;
  cout << threeIntsAvg(5, 10, 20) << endl;

  return EXIT_SUCCESS;
}