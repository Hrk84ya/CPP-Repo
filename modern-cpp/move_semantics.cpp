#include <iostream>
#include <vector>
#include <string>
#include <utility>

class MoveExample {
private:
    std::vector<int> data_;
    std::string name_;
    
public:
    // Constructor
    MoveExample(const std::string& name, size_t size) 
        : name_(name), data_(size, 42) {
        std::cout << "Constructor: " << name_ << " (size: " << size << ")\n";
    }
    
    // Copy constructor
    MoveExample(const MoveExample& other) 
        : name_(other.name_ + "_copy"), data_(other.data_) {
        std::cout << "Copy constructor: " << name_ << "\n";
    }
    
    // Move constructor
    MoveExample(MoveExample&& other) noexcept
        : name_(std::move(other.name_)), data_(std::move(other.data_)) {
        std::cout << "Move constructor: " << name_ << "\n";
        other.name_ = "moved_from";
    }
    
    // Copy assignment
    MoveExample& operator=(const MoveExample& other) {
        if (this != &other) {
            name_ = other.name_ + "_assigned";
            data_ = other.data_;
            std::cout << "Copy assignment: " << name_ << "\n";
        }
        return *this;
    }
    
    // Move assignment
    MoveExample& operator=(MoveExample&& other) noexcept {
        if (this != &other) {
            name_ = std::move(other.name_);
            data_ = std::move(other.data_);
            std::cout << "Move assignment: " << name_ << "\n";
            other.name_ = "moved_from";
        }
        return *this;
    }
    
    void print() const {
        std::cout << "Object: " << name_ << ", data size: " << data_.size() << "\n";
    }
};

MoveExample create_object() {
    return MoveExample("factory_created", 1000);
}

int main() {
    std::cout << "=== Move Semantics Demo ===\n\n";
    
    // Regular construction
    MoveExample obj1("original", 500);
    obj1.print();
    
    // Copy construction
    MoveExample obj2 = obj1;
    obj2.print();
    
    // Move construction with std::move
    MoveExample obj3 = std::move(obj1);
    obj3.print();
    obj1.print();  // obj1 is now in moved-from state
    
    // Move from function return (RVO might optimize this)
    MoveExample obj4 = create_object();
    obj4.print();
    
    // Move assignment
    obj2 = std::move(obj3);
    obj2.print();
    obj3.print();  // obj3 is now in moved-from state
    
    std::cout << "\n=== Perfect Forwarding Example ===\n";
    
    // Perfect forwarding example
    auto forward_and_create = [](auto&& name, auto&& size) {
        return MoveExample(std::forward<decltype(name)>(name), 
                          std::forward<decltype(size)>(size));
    };
    
    std::string temp_name = "forwarded";
    MoveExample obj5 = forward_and_create(std::move(temp_name), 200);
    obj5.print();
    
    return 0;
}