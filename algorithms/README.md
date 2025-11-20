# Algorithms

This folder contains implementations of various algorithms including sorting, searching, dynamic programming, and string algorithms.

## Files Overview

### Sorting Algorithms
- **insertionSort.cpp** - Insertion sort implementation
- **selectionSort.cpp** - Selection sort implementation
- **mergeSort.cpp** - Merge sort implementation
- **MergeSort2.cpp** - Alternative merge sort implementation
- **quickSort.cpp** - Quick sort implementation

### Dynamic Programming
- **dynamic_programming.cpp** - Classic DP problems (Fibonacci, LCS, Knapsack, etc.)
- **editDistance.cpp** - Edit distance calculation
- **longestCommonSubsequence.cpp** - LCS implementation
- **longestPalindromicSubsequence.cpp** - LPS implementation
- **knapsack.cpp** - 0/1 Knapsack problem

### String Algorithms
- **string_algorithms.cpp** - KMP, Rabin-Karp, Z-algorithm, Trie
- **generatePermutation.cpp** - String permutation generation

### Graph Algorithms
- **pathInGraph.cpp** - Path finding in graphs
- **reconstructItinerary.cpp** - Eulerian path reconstruction

### Array Algorithms
- **arrayRotation.cpp** - Array rotation techniques
- **arrayRotation2.cpp** - Alternative rotation methods
- **greaterElementLeft.cpp** - Next greater element to the left
- **greaterElementRight.cpp** - Next greater element to the right
- **smallerElementLeft.cpp** - Next smaller element to the left
- **smallerElementRight.cpp** - Next smaller element to the right

### Mathematical Algorithms
- **powerOfTwo.cpp** - Power of two calculations
- **uniqueElement.cpp** - Finding unique elements
- **kthAndKSmallest.cpp** - Kth largest/smallest element

### Backtracking
- **nQueens.cpp** - N-Queens problem solution
- **sudokuSolver.cpp** - Sudoku solver using backtracking
- **knightsTour.cpp** - Knight's tour problem

## Algorithm Complexities

### Sorting Algorithms
- **Insertion Sort**: O(n²) time, O(1) space
- **Selection Sort**: O(n²) time, O(1) space
- **Merge Sort**: O(n log n) time, O(n) space
- **Quick Sort**: O(n log n) average, O(n²) worst case

### Dynamic Programming
- **Fibonacci**: O(n) time, O(n) space with memoization
- **LCS**: O(mn) time and space
- **Knapsack**: O(nW) time and space

### String Algorithms
- **KMP**: O(n + m) time, O(m) space
- **Rabin-Karp**: O(n + m) average, O(nm) worst case
- **Trie Operations**: O(m) where m is string length

## Compilation

```bash
g++ -std=c++17 filename.cpp -o filename
```

## Learning Path

1. **Sorting**: Start with simple sorts (insertion, selection), then advanced (merge, quick)
2. **Searching**: Binary search and its variants
3. **Dynamic Programming**: Master the concept with classic problems
4. **String Algorithms**: Pattern matching and string processing
5. **Graph Algorithms**: BFS, DFS, shortest path algorithms
6. **Backtracking**: Constraint satisfaction problems