#include <iostream>

using namespace std;

int searchFirst(int nums[], int size, int toSearch);
int searchFirstHelper(int nums[], int size, int toSearch, int start);
int fibonacci(int n);
int fibonacciMemory(int n);
int binarySearch(int arr[], int size);
int binarySearchHelper(int arr[], int left, int right);

int searchFirst(int nums[], int size, int toSearch) {
  return searchFirstHelper(nums, size, toSearch, 0);
}

int searchFirstHelper(int nums[], int size, int toSearch, int start) {
  if (nums[0] == toSearch)
    return start;
  else if (size == 1)
    return -1;
  else
    return searchFirstHelper(nums + 1, size - 1, toSearch, start + 1);
}

// inefficient because of redundant calculation
int fibonacci(int n) {
  cout << "fibonacci(" << n << ") is called.\n";
  if (n <= 2)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// global variable as memory
int memory[100] = {};

int fibonacciMemory(int n) {
  cout << "fibonacci(" << n <<") with memory is called\n";
  if (n <= 2)
    return 1;
  else {
    if (memory[n] != 0)
      return memory[n];
    if (memory[n - 2] == 0)
      memory[n - 2] = fibonacciMemory(n - 2);
    if (memory[n - 1] == 0)
      memory[n - 1] = fibonacciMemory(n - 1);
    memory[n] = memory[n - 1] + memory[n - 2];
    return memory[n];
  }
}

int main() {
  cout << fibonacci(6) << endl;
  cout << fibonacciMemory(6) << endl;
}