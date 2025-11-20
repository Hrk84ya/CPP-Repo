# Modern C++ Features

This folder demonstrates modern C++ features introduced in C++11, C++14, C++17, and later standards.

## Files Overview

- **smart_pointers.cpp** - Smart pointers (unique_ptr, shared_ptr, weak_ptr)
- **lambdas.cpp** - Lambda expressions and closures
- **auto_and_range_loops.cpp** - Auto keyword and range-based for loops
- **move_semantics.cpp** - Move constructors, move assignment, and perfect forwarding

## Key Concepts

### Smart Pointers
- **unique_ptr**: Exclusive ownership, automatic memory management
- **shared_ptr**: Shared ownership with reference counting
- **weak_ptr**: Non-owning observer to break circular references

### Lambda Expressions
- Capture lists: `[=]`, `[&]`, `[var]`, `[&var]`
- Mutable lambdas for modifying captured variables
- Generic lambdas (C++14)

### Auto Keyword
- Automatic type deduction
- Reduces verbosity and improves maintainability
- Works with complex template types

### Range-Based For Loops
- Simplified iteration over containers
- Structured bindings (C++17)

### Move Semantics
- Eliminates unnecessary copying
- Perfect forwarding with `std::forward`
- RAII and exception safety

## Compilation Requirements

These examples require C++17 or later:
```bash
g++ -std=c++17 filename.cpp -o filename
```

## Benefits of Modern C++

1. **Memory Safety**: Smart pointers prevent memory leaks
2. **Performance**: Move semantics reduce copying overhead
3. **Readability**: Auto and range-based loops improve code clarity
4. **Expressiveness**: Lambdas enable functional programming patterns