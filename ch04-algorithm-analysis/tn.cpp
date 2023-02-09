// search linearly, return on match
int search(int * arr, int size, int val) {
  for (int i = 0; i < size; ++i)
    if (arr[i] == val)
      return i;
  return -1;
}
// 1 + n + 1 + n + n + 1 = 3n + 3, worst O(n)
// 1 + 1 + 1 + 1 = 4, best


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
// Analysis
// 1 + 1 + 1 + 4 * n + 1 = 4n + 4, worst case
// 1 + 1 + 1 + 3 * n + 1 = 3n + 4, best case
//O(4n + 4) = O(n)
