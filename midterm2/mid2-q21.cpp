#include <iostream>
using namespace std;

// solution
template <class T>
bool compare(T *arr1, int size1, T *arr2, int size2) {
  if (size1 != size2)
    return false;
  for (int i = 0; i < size1; i++)
    if (arr1[i] != arr2[i])
      return false;
  return true;
}

// for testing
int main() {
  int a1[] = {1,2,3,4};
  int a2[] = {1,2,3,4};
  int a3[] = {1,2,3,3};

  if (compare(a1, 4, a2, 4))
    cout << "Identical\n";
  else
    cout << "Different\n";
  if (compare(a1, 4, a3, 4))
    cout << "Identical\n";
  else
    cout << "Different\n";

  return 0;
}