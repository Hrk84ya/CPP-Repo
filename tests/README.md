# Unit Tests

This folder contains unit tests for various C++ implementations using a simple testing framework.

## Files Overview

- **simple_test_framework.h** - Lightweight testing framework
- **test_data_structures.cpp** - Tests for data structure implementations
- **test_algorithms.cpp** - Tests for algorithm implementations

## Testing Framework Features

### Assertion Methods
- `assert_equal(test_name, expected, actual)` - Compare two values
- `assert_true(test_name, condition)` - Verify condition is true
- `assert_false(test_name, condition)` - Verify condition is false
- `run_test(test_name, test_function)` - Execute a test function with exception handling

### Test Results
- Automatic pass/fail tracking
- Detailed failure reporting
- Test summary with success rate
- Exception handling for test functions

## Running Tests

### Compile and Run Individual Tests
```bash
g++ -std=c++17 test_data_structures.cpp -o test_data_structures
./test_data_structures

g++ -std=c++17 test_algorithms.cpp -o test_algorithms
./test_algorithms
```

### Using Makefile
```bash
make tests
```

## Test Coverage

### Data Structures Tests
- Stack operations (push, pop, top, empty)
- Queue operations (enqueue, dequeue, front, empty)
- Vector operations (insert, erase, access)
- STL container functionality

### Algorithm Tests
- Sorting algorithm correctness
- Binary search functionality
- Fibonacci sequence calculation
- Palindrome detection
- STL algorithm usage
- Edge case handling

## Sample Output

```
=== Data Structures Unit Tests ===

--- Running Stack Operations ---
[PASS] Stack initially empty
[PASS] Stack initial size
[PASS] Stack not empty after pushes
[PASS] Stack size after 3 pushes
[PASS] Stack top element
[PASS] Stack top after one pop
[PASS] Stack size after one pop
[PASS] Stack empty after all pops

=== Test Summary ===
Total tests: 24
Passed: 24
Failed: 0
Success rate: 100%
```

## Writing New Tests

1. Include the testing framework header
2. Write test functions that use assertion methods
3. Use `run_test()` to execute test functions
4. Call `print_summary()` to display results

Example:
```cpp
#include "simple_test_framework.h"

void test_my_function() {
    SimpleTest::assert_equal("Test description", expected_value, actual_value);
}

int main() {
    SimpleTest::run_test("My Function Test", test_my_function);
    SimpleTest::print_summary();
    return 0;
}
```