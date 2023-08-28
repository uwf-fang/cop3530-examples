// search linearly, return on match
int search(int * arr, int size, int val) {
  for (int i = 0; i < size; ++i)
    if (arr[i] == val)
      return i;
  return -1;
}
// worst case: T(n) = 1 + n + 1 + n + n + 1 = 3n + 3 = O(n)
// Best case: T(n) 1 + 1 + 1 + 1 = 4 = O(1)


// search linearly, continue on match
int search1(int * arr, int size, int val) {
  int idx = -1;

  int i = 0;
  while (i < size) {
    if (arr[i] == val) // always match in the worst case
      idx = i;
    ++i;
  }
  return idx;
}
// worst case: T(n) = 1 + 1 + 1 + 4 * n + 1 = 4n + 4 = O(n)
// best case: T(n) = 1 + 1 + 1 + 3 * n + 1 = 3n + 4 = O(n)

// selection sort
void sort(int * arr, int size) {
  for (int i = 0; i < size - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < size; ++j)
      if (arr[j] < arr[min])
        min = j;
    if (min != i) {
      int tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
    }
  }
}
// T(n) = number of comparisons + number of swaps
// number of comparisons = 1 + 2 + 3 + ... + n - 1 = n(n - 1) / 2
// number of swaps = n - 1

// worst case: no swap needed, sorting a sorted array
// T(n) = 1 + 2 + 3 + ... + n - 1 = n(n - 1) / 2 = O(n^2)

// best case: swap needed every time, sorting a reverse sorted array
// T(n) = n(n - 1) / 2 + n - 1 = O(n^2)