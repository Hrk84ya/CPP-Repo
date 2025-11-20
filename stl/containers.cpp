#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>

int main() {
    // Map (ordered)
    std::map<std::string, int> ordered_map;
    ordered_map["apple"] = 5;
    ordered_map["banana"] = 3;
    ordered_map["cherry"] = 8;
    
    std::cout << "Map (ordered by key):\n";
    for (const auto& [key, value] : ordered_map) {
        std::cout << key << ": " << value << "\n";
    }
    
    // Unordered map (hash table)
    std::unordered_map<std::string, int> hash_map;
    hash_map["x"] = 10;
    hash_map["y"] = 20;
    hash_map["z"] = 30;
    
    std::cout << "\nUnordered map:\n";
    for (const auto& [key, value] : hash_map) {
        std::cout << key << ": " << value << "\n";
    }
    
    // Set (unique, ordered)
    std::set<int> ordered_set = {5, 2, 8, 2, 1, 8};
    std::cout << "\nSet (unique, ordered): ";
    for (int val : ordered_set) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    // Unordered set
    std::unordered_set<std::string> hash_set = {"hello", "world", "hello"};
    std::cout << "\nUnordered set: ";
    for (const std::string& str : hash_set) {
        std::cout << str << " ";
    }
    std::cout << "\n";
    
    // Priority queue (max heap by default)
    std::priority_queue<int> max_heap;
    max_heap.push(3);
    max_heap.push(1);
    max_heap.push(4);
    max_heap.push(2);
    
    std::cout << "\nPriority queue (max heap): ";
    while (!max_heap.empty()) {
        std::cout << max_heap.top() << " ";
        max_heap.pop();
    }
    std::cout << "\n";
    
    // Min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    min_heap.push(3);
    min_heap.push(1);
    min_heap.push(4);
    min_heap.push(2);
    
    std::cout << "Priority queue (min heap): ";
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }
    std::cout << "\n";
    
    // Deque (double-ended queue)
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(4);
    
    std::cout << "\nDeque: ";
    for (int val : dq) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    // Stack
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    std::cout << "\nStack (LIFO): ";
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << "\n";
    
    return 0;
}