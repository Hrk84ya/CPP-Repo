#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename K, typename V>
class HashTable {
private:
    struct KeyValue {
        K key;
        V value;
        KeyValue(const K& k, const V& v) : key(k), value(v) {}
    };
    
    std::vector<std::list<KeyValue>> table;
    size_t bucket_count;
    size_t size_;
    
    size_t hash(const K& key) const {
        return std::hash<K>{}(key) % bucket_count;
    }
    
    void rehash() {
        if (size_ > bucket_count * 0.75) {  // Load factor > 0.75
            std::vector<std::list<KeyValue>> old_table = std::move(table);
            bucket_count *= 2;
            table = std::vector<std::list<KeyValue>>(bucket_count);
            size_ = 0;
            
            for (const auto& bucket : old_table) {
                for (const auto& kv : bucket) {
                    insert(kv.key, kv.value);
                }
            }
        }
    }
    
public:
    HashTable(size_t initial_size = 16) : bucket_count(initial_size), size_(0) {
        table.resize(bucket_count);
    }
    
    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        
        // Check if key already exists
        for (auto& kv : table[index]) {
            if (kv.key == key) {
                kv.value = value;  // Update existing value
                return;
            }
        }
        
        // Insert new key-value pair
        table[index].emplace_back(key, value);
        size_++;
        rehash();
    }
    
    bool find(const K& key, V& value) const {
        size_t index = hash(key);
        
        for (const auto& kv : table[index]) {
            if (kv.key == key) {
                value = kv.value;
                return true;
            }
        }
        return false;
    }
    
    bool remove(const K& key) {
        size_t index = hash(key);
        
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                size_--;
                return true;
            }
        }
        return false;
    }
    
    size_t size() const { return size_; }
    
    double load_factor() const {
        return static_cast<double>(size_) / bucket_count;
    }
    
    void print() const {
        std::cout << "Hash Table (size: " << size_ << ", buckets: " << bucket_count 
                  << ", load factor: " << load_factor() << "):\n";
        
        for (size_t i = 0; i < bucket_count; ++i) {
            if (!table[i].empty()) {
                std::cout << "Bucket " << i << ": ";
                for (const auto& kv : table[i]) {
                    std::cout << "[" << kv.key << ":" << kv.value << "] ";
                }
                std::cout << "\n";
            }
        }
    }
    
    void print_stats() const {
        size_t empty_buckets = 0;
        size_t max_chain_length = 0;
        
        for (const auto& bucket : table) {
            if (bucket.empty()) {
                empty_buckets++;
            } else {
                max_chain_length = std::max(max_chain_length, bucket.size());
            }
        }
        
        std::cout << "Statistics:\n";
        std::cout << "  Total buckets: " << bucket_count << "\n";
        std::cout << "  Empty buckets: " << empty_buckets << "\n";
        std::cout << "  Used buckets: " << (bucket_count - empty_buckets) << "\n";
        std::cout << "  Max chain length: " << max_chain_length << "\n";
        std::cout << "  Load factor: " << load_factor() << "\n";
    }
};

// Simple hash function for strings (for demonstration)
class SimpleStringHash {
public:
    size_t operator()(const std::string& str) const {
        size_t hash = 0;
        for (char c : str) {
            hash = hash * 31 + c;
        }
        return hash;
    }
};

int main() {
    std::cout << "=== Hash Table Example ===\n";
    
    HashTable<std::string, int> ht;
    
    // Insert some key-value pairs
    ht.insert("apple", 5);
    ht.insert("banana", 3);
    ht.insert("orange", 8);
    ht.insert("grape", 12);
    ht.insert("kiwi", 2);
    
    ht.print();
    std::cout << "\n";
    
    // Search for values
    int value;
    if (ht.find("banana", value)) {
        std::cout << "Found banana: " << value << "\n";
    }
    
    if (ht.find("mango", value)) {
        std::cout << "Found mango: " << value << "\n";
    } else {
        std::cout << "Mango not found\n";
    }
    
    // Update existing key
    ht.insert("apple", 10);
    std::cout << "\nAfter updating apple to 10:\n";
    ht.print();
    
    // Remove a key
    if (ht.remove("grape")) {
        std::cout << "\nRemoved grape successfully\n";
    }
    ht.print();
    
    // Add more items to trigger rehashing
    std::cout << "\nAdding more items to trigger rehashing:\n";
    for (int i = 0; i < 20; ++i) {
        ht.insert("item" + std::to_string(i), i);
    }
    
    ht.print_stats();
    
    // Integer hash table
    std::cout << "\n=== Integer Hash Table ===\n";
    HashTable<int, std::string> int_ht;
    
    int_ht.insert(1, "one");
    int_ht.insert(2, "two");
    int_ht.insert(17, "seventeen");  // Might collide with 1 in small table
    int_ht.insert(33, "thirty-three");  // Might collide with 1 in small table
    
    int_ht.print();
    int_ht.print_stats();
    
    return 0;
}