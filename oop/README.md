# Object-Oriented Programming (OOP)

This folder contains examples of object-oriented programming concepts in C++, including classes, inheritance, polymorphism, and encapsulation.

## Files Overview

- **Class.cpp** - Basic class definition and usage
- **Encapsulation.cpp** - Data hiding and access control
- **Inheritance.cpp** - Class inheritance and derived classes
- **Polymorphism.cpp** - Virtual functions and runtime polymorphism
- **Enums.cpp** - Enumeration types and scoped enums

## Core OOP Concepts

### 1. Classes and Objects

#### Class Definition
```cpp
class Rectangle {
private:
    double width, height;
    
public:
    Rectangle(double w, double h);  // Constructor
    ~Rectangle();                   // Destructor
    
    double area() const;            // Member function
    void setDimensions(double w, double h);
    
    // Getters
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};
```

#### Key Components
- **Data members**: Store object state
- **Member functions**: Define object behavior
- **Constructors**: Initialize objects
- **Destructors**: Clean up resources
- **Access specifiers**: Control visibility

### 2. Encapsulation

#### Access Control
- **private**: Accessible only within the class
- **protected**: Accessible within class and derived classes
- **public**: Accessible from anywhere

#### Benefits
- **Data hiding**: Internal implementation is hidden
- **Interface control**: Only necessary functions are exposed
- **Maintainability**: Changes to implementation don't affect users
- **Data integrity**: Controlled access prevents invalid states

### 3. Inheritance

#### Types of Inheritance
```cpp
// Public inheritance (is-a relationship)
class Dog : public Animal {
    // Dog is an Animal
};

// Protected inheritance
class ProtectedDerived : protected Base {
    // Protected members of Base become protected in derived
};

// Private inheritance (implemented-in-terms-of)
class PrivateDerived : private Base {
    // All Base members become private in derived
};
```

#### Inheritance Benefits
- **Code reuse**: Inherit functionality from base classes
- **Extensibility**: Add new features to existing classes
- **Polymorphism**: Treat derived objects as base objects
- **Hierarchical organization**: Model real-world relationships

### 4. Polymorphism

#### Runtime Polymorphism (Virtual Functions)
```cpp
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual ~Shape() = default;       // Virtual destructor
};

class Circle : public Shape {
public:
    double area() const override {    // Override keyword (C++11)
        return M_PI * radius * radius;
    }
};
```

#### Compile-time Polymorphism
- **Function overloading**: Multiple functions with same name
- **Operator overloading**: Custom behavior for operators
- **Template specialization**: Different implementations for types

### 5. Advanced OOP Features

#### Abstract Classes
- Classes with at least one pure virtual function
- Cannot be instantiated directly
- Define interfaces for derived classes

#### Virtual Destructors
- Ensure proper cleanup in inheritance hierarchies
- Required when deleting through base class pointers

#### Multiple Inheritance
```cpp
class FlyingCar : public Car, public Aircraft {
    // Inherits from both Car and Aircraft
    // Beware of diamond problem
};
```

## Design Principles

### SOLID Principles

#### Single Responsibility Principle (SRP)
- Each class should have only one reason to change
- High cohesion within classes

#### Open/Closed Principle (OCP)
- Open for extension, closed for modification
- Use inheritance and polymorphism

#### Liskov Substitution Principle (LSP)
- Derived classes must be substitutable for base classes
- Maintain behavioral contracts

#### Interface Segregation Principle (ISP)
- Clients shouldn't depend on interfaces they don't use
- Prefer small, focused interfaces

#### Dependency Inversion Principle (DIP)
- Depend on abstractions, not concretions
- Use interfaces and abstract classes

### Composition vs Inheritance

#### Composition (Has-a)
```cpp
class Car {
private:
    Engine engine;    // Car has an Engine
    Wheel wheels[4];  // Car has Wheels
};
```

#### When to Use Each
- **Inheritance**: "is-a" relationships, shared interface
- **Composition**: "has-a" relationships, code reuse without inheritance

## Best Practices

### Class Design
1. **Make data members private**: Use getters/setters for access
2. **Use const correctness**: Mark read-only functions as const
3. **Provide virtual destructors**: For base classes
4. **Follow Rule of Three/Five**: Constructor, destructor, copy operations
5. **Use initialization lists**: For constructor efficiency

### Inheritance Guidelines
1. **Prefer composition over inheritance**: When possible
2. **Make base class destructors virtual**: For proper cleanup
3. **Use override keyword**: For virtual function overrides
4. **Avoid deep inheritance hierarchies**: Keep it simple
5. **Design for inheritance or prohibit it**: Make intent clear

### Polymorphism Best Practices
1. **Use pure virtual functions**: For abstract interfaces
2. **Avoid virtual function calls in constructors**: Undefined behavior
3. **Consider performance implications**: Virtual calls have overhead
4. **Use smart pointers**: For automatic memory management

## Common Patterns

### Factory Pattern
```cpp
class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle") return std::make_unique<Circle>();
        if (type == "rectangle") return std::make_unique<Rectangle>();
        return nullptr;
    }
};
```

### Observer Pattern
```cpp
class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void notify() {
        for (auto* obs : observers) obs->update();
    }
};
```

## Compilation

```bash
g++ -std=c++17 filename.cpp -o filename
```

## Modern C++ OOP Features

### C++11 and Later
- **override/final keywords**: Better virtual function control
- **= default/= delete**: Control special member functions
- **Delegating constructors**: Constructor chaining
- **Uniform initialization**: Consistent initialization syntax

### C++20
- **Concepts**: Constrain template parameters
- **Modules**: Better encapsulation and compilation
- **Coroutines**: Cooperative multitasking