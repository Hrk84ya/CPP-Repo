#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    // Basic lambda
    auto print = [](int n) { std::cout << n << " "; };
    
    std::cout << "Original: ";
    std::for_each(numbers.begin(), numbers.end(), print);
    std::cout << "\n";
    
    // Lambda with capture
    int threshold = 5;
    auto count_greater = [threshold](const std::vector<int>& vec) {
        return std::count_if(vec.begin(), vec.end(), 
                           [threshold](int n) { return n > threshold; });
    };
    
    std::cout << "Numbers > " << threshold << ": " << count_greater(numbers) << "\n";
    
    // Mutable lambda
    int multiplier = 2;
    auto multiply_and_increment = [multiplier](int n) mutable {
        return n * (multiplier++);
    };
    
    std::cout << "Transformed: ";
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), multiply_and_increment);
    std::for_each(numbers.begin(), numbers.end(), print);
    std::cout << "\n";
    
    // Generic lambda (C++14)
    auto generic_print = [](const auto& item) {
        std::cout << item << " ";
    };
    
    std::cout << "Generic lambda: ";
    generic_print(42);
    generic_print(3.14);
    generic_print("Hello");
    std::cout << "\n";
    
    return 0;
}