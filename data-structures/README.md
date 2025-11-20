# Data Structures

This folder contains implementations of fundamental data structures in C++.

## Files Overview

### Basic Data Structures
- **Arrays.cpp** - Array operations and manipulations
- **vector.cpp** - Dynamic arrays using std::vector
- **Structures.cpp** - User-defined structures
- **Structures2.cpp** - Advanced structure operations
- **Pointer.cpp** - Pointer basics and operations
- **DoublePointer.cpp** - Double pointers and pointer to pointers

### Advanced Data Structures
- **binary_search_tree.cpp** - BST implementation with insertion, deletion, traversals
- **graph.cpp** - Graph representation and algorithms (BFS, DFS, Dijkstra)
- **hash_table.cpp** - Hash table with collision handling
- **heap.cpp** - Min/Max heap implementation and heap sort

## Data Structure Complexities

### Binary Search Tree
- **Search**: O(log n) average, O(n) worst case
- **Insert**: O(log n) average, O(n) worst case
- **Delete**: O(log n) average, O(n) worst case

### Hash Table
- **Search**: O(1) average, O(n) worst case
- **Insert**: O(1) average, O(n) worst case
- **Delete**: O(1) average, O(n) worst case

### Heap
- **Insert**: O(log n)
- **Extract Min/Max**: O(log n)
- **Build Heap**: O(n)

### Graph Operations
- **BFS/DFS**: O(V + E) where V = vertices, E = edges
- **Dijkstra**: O((V + E) log V) with priority queue

## Compilation

```bash
g++ -std=c++17 filename.cpp -o filename
```

## Usage Examples

Each file contains a main function demonstrating the data structure operations with sample input and expected output.