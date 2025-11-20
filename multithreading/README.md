# Multithreading and Concurrency

This folder demonstrates C++ multithreading capabilities, synchronization primitives, and concurrent programming patterns.

## Files Overview

- **basic_threading.cpp** - Thread creation, synchronization, and concurrent patterns

## Threading Concepts

### Thread Management
- **std::thread**: Creating and managing threads
- **Thread lifecycle**: Creation, execution, joining/detaching
- **Thread IDs**: Identifying threads
- **Hardware concurrency**: Available CPU cores

### Synchronization Primitives

#### Mutexes
- **std::mutex**: Basic mutual exclusion
- **std::recursive_mutex**: Allows recursive locking
- **std::timed_mutex**: Mutex with timeout capabilities
- **std::shared_mutex**: Reader-writer lock (C++17)

#### Lock Management
- **std::lock_guard**: RAII lock management
- **std::unique_lock**: Flexible lock management
- **std::shared_lock**: Shared ownership lock (C++14)
- **std::scoped_lock**: Multiple mutex locking (C++17)

#### Condition Variables
- **std::condition_variable**: Thread synchronization
- **Producer-consumer patterns**: Coordinating data exchange
- **Wait conditions**: Blocking until conditions are met

#### Atomic Operations
- **std::atomic**: Lock-free thread-safe operations
- **Memory ordering**: Control over memory access ordering
- **Compare-and-swap**: Atomic read-modify-write operations

## Common Patterns

### 1. Producer-Consumer
```cpp
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;

// Producer
void produce() {
    std::lock_guard<std::mutex> lock(mtx);
    buffer.push(data);
    cv.notify_one();
}

// Consumer
void consume() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return !buffer.empty(); });
    int data = buffer.front();
    buffer.pop();
}
```

### 2. Thread Pool
```cpp
class ThreadPool {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};
```

### 3. Reader-Writer Lock
```cpp
std::shared_mutex rw_mutex;

// Reader
void read_data() {
    std::shared_lock<std::shared_mutex> lock(rw_mutex);
    // Multiple readers can access simultaneously
}

// Writer
void write_data() {
    std::unique_lock<std::shared_mutex> lock(rw_mutex);
    // Exclusive access for writing
}
```

## Thread Safety Guidelines

### Thread-Safe Operations
1. **Immutable data**: Read-only data is inherently thread-safe
2. **Local variables**: Each thread has its own stack
3. **Atomic operations**: Lock-free thread-safe operations
4. **Properly synchronized access**: Using mutexes and locks

### Race Conditions
- **Data races**: Concurrent access to shared mutable data
- **Race conditions**: Outcome depends on timing
- **Prevention**: Proper synchronization and atomic operations

### Deadlock Prevention
1. **Lock ordering**: Always acquire locks in the same order
2. **Timeout locks**: Use timed_mutex with timeouts
3. **Lock-free programming**: Use atomic operations
4. **Avoid nested locks**: Minimize lock complexity

## Performance Considerations

### Benefits of Multithreading
- **Parallelism**: Utilize multiple CPU cores
- **Responsiveness**: Background processing
- **Throughput**: Concurrent task execution

### Costs of Multithreading
- **Context switching**: Thread switching overhead
- **Synchronization**: Lock contention and waiting
- **Memory overhead**: Thread stacks and metadata
- **Complexity**: Debugging and maintenance

### Optimization Strategies
1. **Minimize shared state**: Reduce synchronization needs
2. **Use lock-free algorithms**: When possible
3. **Thread-local storage**: Avoid sharing when possible
4. **Work stealing**: Balance load across threads

## Memory Models

### Sequential Consistency
- Default behavior: Operations appear in program order
- Strongest guarantee but may limit optimizations

### Relaxed Ordering
- No ordering constraints except atomicity
- Best performance but requires careful design

### Acquire-Release Ordering
- Synchronizes memory operations between threads
- Balance between performance and safety

## Best Practices

### Do's
1. **Use RAII for locks**: Automatic lock management
2. **Prefer atomic operations**: For simple shared data
3. **Design for immutability**: Reduce shared mutable state
4. **Use thread-safe containers**: When available
5. **Test thoroughly**: Concurrency bugs are hard to find

### Don'ts
1. **Don't share mutable data**: Without proper synchronization
2. **Don't use raw mutexes**: Use lock guards instead
3. **Don't ignore race conditions**: They will cause bugs
4. **Don't over-synchronize**: Can hurt performance
5. **Don't assume atomicity**: Most operations aren't atomic

## Debugging Concurrent Code

### Tools
- **Thread sanitizer**: Detects data races
- **Helgrind (Valgrind)**: Race condition detection
- **Static analysis**: Code analysis tools
- **Logging**: Careful logging for debugging

### Techniques
- **Stress testing**: Run with high thread counts
- **Deterministic testing**: Control thread scheduling
- **Assertion checking**: Verify invariants
- **Code review**: Multiple eyes on concurrent code

## Compilation

For multithreading support:
```bash
g++ -std=c++17 -pthread filename.cpp -o filename
```

## C++20 Additions

- **std::jthread**: Joining thread with stop tokens
- **std::stop_token**: Cooperative cancellation
- **std::counting_semaphore**: Counting semaphore
- **std::binary_semaphore**: Binary semaphore
- **std::latch**: Single-use barrier
- **std::barrier**: Reusable synchronization point