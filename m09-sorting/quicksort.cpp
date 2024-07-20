/**
 * @file quicksort.cpp
 * @author Ian Fang
 * @brief Quick sort implementation adopted from zyBooks.com
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "quicksort.hpp"
#include <algorithm>
#include <cassert>

using namespace std;

void quicksort(int *arr, int size);
void quicksortHelper(int *arr, int low, int high);
int quickPartition(int *arr, int low, int high);

int quickPartition(int *arr, int low, int high) {
  int mid = (high + low) / 2;
  // int mid = low + (high - low) / 2;
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
