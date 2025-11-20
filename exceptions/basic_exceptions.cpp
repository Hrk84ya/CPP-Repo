#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Custom exception class
class CustomException : public std::exception {
private:
    std::string message_;
    
public:
    CustomException(const std::string& message) : message_(message) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

// Function that throws exceptions
double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

// Function with multiple exception types
int access_vector(const std::vector<int>& vec, size_t index) {
    if (vec.empty()) {
        throw CustomException("Vector is empty");
    }
    if (index >= vec.size()) {
        throw std::out_of_range("Index out of range");
    }
    return vec[index];
}

// RAII example with exception safety
class Resource {
private:
    std::string name_;
    
public:
    Resource(const std::string& name) : name_(name) {
        std::cout << "Acquiring resource: " << name_ << "\n";
        if (name == "bad_resource") {
            throw CustomException("Failed to acquire resource");
        }
    }
    
    ~Resource() {
        std::cout << "Releasing resource: " << name_ << "\n";
    }
    
    void use() {
        std::cout << "Using resource: " << name_ << "\n";
    }
};

void demonstrate_raii() {
    try {
        Resource r1("good_resource");
        r1.use();
        
        Resource r2("bad_resource");  // This will throw
        r2.use();  // This won't execute
        
    } catch (const CustomException& e) {
        std::cout << "RAII Exception caught: " << e.what() << "\n";
        // r1 destructor is automatically called here
    }
}

int main() {
    // Basic exception handling
    std::cout << "=== Basic Exception Handling ===\n";
    try {
        double result = divide(10, 2);
        std::cout << "10 / 2 = " << result << "\n";
        
        result = divide(10, 0);  // This will throw
        std::cout << "This won't print\n";
        
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << "\n";
    }
    
    // Multiple exception types
    std::cout << "\n=== Multiple Exception Types ===\n";
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    try {
        std::cout << "Element at index 2: " << access_vector(numbers, 2) << "\n";
        std::cout << "Element at index 10: " << access_vector(numbers, 10) << "\n";
        
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << "\n";
    } catch (const CustomException& e) {
        std::cout << "Custom exception: " << e.what() << "\n";
    }
    
    // Empty vector test
    try {
        std::vector<int> empty_vec;
        access_vector(empty_vec, 0);
        
    } catch (const CustomException& e) {
        std::cout << "Custom exception: " << e.what() << "\n";
    }
    
    // Catch all exceptions
    std::cout << "\n=== Catch All ===\n";
    try {
        throw std::runtime_error("Unknown error");
        
    } catch (const std::exception& e) {
        std::cout << "Standard exception: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Unknown exception caught\n";
    }
    
    // RAII demonstration
    std::cout << "\n=== RAII Exception Safety ===\n";
    demonstrate_raii();
    
    // Exception specifications (noexcept)
    std::cout << "\n=== Noexcept Function ===\n";
    auto safe_function = []() noexcept {
        std::cout << "This function guarantees no exceptions\n";
        return 42;
    };
    
    std::cout << "Result: " << safe_function() << "\n";
    
    // Rethrowing exceptions
    std::cout << "\n=== Rethrowing Exceptions ===\n";
    try {
        try {
            throw std::runtime_error("Original error");
        } catch (const std::exception& e) {
            std::cout << "Caught and rethrowing: " << e.what() << "\n";
            throw;  // Rethrow the same exception
        }
    } catch (const std::exception& e) {
        std::cout << "Final catch: " << e.what() << "\n";
    }
    
    return 0;
}