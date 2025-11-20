#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, typename Compare = std::less<T>>
class Heap {
private:
    std::vector<T> data;
    Compare comp;
    
    size_t parent(size_t i) { return (i - 1) / 2; }
    size_t left_child(size_t i) { return 2 * i + 1; }
    size_t right_child(size_t i) { return 2 * i + 2; }
    
    void heapify_up(size_t index) {
        while (index > 0 && comp(data[parent(index)], data[index])) {
            std::swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapify_down(size_t index) {
        size_t largest = index;
        size_t left = left_child(index);
        size_t right = right_child(index);
        
        if (left < data.size() && comp(data[largest], data[left])) {
            largest = left;
        }
        
        if (right < data.size() && comp(data[largest], data[right])) {
            largest = right;
        }
        
        if (largest != index) {
            std::swap(data[index], data[largest]);
            heapify_down(largest);
        }
    }
    
public:
    Heap() = default;
    
    Heap(const std::vector<T>& elements) : data(elements) {
        // Build heap from bottom up
        for (int i = data.size() / 2 - 1; i >= 0; --i) {
            heapify_down(i);
        }
    }
    
    void push(const T& value) {
        data.push_back(value);
        heapify_up(data.size() - 1);
    }
    
    void pop() {
        if (empty()) return;
        
        data[0] = data.back();
        data.pop_back();
        
        if (!empty()) {
            heapify_down(0);
        }
    }
    
    const T& top() const {
        return data[0];
    }
    
    bool empty() const {
        return data.empty();
    }
    
    size_t size() const {
        return data.size();
    }
    
    void print() const {
        std::cout << "Heap: ";
        for (const T& val : data) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    
    // Print heap as a tree structure
    void print_tree() const {
        if (empty()) return;
        
        std::cout << "Heap tree structure:\n";
        print_tree_helper(0, 0);
    }
    
private:
    void print_tree_helper(size_t index, int depth) const {
        if (index >= data.size()) return;
        
        // Print right subtree first
        print_tree_helper(right_child(index), depth + 1);
        
        // Print current node with indentation
        for (int i = 0; i < depth; ++i) {
            std::cout << "    ";
        }
        std::cout << data[index] << "\n";
        
        // Print left subtree
        print_tree_helper(left_child(index), depth + 1);
    }
};

// Heap sort implementation
template<typename T>
void heap_sort(std::vector<T>& arr) {
    // Build max heap
    Heap<T, std::greater<T>> max_heap(arr);
    
    arr.clear();
    
    // Extract elements in sorted order
    while (!max_heap.empty()) {
        arr.push_back(max_heap.top());
        max_heap.pop();
    }
}

int main() {
    std::cout << "=== Max Heap Example ===\n";
    
    // Max heap (default behavior with std::less)
    Heap<int, std::greater<int>> max_heap;
    
    std::vector<int> values = {4, 10, 3, 5, 1, 15, 20, 17};
    
    std::cout << "Inserting values: ";
    for (int val : values) {
        std::cout << val << " ";
        max_heap.push(val);
    }
    std::cout << "\n\n";
    
    max_heap.print();
    max_heap.print_tree();
    
    std::cout << "\nExtracting elements from max heap:\n";
    while (!max_heap.empty()) {
        std::cout << "Top: " << max_heap.top() << "\n";
        max_heap.pop();
        if (!max_heap.empty()) {
            max_heap.print();
        }
    }
    
    std::cout << "\n=== Min Heap Example ===\n";
    
    // Min heap
    Heap<int> min_heap;
    
    for (int val : values) {
        min_heap.push(val);
    }
    
    min_heap.print();
    min_heap.print_tree();
    
    std::cout << "\nExtracting elements from min heap:\n";
    while (!min_heap.empty()) {
        std::cout << "Top: " << min_heap.top() << "\n";
        min_heap.pop();
    }
    
    std::cout << "\n=== Build Heap from Array ===\n";
    
    std::vector<int> array = {4, 10, 3, 5, 1, 15, 20, 17, 8, 12};
    std::cout << "Original array: ";
    for (int val : array) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    Heap<int, std::greater<int>> built_heap(array);
    built_heap.print();
    built_heap.print_tree();
    
    std::cout << "\n=== Heap Sort ===\n";
    
    std::vector<int> to_sort = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Before sorting: ";
    for (int val : to_sort) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    heap_sort(to_sort);
    
    std::cout << "After heap sort: ";
    for (int val : to_sort) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    return 0;
}