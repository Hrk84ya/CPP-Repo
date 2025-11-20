# C++ Code Repository

A comprehensive collection of C++ code examples covering fundamental to advanced programming concepts, data structures, algorithms, and modern C++ features.

## 📁 Repository Structure

```
CPP-Repo/
├── basics/              # Fundamental C++ concepts
├── oop/                 # Object-oriented programming
├── data-structures/     # Data structure implementations
├── algorithms/          # Algorithm implementations
├── modern-cpp/          # Modern C++ features (C++11+)
├── stl/                 # Standard Template Library examples
├── templates/           # Template programming
├── exceptions/          # Exception handling
├── multithreading/      # Concurrent programming
├── tests/               # Unit tests and testing framework
├── Makefile            # Build automation
└── .gitignore          # Git ignore rules
```

## 🚀 Quick Start

### Prerequisites
- C++ compiler supporting C++17 or later (GCC, Clang, MSVC)
- Make (optional, for using Makefile)

### Clone and Build
```bash
git clone git@github.com:Hrk84ya/CPP-Repo.git
cd CPP-Repo

# Build all examples
make all

# Or build specific categories
make basics
make algorithms
make modern-cpp
```

### Manual Compilation
```bash
g++ -std=c++17 -Wall -Wextra filename.cpp -o filename
./filename
```

## 📚 Learning Path

### 1. **Basics** (`basics/`)
Start here if you're new to C++:
- Variables, data types, operators
- Control flow (if/else, loops, switch)
- Functions and scope
- Input/output operations

### 2. **Object-Oriented Programming** (`oop/`)
Learn OOP concepts:
- Classes and objects
- Encapsulation, inheritance, polymorphism
- Constructors and destructors
- Access modifiers

### 3. **Data Structures** (`data-structures/`)
Implement and understand:
- Arrays, vectors, linked lists
- Stacks, queues, trees
- Hash tables, heaps
- Graph representations

### 4. **Algorithms** (`algorithms/`)
Master algorithmic thinking:
- Sorting and searching
- Dynamic programming
- Graph algorithms
- String processing
- Backtracking

### 5. **Modern C++** (`modern-cpp/`)
Explore modern features:
- Smart pointers
- Lambda expressions
- Move semantics
- Auto keyword and range-based loops

### 6. **Advanced Topics**
- **STL** (`stl/`): Containers, algorithms, iterators
- **Templates** (`templates/`): Generic programming
- **Exceptions** (`exceptions/`): Error handling
- **Multithreading** (`multithreading/`): Concurrent programming

## 🧪 Testing

Run the included unit tests:
```bash
make tests
./tests/test_data_structures
./tests/test_algorithms
```

## 📖 Documentation

Each folder contains its own README with:
- File descriptions
- Key concepts explained
- Compilation instructions
- Learning objectives

## 🛠️ Build System

### Makefile Targets
- `make all` - Build all examples
- `make basics` - Build basic examples
- `make oop` - Build OOP examples
- `make algorithms` - Build algorithm examples
- `make data-structures` - Build data structure examples
- `make modern-cpp` - Build modern C++ examples
- `make stl` - Build STL examples
- `make templates` - Build template examples
- `make exceptions` - Build exception examples
- `make multithreading` - Build multithreading examples
- `make tests` - Build and run tests
- `make clean` - Remove all executables
- `make debug FILE=filename.cpp` - Build with debug flags

## 🤝 Contributing

Contributions are welcome! Please follow these guidelines:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/new-algorithm`)
3. **Follow** the existing code style and structure
4. **Add** appropriate comments and documentation
5. **Include** example usage in main() function
6. **Test** your code thoroughly
7. **Commit** your changes (`git commit -am 'Add new sorting algorithm'`)
8. **Push** to the branch (`git push origin feature/new-algorithm`)
9. **Create** a Pull Request

### Code Standards
- Use meaningful variable and function names
- Include comprehensive comments
- Follow consistent indentation (4 spaces)
- Add example usage and expected output
- Ensure code compiles with C++17 standard

## 📊 Repository Statistics

- **70+** C++ files covering various topics
- **Organized** into logical categories
- **Comprehensive** examples with explanations
- **Modern C++** features and best practices
- **Unit tests** for quality assurance
- **Build automation** with Makefile

## 🎯 Learning Objectives

After working through this repository, you will:
- Master C++ fundamentals and advanced concepts
- Understand data structures and their implementations
- Know common algorithms and their complexities
- Be familiar with modern C++ features and best practices
- Have experience with template programming
- Understand concurrent programming concepts
- Know how to write and run unit tests

## 🙏 Acknowledgments

- C++ community for best practices and standards
- Contributors who help improve the repository
- Educational resources that inspire these examples

