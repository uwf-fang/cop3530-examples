#include "quicksort.hpp"
#include <algorithm>

using namespace std;

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
  }
  return high;
}

void quicksort(int *arr, int size) {
  quicksortHelper(arr, 0, size - 1);
}

void quicksortHelper(int *arr, int low, int high) {
  if (low >= high) return;
  int part = quickPartition(arr, low, high);
  quicksortHelper(arr, low, part - 1);
  quicksortHelper(arr, part + 1, high);
}
