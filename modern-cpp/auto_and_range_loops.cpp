#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    // Auto keyword
    auto number = 42;           // int
    auto pi = 3.14159;         // double
    auto message = "Hello";     // const char*
    
    std::cout << "Auto deduced types:\n";
    std::cout << "number: " << number << "\n";
    std::cout << "pi: " << pi << "\n";
    std::cout << "message: " << message << "\n\n";
    
    // Range-based for loops
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    std::cout << "Range-based for loop (read-only):\n";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
    
    std::cout << "Range-based for loop (modifying):\n";
    for (auto& num : numbers) {
        num *= 2;
        std::cout << num << " ";
    }
    std::cout << "\n\n";
    
    // With maps
    std::map<std::string, int> ages = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35}
    };
    
    std::cout << "Map iteration:\n";
    for (const auto& [name, age] : ages) {  // Structured binding (C++17)
        std::cout << name << " is " << age << " years old\n";
    }
    
    // Auto with function return types
    auto get_vector = []() -> std::vector<int> {
        return {10, 20, 30};
    };
    
    auto result = get_vector();
    std::cout << "\nAuto with function return:\n";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    return 0;
}