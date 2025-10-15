# Module 09: Sorting Algorithms

This module contains implementations and examples of various sorting algorithms in C++, focusing on quicksort and linked list sorting techniques.

## Files

- [llist.hpp](llist.hpp) - Linked list implementation header file for sorting demonstrations
- [quicksort.hpp](quicksort.hpp) - Quicksort algorithm header file
- [quicksort.cpp](quicksort.cpp) - Quicksort algorithm implementation with partition logic
- [test-ll-sorting.cpp](test-ll-sorting.cpp) - Test cases for linked list sorting
- [test-quicksort.cpp](test-quicksort.cpp) - Test cases for quicksort algorithm
- [makefile](makefile) - Build configuration file

## Building

To build all test programs, run:

```sh
make test-all
```

To build individual test programs:

```sh
make test-quicksort
make test-ll-sorting
```

## Running Tests

After building, the tests will automatically run. You can also run them manually:

```sh
./test-quicksort
./test-ll-sorting
```

## Cleaning Build Artifacts

To remove compiled binaries and object files:

```sh
make clean
```

## Topics Covered

This module demonstrates:

- **Quicksort Algorithm**: Efficient divide-and-conquer sorting with partitioning
  - Implementation using median-of-three pivot selection
  - Recursive helper functions
  - In-place sorting with partition logic
- **Linked List Sorting**: Sorting techniques for linked data structures
- **Algorithm Analysis**: Performance comparison of different sorting approaches
- **Template Usage**: Generic sorting implementations

## Algorithm Overview

### Quicksort

The [`quicksort`](quicksort.cpp) implementation uses:
- Partition-based approach with pivot selection
- Recursive divide-and-conquer strategy
- Helper function [`quicksortHelper`](quicksort.cpp) for recursive calls
- [`quickPartition`](quicksort.cpp) function for element partitioning

## Related Modules

- See [m07-linked-list](../m07-linked-list) for linked list basics
- See [m04-algorithm-analysis](../m04-algorithm-analysis) for complexity analysis
- See the parent [README.md](../README.md) for more COP3530 course materials

## Course Context

This is part of the COP3530 (Data Structures and Algorithms I) course examples at UWF.