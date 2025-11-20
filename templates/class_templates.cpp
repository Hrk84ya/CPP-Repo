#include <iostream>
#include <vector>
#include <memory>

// Basic class template
template<typename T>
class Stack {
private:
    std::vector<T> elements_;
    
public:
    void push(const T& element) {
        elements_.push_back(element);
    }
    
    void pop() {
        if (!elements_.empty()) {
            elements_.pop_back();
        }
    }
    
    T& top() {
        return elements_.back();
    }
    
    const T& top() const {
        return elements_.back();
    }
    
    bool empty() const {
        return elements_.empty();
    }
    
    size_t size() const {
        return elements_.size();
    }
};

// Template with multiple parameters and default values
template<typename T, typename Container = std::vector<T>>
class Queue {
private:
    Container container_;
    
public:
    void push(const T& element) {
        container_.push_back(element);
    }
    
    void pop() {
        if (!container_.empty()) {
            container_.erase(container_.begin());
        }
    }
    
    T& front() {
        return container_.front();
    }
    
    bool empty() const {
        return container_.empty();
    }
};

// Template specialization
template<typename T>
class Vector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;
    
public:
    Vector() : data_(nullptr), size_(0), capacity_(0) {}
    
    ~Vector() {
        delete[] data_;
    }
    
    void push_back(const T& value) {
        if (size_ >= capacity_) {
            resize();
        }
        data_[size_++] = value;
    }
    
    T& operator[](size_t index) {
        return data_[index];
    }
    
    size_t size() const { return size_; }
    
private:
    void resize() {
        capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2;
        T* new_data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
    }
};

// Specialization for bool (bit vector)
template<>
class Vector<bool> {
private:
    std::vector<unsigned char> data_;
    size_t size_;
    
public:
    Vector() : size_(0) {}
    
    void push_back(bool value) {
        if (size_ % 8 == 0) {
            data_.push_back(0);
        }
        if (value) {
            data_[size_ / 8] |= (1 << (size_ % 8));
        }
        ++size_;
    }
    
    bool operator[](size_t index) const {
        return (data_[index / 8] & (1 << (index % 8))) != 0;
    }
    
    size_t size() const { return size_; }
};

// Template template parameter
template<template<typename> class Container, typename T>
class Adapter {
private:
    Container<T> container_;
    
public:
    void add(const T& item) {
        container_.push_back(item);
    }
    
    void process() {
        std::cout << "Processing " << container_.size() << " items\n";
    }
};

int main() {
    // Basic stack usage
    Stack<int> int_stack;
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    
    std::cout << "Stack contents: ";
    while (!int_stack.empty()) {
        std::cout << int_stack.top() << " ";
        int_stack.pop();
    }
    std::cout << "\n";
    
    // Queue usage
    Queue<std::string> string_queue;
    string_queue.push("first");
    string_queue.push("second");
    string_queue.push("third");
    
    std::cout << "Queue contents: ";
    while (!string_queue.empty()) {
        std::cout << string_queue.front() << " ";
        string_queue.pop();
    }
    std::cout << "\n";
    
    // Custom vector
    Vector<int> int_vector;
    for (int i = 0; i < 5; ++i) {
        int_vector.push_back(i * 10);
    }
    
    std::cout << "Vector contents: ";
    for (size_t i = 0; i < int_vector.size(); ++i) {
        std::cout << int_vector[i] << " ";
    }
    std::cout << "\n";
    
    // Specialized bool vector
    Vector<bool> bool_vector;
    bool_vector.push_back(true);
    bool_vector.push_back(false);
    bool_vector.push_back(true);
    bool_vector.push_back(true);
    
    std::cout << "Bool vector contents: ";
    for (size_t i = 0; i < bool_vector.size(); ++i) {
        std::cout << bool_vector[i] << " ";
    }
    std::cout << "\n";
    
    // Template template parameter
    Adapter<std::vector, int> adapter;
    adapter.add(1);
    adapter.add(2);
    adapter.process();
    
    return 0;
}