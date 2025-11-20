#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <atomic>

// Global variables for demonstration
std::mutex cout_mutex;
std::atomic<int> counter{0};

// Thread-safe print function
void safe_print(const std::string& message) {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "[Thread " << std::this_thread::get_id() << "] " << message << "\n";
}

// Simple worker function
void worker(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        safe_print("Worker " + std::to_string(id) + " iteration " + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        counter++;
    }
}

// Producer-Consumer example
class ProducerConsumer {
private:
    std::vector<int> buffer_;
    std::mutex mutex_;
    std::condition_variable condition_;
    const size_t max_size_ = 5;
    bool done_ = false;
    
public:
    void produce(int items) {
        for (int i = 0; i < items; ++i) {
            std::unique_lock<std::mutex> lock(mutex_);
            
            // Wait until buffer has space
            condition_.wait(lock, [this] { return buffer_.size() < max_size_; });
            
            buffer_.push_back(i);
            safe_print("Produced: " + std::to_string(i) + " (buffer size: " + std::to_string(buffer_.size()) + ")");
            
            condition_.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        
        std::lock_guard<std::mutex> lock(mutex_);
        done_ = true;
        condition_.notify_all();
    }
    
    void consume() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex_);
            
            // Wait until buffer has items or production is done
            condition_.wait(lock, [this] { return !buffer_.empty() || done_; });
            
            if (buffer_.empty() && done_) {
                break;
            }
            
            if (!buffer_.empty()) {
                int item = buffer_.back();
                buffer_.pop_back();
                safe_print("Consumed: " + std::to_string(item) + " (buffer size: " + std::to_string(buffer_.size()) + ")");
                
                condition_.notify_all();
            }
            
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
};

// Atomic operations example
void atomic_operations() {
    safe_print("=== Atomic Operations ===");
    
    std::atomic<int> atomic_counter{0};
    const int num_threads = 4;
    const int increments_per_thread = 1000;
    
    std::vector<std::thread> threads;
    
    // Launch threads that increment the atomic counter
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&atomic_counter, increments_per_thread, i]() {
            for (int j = 0; j < increments_per_thread; ++j) {
                atomic_counter.fetch_add(1);
            }
            safe_print("Thread " + std::to_string(i) + " finished incrementing");
        });
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    safe_print("Final atomic counter value: " + std::to_string(atomic_counter.load()));
    safe_print("Expected value: " + std::to_string(num_threads * increments_per_thread));
}

int main() {
    safe_print("=== Basic Threading Example ===");
    
    // Create and launch threads
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(worker, i, 3);
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    safe_print("All worker threads completed. Counter value: " + std::to_string(counter.load()));
    
    // Producer-Consumer example
    safe_print("\n=== Producer-Consumer Example ===");
    ProducerConsumer pc;
    
    std::thread producer(&ProducerConsumer::produce, &pc, 10);
    std::thread consumer(&ProducerConsumer::consume, &pc);
    
    producer.join();
    consumer.join();
    
    // Atomic operations
    atomic_operations();
    
    // Thread with lambda
    safe_print("\n=== Lambda Thread ===");
    std::thread lambda_thread([]() {
        safe_print("Lambda thread executing");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        safe_print("Lambda thread finished");
    });
    
    lambda_thread.join();
    
    // Hardware concurrency
    safe_print("\nHardware concurrency: " + std::to_string(std::thread::hardware_concurrency()));
    
    return 0;
}