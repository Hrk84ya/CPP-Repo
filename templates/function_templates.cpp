#include <iostream>
#include <vector>
#include <string>

// Basic function template
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Function template with multiple parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Template with non-type parameters
template<typename T, size_t N>
void print_array(const T (&arr)[N]) {
    std::cout << "Array of size " << N << ": ";
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Variadic template
template<typename T>
void print(T&& t) {
    std::cout << t << "\n";
}

template<typename T, typename... Args>
void print(T&& t, Args&&... args) {
    std::cout << t << " ";
    print(args...);
}

// Template specialization
template<typename T>
void process(T value) {
    std::cout << "Generic processing: " << value << "\n";
}

// Specialization for strings
template<>
void process<std::string>(std::string value) {
    std::cout << "String processing: \"" << value << "\"\n";
}

// SFINAE example
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_type(T value) {
    std::cout << value << " is an integral type\n";
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print_type(T value) {
    std::cout << value << " is a floating point type\n";
}

int main() {
    // Basic template usage
    std::cout << "Maximum of 5 and 3: " << maximum(5, 3) << "\n";
    std::cout << "Maximum of 5.5 and 3.2: " << maximum(5.5, 3.2) << "\n";
    std::cout << "Maximum of 'a' and 'z': " << maximum('a', 'z') << "\n";
    
    // Multiple type parameters
    std::cout << "Add 5 + 3.14: " << add(5, 3.14) << "\n";
    
    // Array template
    int arr[] = {1, 2, 3, 4, 5};
    print_array(arr);
    
    // Variadic template
    std::cout << "Variadic print: ";
    print(1, 2.5, "hello", 'c');
    
    // Template specialization
    process(42);
    process(std::string("Hello World"));
    
    // SFINAE
    print_type(42);
    print_type(3.14);
    
    return 0;
}