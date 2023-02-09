#include <cassert>
#include <iostream>

using namespace std;

// ============= declarations =======================
int searchFirst(int array[], int size, int toSearch);
int searchFirstHelper(int array[], int size, int toSearch, int start);

bool areEqualArrays(int *arr1, int size1, int * arr2, int size2);
bool areEqualArrays1(int *arr1, int size1, int * arr2, int size2);
bool areEqualArraysHelper1(int *arr1, int *arr2, int left, int right);

bool isPalindrome(int *arr, int size);
bool isPalindromeHelper(int *arr, int left, int right);

// fibonacci(47) will overflow int type
int fibonacci(int n);
int fibonacciMemory(int n);

int binarySearch(int arr[], int size, int value);
int binarySearchHelper(int arr[], int left, int right, int value);

// ==================== definitions =====================
int searchFirst(int array[], int size, int toSearch) {
  return searchFirstHelper(array, size, toSearch, 0);
}

int searchFirstHelper(int array[], int size, int toSearch, int start) {
  if (array[start] == toSearch) return start;
  if (start >= size - 1)  // hit the end
    return -1;
  return searchFirstHelper(array, size, toSearch, start + 1);
}


// compare tail element every round
bool areEqualArrays(int *arr1, int size1, int * arr2, int size2) {
  if (size1 != size2) return false;
  if (size1 == 0) return true;
  if (arr1[size1 - 1] != arr2[size2 - 1]) return false;
  return areEqualArrays(arr1, size1 - 1, arr2, size2 - 1);
}

// compare head element every round
// must use a helper function
bool areEqualArrays1(int *arr1, int size1, int * arr2, int size2) {
  if (size1 != size2) return false;
  return areEqualArraysHelper1(arr1, arr2, 0, size1 - 1);
}

bool areEqualArraysHelper1(int *arr1, int *arr2, int left, int right) {
  if (left >= right) return true;
  if (arr1[left] != arr2[left]) return false;
  return areEqualArraysHelper1(arr1, arr2, left + 1, right);
}


bool isPalindrome(int *arr, int size) {
  return isPalindromeHelper(arr, 0, size - 1);
}

bool isPalindromeHelper(int *arr, int left, int right) {
  if (left >= right) return true;
  if (arr[left] != arr[right]) return false;
  return isPalindromeHelper(arr, left + 1, right - 1);
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


// ========================= tests ========================
void testSearch() {
  cout << "Testing search algorithms\n";
  int arr[] = {1, 9, 4, 6, 3};
  assert(searchFirst(arr, 5, 3) == 4);
  assert(searchFirst(arr, 5, 9) == 1);
  assert(searchFirst(arr, 5, 1) == 0);
  cout << "All tests passed\n";
}


void testArrayEqual() {
  cout << "Testing array comparison algorithms\n";
  int arr1[] = {1, 5, 6, 8, 9};
  int arr2[] = {1, 5, 6, 8, 9};
  int arr3[] = {1, 5, 6};
  int arr4[] = {2, 5, 7, 8, 9};

  // same
  assert(areEqualArrays(arr1, 5, arr2, 5));
  assert(areEqualArrays1(arr1, 5, arr2, 5));
  // different size
  assert(!areEqualArrays(arr1, 5, arr3, 3));
  assert(!areEqualArrays1(arr1, 5, arr3, 3));
  // different values
  assert(!areEqualArrays(arr1, 5, arr4, 5));
  assert(!areEqualArrays1(arr1, 5, arr4, 5));
  cout << "All tests passed\n";
}


void testArrayPalindrome() {
  cout << "Testing array palindrome algorithms\n";
  int arr1[] = {1, 2, 2, 1};
  int arr2[] = {1, 2, 1};
  int arr4[] = {1, 2, 3, 1};

  assert(isPalindrome(arr1, 4));
  assert(isPalindrome(arr2, 3));
  assert(!isPalindrome(arr4, 4));
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
  testArrayEqual();
  testArrayPalindrome();
  testFibonacci();
  testBinarySearch();
}