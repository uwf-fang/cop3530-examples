#include <cassert>
#include <iostream>

using namespace std;

// declarations
int searchFirst(int array[], int size, int toSearch);
int searchFirstHelper(int array[], int size, int toSearch, int start);
// fibonacci(47) will overflow int type
int fibonacci(int n);
int fibonacciMemory(int n);
int binarySearch(int arr[], int size, int value);
int binarySearchHelper(int arr[], int left, int right, int value);

// definitions
int searchFirst(int array[], int size, int toSearch) {
  return searchFirstHelper(array, size, toSearch, 0);
}

int searchFirstHelper(int array[], int size, int toSearch, int start) {
  if (array[start] == toSearch) return start;
  if (start >= size - 1)  // hit the end
    return -1;
  return searchFirstHelper(array, size, toSearch, start + 1);
}

// inefficient because of redundant calculation
int fibonacci(int n) {
  // cout << "fibonacci(" << n << ") is called.\n";
  if (n <= 2)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// global variable as memory
// fibonacci(47) will overflow int type
int memory[46] = {};

int fibonacciMemory(int n) {
  // cout << "fibonacci(" << n << ") with memory is called\n";
  if (n <= 2)
    return 1;
  else {
    if (memory[n] != 0) return memory[n];
    if (memory[n - 2] == 0) memory[n - 2] = fibonacciMemory(n - 2);
    if (memory[n - 1] == 0) memory[n - 1] = fibonacciMemory(n - 1);
    memory[n] = memory[n - 1] + memory[n - 2];
    return memory[n];
  }
}

int binarySearch(int arr[], int size, int value) {
  return binarySearchHelper(arr, 0, size - 1, value);
}

int binarySearchHelper(int arr[], int left, int right, int value) {
  if (left >= right) return -1;
  int mid = (left + right) / 2;
  if (arr[mid] == value) return mid;
  if (arr[mid] > value)
    right = mid - 1;
  else if (arr[mid] < value)
    left = mid + 1;
  return binarySearchHelper(arr, left, right, value);
}

void testSearch() {
  cout << "Testing search algorithms\n";
  int arr[] = {1, 9, 4, 6, 3};
  assert(searchFirst(arr, 5, 3) == 4);
  assert(searchFirst(arr, 5, 9) == 1);
  assert(searchFirst(arr, 5, 1) == 0);
  cout << "All tests passed\n";
}

void testFibonacci() {
  cout << "Testing Fibonacci algorithms\n";
  assert(fibonacci(10) == 55);
  assert(fibonacci(0) == 1);
  assert(fibonacci(2) == 1);
  assert(fibonacciMemory(10) == 55);
  assert(fibonacciMemory(0) == 1);
  assert(fibonacciMemory(2) == 1);
  cout << "All tests passed\n";
}

void testBinarySearch() {
  cout << "Testing binary search algorithms\n";
  int arr[] = {1, 2, 5, 6, 8};
  assert(searchFirst(arr, 5, 5) == 2);
  assert(searchFirst(arr, 5, 8) == 4);
  assert(searchFirst(arr, 5, 1) == 0);
  cout << "All tests passed\n";
}

int main() {
  testSearch();
  testFibonacci();
  testBinarySearch();
}