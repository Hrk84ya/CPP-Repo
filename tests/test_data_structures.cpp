#include "simple_test_framework.h"
#include <vector>
#include <stack>
#include <queue>

// Simple Stack implementation for testing
template<typename T>
class TestStack {
private:
    std::vector<T> data;
    
public:
    void push(const T& item) {
        data.push_back(item);
    }
    
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }
    
    T top() const {
        return data.back();
    }
    
    bool empty() const {
        return data.empty();
    }
    
    size_t size() const {
        return data.size();
    }
};

// Simple Queue implementation for testing
template<typename T>
class TestQueue {
private:
    std::vector<T> data;
    size_t front_index = 0;
    
public:
    void push(const T& item) {
        data.push_back(item);
    }
    
    void pop() {
        if (front_index < data.size()) {
            front_index++;
        }
    }
    
    T front() const {
        return data[front_index];
    }
    
    bool empty() const {
        return front_index >= data.size();
    }
    
    size_t size() const {
        return data.size() - front_index;
    }
};

void test_stack_operations() {
    TestStack<int> stack;
    
    // Test empty stack
    SimpleTest::assert_true("Stack initially empty", stack.empty());
    SimpleTest::assert_equal("Stack initial size", 0, static_cast<int>(stack.size()));
    
    // Test push operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    SimpleTest::assert_false("Stack not empty after pushes", stack.empty());
    SimpleTest::assert_equal("Stack size after 3 pushes", 3, static_cast<int>(stack.size()));
    SimpleTest::assert_equal("Stack top element", 30, stack.top());
    
    // Test pop operations
    stack.pop();
    SimpleTest::assert_equal("Stack top after one pop", 20, stack.top());
    SimpleTest::assert_equal("Stack size after one pop", 2, static_cast<int>(stack.size()));
    
    stack.pop();
    stack.pop();
    SimpleTest::assert_true("Stack empty after all pops", stack.empty());
}

void test_queue_operations() {
    TestQueue<int> queue;
    
    // Test empty queue
    SimpleTest::assert_true("Queue initially empty", queue.empty());
    SimpleTest::assert_equal("Queue initial size", 0, static_cast<int>(queue.size()));
    
    // Test enqueue operations
    queue.push(10);
    queue.push(20);
    queue.push(30);
    
    SimpleTest::assert_false("Queue not empty after pushes", queue.empty());
    SimpleTest::assert_equal("Queue size after 3 pushes", 3, static_cast<int>(queue.size()));
    SimpleTest::assert_equal("Queue front element", 10, queue.front());
    
    // Test dequeue operations
    queue.pop();
    SimpleTest::assert_equal("Queue front after one pop", 20, queue.front());
    SimpleTest::assert_equal("Queue size after one pop", 2, static_cast<int>(queue.size()));
    
    queue.pop();
    SimpleTest::assert_equal("Queue front after second pop", 30, queue.front());
    
    queue.pop();
    SimpleTest::assert_true("Queue empty after all pops", queue.empty());
}

void test_vector_operations() {
    std::vector<int> vec;
    
    // Test empty vector
    SimpleTest::assert_true("Vector initially empty", vec.empty());
    SimpleTest::assert_equal("Vector initial size", 0, static_cast<int>(vec.size()));
    
    // Test push_back
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    SimpleTest::assert_equal("Vector size after pushes", 3, static_cast<int>(vec.size()));
    SimpleTest::assert_equal("Vector first element", 1, vec[0]);
    SimpleTest::assert_equal("Vector last element", 3, vec[2]);
    
    // Test insert
    vec.insert(vec.begin() + 1, 10);
    SimpleTest::assert_equal("Vector size after insert", 4, static_cast<int>(vec.size()));
    SimpleTest::assert_equal("Vector element at index 1", 10, vec[1]);
    
    // Test erase
    vec.erase(vec.begin() + 1);
    SimpleTest::assert_equal("Vector size after erase", 3, static_cast<int>(vec.size()));
    SimpleTest::assert_equal("Vector element at index 1", 2, vec[1]);
    
    // Test clear
    vec.clear();
    SimpleTest::assert_true("Vector empty after clear", vec.empty());
}

void test_stl_stack() {
    std::stack<std::string> stack;
    
    SimpleTest::assert_true("STL Stack initially empty", stack.empty());
    
    stack.push("first");
    stack.push("second");
    stack.push("third");
    
    SimpleTest::assert_equal("STL Stack size", 3, static_cast<int>(stack.size()));
    SimpleTest::assert_equal("STL Stack top", std::string("third"), stack.top());
    
    stack.pop();
    SimpleTest::assert_equal("STL Stack top after pop", std::string("second"), stack.top());
}

void test_stl_queue() {
    std::queue<char> queue;
    
    SimpleTest::assert_true("STL Queue initially empty", queue.empty());
    
    queue.push('A');
    queue.push('B');
    queue.push('C');
    
    SimpleTest::assert_equal("STL Queue size", 3, static_cast<int>(queue.size()));
    SimpleTest::assert_equal("STL Queue front", 'A', queue.front());
    SimpleTest::assert_equal("STL Queue back", 'C', queue.back());
    
    queue.pop();
    SimpleTest::assert_equal("STL Queue front after pop", 'B', queue.front());
}

int main() {
    std::cout << "=== Data Structures Unit Tests ===\n";
    
    SimpleTest::run_test("Stack Operations", test_stack_operations);
    SimpleTest::run_test("Queue Operations", test_queue_operations);
    SimpleTest::run_test("Vector Operations", test_vector_operations);
    SimpleTest::run_test("STL Stack", test_stl_stack);
    SimpleTest::run_test("STL Queue", test_stl_queue);
    
    SimpleTest::print_summary();
    
    return 0;
}