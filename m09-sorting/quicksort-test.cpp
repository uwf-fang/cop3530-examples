#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>

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
  int size = 10;
  int *arr = new int[size];

  for (int run = 0; run < 3; ++ run) {
    for (int i = 0; i < size; ++i) arr[i] = i + 1;
    shuffle(arr, arr + size, default_random_engine(0));
    assert(!is_sorted(arr, arr + size));
    quicksort(arr, size);
    assert(is_sorted(arr, arr + size));
    cout << "Run " << run << " passed!" << endl;
  }

  return EXIT_SUCCESS;
}