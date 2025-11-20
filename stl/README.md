# Standard Template Library (STL)

This folder demonstrates the usage of C++ Standard Template Library components including containers, algorithms, and iterators.

## Files Overview

- **containers.cpp** - STL containers (map, set, queue, deque, etc.)
- **algorithms.cpp** - STL algorithms (sort, find, transform, etc.)

## STL Components

### Containers

#### Sequence Containers
- **vector**: Dynamic array with random access
- **deque**: Double-ended queue
- **list**: Doubly-linked list
- **array**: Fixed-size array (C++11)

#### Associative Containers
- **set**: Ordered unique elements
- **multiset**: Ordered elements (duplicates allowed)
- **map**: Key-value pairs (ordered by key)
- **multimap**: Key-value pairs with duplicate keys

#### Unordered Containers (C++11)
- **unordered_set**: Hash set
- **unordered_multiset**: Hash multiset
- **unordered_map**: Hash map
- **unordered_multimap**: Hash multimap

#### Container Adapters
- **stack**: LIFO container adapter
- **queue**: FIFO container adapter
- **priority_queue**: Priority queue (heap)

### Algorithms

#### Non-modifying Sequence Operations
- `find`, `find_if`, `count`, `count_if`
- `search`, `equal`, `mismatch`

#### Modifying Sequence Operations
- `copy`, `move`, `transform`, `replace`
- `fill`, `generate`, `remove`, `unique`

#### Sorting and Related Operations
- `sort`, `stable_sort`, `partial_sort`
- `binary_search`, `lower_bound`, `upper_bound`
- `merge`, `partition`

#### Numeric Operations
- `accumulate`, `inner_product`
- `partial_sum`, `adjacent_difference`

## Performance Characteristics

### Container Access Times
| Container | Access | Insert | Delete | Search |
|-----------|--------|--------|--------|--------|
| vector | O(1) | O(n) | O(n) | O(n) |
| deque | O(1) | O(1) ends, O(n) middle | O(1) ends, O(n) middle | O(n) |
| list | O(n) | O(1) | O(1) | O(n) |
| set/map | O(log n) | O(log n) | O(log n) | O(log n) |
| unordered_set/map | O(1) avg | O(1) avg | O(1) avg | O(1) avg |

## Best Practices

1. **Choose the right container** for your use case
2. **Use algorithms** instead of hand-written loops when possible
3. **Prefer const iterators** when not modifying elements
4. **Use range-based for loops** for simple iterations
5. **Reserve capacity** for vectors when size is known
6. **Use emplace** instead of insert for better performance

## Compilation

```bash
g++ -std=c++17 filename.cpp -o filename
```