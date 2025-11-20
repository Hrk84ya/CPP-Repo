#include <iostream>
#include <memory>

class Resource {
public:
    Resource(int id) : id_(id) {
        std::cout << "Resource " << id_ << " created\n";
    }
    ~Resource() {
        std::cout << "Resource " << id_ << " destroyed\n";
    }
    void use() { std::cout << "Using resource " << id_ << "\n"; }
private:
    int id_;
};

int main() {
    // unique_ptr - exclusive ownership
    std::unique_ptr<Resource> unique_res = std::make_unique<Resource>(1);
    unique_res->use();
    
    // shared_ptr - shared ownership
    std::shared_ptr<Resource> shared_res1 = std::make_shared<Resource>(2);
    {
        std::shared_ptr<Resource> shared_res2 = shared_res1;
        std::cout << "Reference count: " << shared_res1.use_count() << "\n";
    }
    std::cout << "Reference count after scope: " << shared_res1.use_count() << "\n";
    
    // weak_ptr - non-owning observer
    std::weak_ptr<Resource> weak_res = shared_res1;
    if (auto locked = weak_res.lock()) {
        locked->use();
    }
    
    return 0;
}