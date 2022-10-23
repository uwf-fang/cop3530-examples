#include "testing-helper.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void quicksort(int *arr, int size);
void quicksortHelper(int *arr, int low, int high);
int quickPartition(int *arr, int low, int high);

int quickPartition(int *arr, int low, int high) {
  int mid = (high + low) / 2;
  int pivot = arr[mid];
  while (true) {
    while (arr[low] < pivot) ++low;
    while (arr[high] > pivot) --high;
    if (low >= high) break;
    swap(arr[low], arr[high]);
    ++low;
    --high;
  }
  return high;
}

void quicksort(int *arr, int size) {
  quicksortHelper(arr, 0, size - 1);
}

void quicksortHelper(int *arr, int low, int high) {
  if (low >= high) return;
  int part = quickPartition(arr, low, high);
  quicksortHelper(arr, low, part);
  quicksortHelper(arr, part + 1, high);
}

int main() {
  int arr[] = {12, 63, 23, 72, 18, 90, 82, 99, 2, 42};
  int size = sizeof(arr) / sizeof(arr[0]);

  printSeq(arr, arr + size);
  quicksort(arr, size);
  printSeq(arr, arr + size);
  assert(isAscending(arr, arr + size));

  return EXIT_SUCCESS;
}