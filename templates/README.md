# Template Programming

This folder contains examples of C++ template programming, including function templates, class templates, and advanced template techniques.

## Files Overview

- **function_templates.cpp** - Function template examples and specializations
- **class_templates.cpp** - Class template implementations and specializations

## Template Concepts

### Function Templates
- Generic functions that work with multiple types
- Template parameter deduction
- Explicit template specialization
- SFINAE (Substitution Failure Is Not An Error)
- Variadic templates

### Class Templates
- Generic classes parameterized by types
- Template specialization (full and partial)
- Template template parameters
- Default template arguments

### Advanced Template Features
- **Template Metaprogramming**: Compile-time computations
- **SFINAE**: Enable/disable templates based on conditions
- **Variadic Templates**: Templates with variable number of parameters
- **Perfect Forwarding**: Preserving value categories
- **Template Aliases**: Type aliases using templates

## Template Syntax

### Basic Function Template
```cpp
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
```

### Basic Class Template
```cpp
template<typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& element);
    void pop();
    T top() const;
};
```

### Template Specialization
```cpp
// Full specialization
template<>
class Stack<bool> {
    // Specialized implementation for bool
};

// Partial specialization
template<typename T>
class Stack<T*> {
    // Specialized implementation for pointers
};
```

## Template Best Practices

1. **Use meaningful template parameter names**
2. **Provide clear error messages** with static_assert
3. **Use concepts** (C++20) or SFINAE for constraints
4. **Avoid deep template instantiation** chains
5. **Use template aliases** for complex types
6. **Document template requirements** clearly

## Common Template Patterns

### CRTP (Curiously Recurring Template Pattern)
```cpp
template<typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};

class Derived : public Base<Derived> {
public:
    void implementation() { /* ... */ }
};
```

### Type Traits
```cpp
template<typename T>
void process(T value) {
    if constexpr (std::is_integral_v<T>) {
        // Handle integral types
    } else if constexpr (std::is_floating_point_v<T>) {
        // Handle floating point types
    }
}
```

## Compilation

Templates are compiled when instantiated, so compilation errors may occur at instantiation time:

```bash
g++ -std=c++17 filename.cpp -o filename
```

For better error messages, use:
```bash
g++ -std=c++17 -ftemplate-backtrace-limit=0 filename.cpp -o filename
```

## Template Instantiation

Templates are instantiated when:
1. A function template is called
2. A class template is used to create an object
3. A template member is accessed
4. Explicit instantiation is requested

## Performance Considerations

- Templates generate code at compile time (zero runtime overhead)
- Can increase binary size due to code generation
- Compilation time may increase with complex templates
- Template metaprogramming enables compile-time optimizations