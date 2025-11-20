#include "simple_test_framework.h"
#include <vector>
#include <algorithm>

// Sorting algorithms for testing
void bubble_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binary_search(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Not found
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

bool is_palindrome(const std::string& str) {
    int left = 0, right = str.length() - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

void test_bubble_sort() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> expected = {11, 12, 22, 25, 34, 64, 90};
    
    bubble_sort(arr);
    
    SimpleTest::assert_equal("Bubble sort array size", static_cast<int>(expected.size()), static_cast<int>(arr.size()));
    
    bool arrays_equal = true;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] != expected[i]) {
            arrays_equal = false;
            break;
        }
    }
    
    SimpleTest::assert_true("Bubble sort correctness", arrays_equal);
}

void test_binary_search() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    // Test existing elements
    SimpleTest::assert_equal("Binary search - find 7", 3, binary_search(arr, 7));
    SimpleTest::assert_equal("Binary search - find 1", 0, binary_search(arr, 1));
    SimpleTest::assert_equal("Binary search - find 19", 9, binary_search(arr, 19));
    
    // Test non-existing elements
    SimpleTest::assert_equal("Binary search - not found 6", -1, binary_search(arr, 6));
    SimpleTest::assert_equal("Binary search - not found 20", -1, binary_search(arr, 20));
    SimpleTest::assert_equal("Binary search - not found 0", -1, binary_search(arr, 0));
}

void test_fibonacci() {
    SimpleTest::assert_equal("Fibonacci(0)", 0, fibonacci(0));
    SimpleTest::assert_equal("Fibonacci(1)", 1, fibonacci(1));
    SimpleTest::assert_equal("Fibonacci(2)", 1, fibonacci(2));
    SimpleTest::assert_equal("Fibonacci(3)", 2, fibonacci(3));
    SimpleTest::assert_equal("Fibonacci(4)", 3, fibonacci(4));
    SimpleTest::assert_equal("Fibonacci(5)", 5, fibonacci(5));
    SimpleTest::assert_equal("Fibonacci(6)", 8, fibonacci(6));
    SimpleTest::assert_equal("Fibonacci(7)", 13, fibonacci(7));
}

void test_palindrome() {
    SimpleTest::assert_true("Palindrome - 'racecar'", is_palindrome("racecar"));
    SimpleTest::assert_true("Palindrome - 'madam'", is_palindrome("madam"));
    SimpleTest::assert_true("Palindrome - 'a'", is_palindrome("a"));
    SimpleTest::assert_true("Palindrome - empty string", is_palindrome(""));
    
    SimpleTest::assert_false("Not palindrome - 'hello'", is_palindrome("hello"));
    SimpleTest::assert_false("Not palindrome - 'world'", is_palindrome("world"));
    SimpleTest::assert_false("Not palindrome - 'ab'", is_palindrome("ab"));
}

void test_stl_algorithms() {
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};
    
    // Test std::sort
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());
    SimpleTest::assert_equal("STL sort - first element", 1, sorted_arr[0]);
    SimpleTest::assert_equal("STL sort - last element", 9, sorted_arr[5]);
    
    // Test std::find
    auto it = std::find(arr.begin(), arr.end(), 8);
    SimpleTest::assert_true("STL find - element exists", it != arr.end());
    SimpleTest::assert_equal("STL find - correct value", 8, *it);
    
    auto not_found = std::find(arr.begin(), arr.end(), 10);
    SimpleTest::assert_true("STL find - element not exists", not_found == arr.end());
    
    // Test std::count
    arr.push_back(5); // Add duplicate
    int count_5 = std::count(arr.begin(), arr.end(), 5);
    SimpleTest::assert_equal("STL count - count of 5", 2, count_5);
    
    // Test std::max_element
    auto max_it = std::max_element(arr.begin(), arr.end());
    SimpleTest::assert_equal("STL max_element", 9, *max_it);
    
    // Test std::min_element
    auto min_it = std::min_element(arr.begin(), arr.end());
    SimpleTest::assert_equal("STL min_element", 1, *min_it);
}

void test_edge_cases() {
    // Empty array binary search
    std::vector<int> empty_arr;
    SimpleTest::assert_equal("Binary search - empty array", -1, binary_search(empty_arr, 5));
    
    // Single element array
    std::vector<int> single = {42};
    SimpleTest::assert_equal("Binary search - single element found", 0, binary_search(single, 42));
    SimpleTest::assert_equal("Binary search - single element not found", -1, binary_search(single, 43));
    
    // Empty string palindrome (already tested above)
    // Single character palindrome (already tested above)
}

int main() {
    std::cout << "=== Algorithm Unit Tests ===\n";
    
    SimpleTest::run_test("Bubble Sort", test_bubble_sort);
    SimpleTest::run_test("Binary Search", test_binary_search);
    SimpleTest::run_test("Fibonacci", test_fibonacci);
    SimpleTest::run_test("Palindrome Check", test_palindrome);
    SimpleTest::run_test("STL Algorithms", test_stl_algorithms);
    SimpleTest::run_test("Edge Cases", test_edge_cases);
    
    SimpleTest::print_summary();
    
    return 0;
}