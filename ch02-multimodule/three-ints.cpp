#include "three-ints.hpp"

int threeIntsSum(int num1, int num2, int num3)
{
   return (num1 + num2 + num3);
}

int threeIntsAvg(int num1, int num2, int num3)
{
   int sum;
   sum = num1 + num2 + num3;
   return (sum / 3);
}