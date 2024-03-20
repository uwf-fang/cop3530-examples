#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

template <typename T>
void percolateDown(T arr[], int size, int root) {
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && arr[left] > arr[largest])
    largest = left;

  if (right < size && arr[right] > arr[largest])
    largest = right;

  if (largest != root) {
    std::swap(arr[root], arr[largest]);
    percolateDown(arr, size, largest);
  }
}

template <typename T>
void heapsort(T arr[], int size) {
  // Build the heap
  for (int i = size / 2 - 1; i >= 0; i--)
    percolateDown(arr, size, i);

  // Extract elements from the heap and place them in the array at the end
  for (int i = size - 1; i > 0; i--) {
    std::swap(arr[0], arr[i]);
    percolateDown(arr, i, 0);
  }
}

#endif // HEAP_SORT_HPP
