# Exception Handling

This folder demonstrates C++ exception handling mechanisms, best practices, and RAII (Resource Acquisition Is Initialization) principles.

## Files Overview

- **basic_exceptions.cpp** - Exception handling fundamentals, custom exceptions, and RAII

## Exception Handling Concepts

### Basic Exception Handling
- **try-catch blocks**: Handling exceptions
- **throw statements**: Throwing exceptions
- **Exception propagation**: How exceptions travel up the call stack
- **Multiple catch blocks**: Handling different exception types

### Standard Exception Hierarchy
```
std::exception
├── std::logic_error
│   ├── std::invalid_argument
│   ├── std::domain_error
│   ├── std::length_error
│   └── std::out_of_range
├── std::runtime_error
│   ├── std::range_error
│   ├── std::overflow_error
│   └── std::underflow_error
├── std::bad_alloc
├── std::bad_cast
└── std::bad_typeid
```

### Custom Exceptions
```cpp
class CustomException : public std::exception {
private:
    std::string message;
public:
    CustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
```

## RAII (Resource Acquisition Is Initialization)

RAII is a programming idiom where resource management is tied to object lifetime:

### Principles
1. **Acquire resources in constructors**
2. **Release resources in destructors**
3. **Use automatic storage duration** when possible
4. **Leverage smart pointers** for dynamic memory

### Benefits
- **Automatic cleanup**: Resources are automatically released
- **Exception safety**: Resources are cleaned up even when exceptions occur
- **Deterministic destruction**: Predictable resource management

### Example
```cpp
class FileHandler {
private:
    std::FILE* file;
public:
    FileHandler(const std::string& filename) {
        file = std::fopen(filename.c_str(), "r");
        if (!file) {
            throw std::runtime_error("Cannot open file");
        }
    }
    
    ~FileHandler() {
        if (file) {
            std::fclose(file);
        }
    }
    
    // Disable copy to prevent double-close
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
};
```

## Exception Safety Guarantees

### 1. No-throw Guarantee
- Function never throws exceptions
- Marked with `noexcept`

### 2. Strong Exception Safety
- If exception occurs, program state is unchanged
- "Commit or rollback" semantics

### 3. Basic Exception Safety
- If exception occurs, program is in valid state
- No resource leaks, but state may be changed

### 4. No Exception Safety
- No guarantees about program state after exception

## Best Practices

### Do's
1. **Use RAII** for resource management
2. **Catch exceptions by const reference**
3. **Throw exceptions by value**
4. **Use standard exception types** when appropriate
5. **Provide strong exception safety** when possible
6. **Use smart pointers** for automatic memory management

### Don'ts
1. **Don't throw exceptions from destructors**
2. **Don't catch exceptions you can't handle**
3. **Don't use exceptions for control flow**
4. **Don't throw exceptions across C library boundaries**
5. **Don't ignore exceptions** (empty catch blocks)

## Exception Specifications

### noexcept (C++11)
```cpp
void safe_function() noexcept {
    // Guaranteed not to throw
}

void conditional_noexcept() noexcept(some_condition) {
    // noexcept depends on condition
}
```

### Benefits of noexcept
- **Compiler optimizations**: Better code generation
- **Move semantics**: Enables move operations in containers
- **Documentation**: Clear intent about exception behavior

## Error Handling Strategies

### 1. Exception Handling
- Use for exceptional circumstances
- Automatic stack unwinding
- RAII ensures cleanup

### 2. Error Codes
- Use for expected error conditions
- Explicit error checking required
- No automatic cleanup

### 3. Optional/Expected (C++17/C++23)
- Represents values that may or may not exist
- Type-safe error handling
- Functional programming style

## Compilation

```bash
g++ -std=c++17 filename.cpp -o filename
```

## Performance Considerations

- **Zero-cost when no exceptions**: No runtime overhead in normal execution
- **Stack unwinding cost**: Overhead when exceptions are thrown
- **Code size**: Exception handling can increase binary size
- **Optimization**: Compilers can optimize exception-free paths