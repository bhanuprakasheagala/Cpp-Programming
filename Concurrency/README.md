# C++ Concurrency Guide

This README provides a comprehensive guide to understanding concurrency in C++. It explains the various constructs used for multithreading, synchronization, and how they work internally. Additionally, it provides scenarios, use cases, and examples with ASCII diagrams to illustrate how different concurrency concepts work.

## Table of Contents

1. [Introduction to C++ Concurrency](#introduction-to-c-concurrency)
2. [Basic Threading](#basic-threading)
3. [Mutexes and Locks](#mutexes-and-locks)
4. [Condition Variables](#condition-variables)
5. [Atomic Operations](#atomic-operations)
6. [Thread Safety and Best Practices](#thread-safety-and-best-practices)
7. [Advanced Thread Synchronization](#advanced-thread-synchronization)
8. [Examples and Scenarios](#examples-and-scenarios)
9. [Conclusion](#conclusion)

---

## 1. Introduction to C++ Concurrency

C++ concurrency provides mechanisms that allow programs to perform multiple tasks simultaneously using threads. The C++ Standard Library provides several constructs to help manage threads, mutexes, locks, condition variables, and atomic operations. These tools allow developers to create efficient and safe multi-threaded applications.

### Key Concurrency Concepts:
- **Threads**: The smallest unit of execution within a process.
- **Mutexes**: Prevent data races by ensuring that only one thread can access a shared resource at a time.
- **Condition Variables**: Used for thread synchronization, enabling threads to wait for certain conditions to be met.
- **Atomic Operations**: Ensures safe access to shared variables without requiring locks.
  
Concurrency can be tricky, especially when shared data needs to be accessed or modified. Ensuring **thread safety** is crucial in any multithreaded application to avoid **data races**.

---

## 2. Basic Threading

C++ provides `std::thread` to manage and launch threads. Each thread can run a function concurrently.

### Basic Thread Creation

```cpp
#include <iostream>
#include <thread>

void print_hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(print_hello);  // Creating and starting a thread
    t.join();  // Wait for the thread to finish before continuing
    return 0;
}
```

- **`std::thread`**: Represents a thread of execution.
- **`join()`**: Waits for the thread to complete its execution.
- **`detach()`**: Allows the thread to execute independently, but you lose control over its completion.

---

## 3. Mutexes and Locks

### Mutex (`std::mutex`)

A **mutex** is used to prevent multiple threads from simultaneously accessing shared resources. If one thread locks a mutex, other threads must wait until it is unlocked.

### Locking Mechanism

A lock provides exclusive access to a shared resource.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex object

void print_numbers(int id) {
    std::lock_guard<std::mutex> lock(mtx);  // Locking the mutex
    std::cout << "Thread " << id << " is printing numbers." << std::endl;
}

int main() {
    std::thread t1(print_numbers, 1);
    std::thread t2(print_numbers, 2);
    
    t1.join();
    t2.join();
    
    return 0;
}
```

- **`std::lock_guard<std::mutex>`**: A RAII-style lock that automatically locks the mutex when the object is created and unlocks it when the object goes out of scope.
  
- **`std::unique_lock<std::mutex>`**: More flexible than `std::lock_guard`, allows explicit locking and unlocking.

---

## 4. Condition Variables

A **condition variable** allows threads to wait for some condition to be met before they continue executing. It’s used for synchronization between threads.

### `std::condition_variable` Example

```cpp
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_numbers() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [](){ return ready; });  // Wait until 'ready' becomes true
    std::cout << "Thread started printing." << std::endl;
}

void notify() {
    std::unique_lock<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one();  // Notify one thread
}

int main() {
    std::thread t1(print_numbers);
    std::thread t2(notify);
    
    t1.join();
    t2.join();
    
    return 0;
}
```

- **`cv.wait(lock)`**: Blocks the current thread until it’s notified and the condition is true.
- **`cv.notify_one()`**: Wakes up one waiting thread.
- **`cv.notify_all()`**: Wakes up all waiting threads.

### Scenario: Producer-Consumer with Condition Variables

```cpp
#include <queue>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> data_queue;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex> lock(mtx);
        data_queue.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_all();  // Notify consumers
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return !data_queue.empty(); });  // Wait until data is available
        int data = data_queue.front();
        data_queue.pop();
        std::cout << "Consumed: " << data << std::endl;
        if (data == 4) break;  // Exit after consuming the last item
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    
    return 0;
}
```

---

## 5. Atomic Operations

C++ provides **atomic operations** that allow a variable to be modified safely in a multithreaded environment without using locks.

### `std::atomic` Example

```cpp
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);  // Atomic counter

void increment_counter() {
    for (int i = 0; i < 1000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);
    
    t1.join();
    t2.join();
    
    std::cout << "Counter: " << counter.load() << std::endl;  // Print final counter value
    return 0;
}
```

- **`std::atomic<int>`**: A type that ensures that operations on `counter` are atomic (i.e., cannot be interrupted).
- **`counter.load()`**: Safely loads the value of the atomic variable.

---

## 6. Thread Safety and Best Practices

### Data Race Prevention

- Always use a **mutex** or **atomic operations** when accessing shared data across multiple threads.
  
### Deadlock Avoidance

- **Deadlocks** occur when two or more threads are waiting for each other to release resources they need, causing them to be stuck forever. To avoid deadlocks:
  - Always lock mutexes in a consistent order.
  - Use **`std::lock`** to lock multiple mutexes at once.

```cpp
std::mutex mtx1, mtx2;

void thread_func() {
    std::lock(mtx1, mtx2);  // Lock both mutexes at once
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    // Critical section
}
```

### Race Conditions

A **race condition** happens when the outcome depends on the sequence or timing of threads. It’s important to ensure that shared data is properly synchronized.

---

## 7. Advanced Thread Synchronization

### Barriers

A **barrier** is a synchronization point where all threads must wait until all other threads reach it.

```cpp
#include <iostream>
#include <barrier>

std::barrier sync_point(3);  // Barrier for 3 threads

void thread_func(int id) {
    std::cout << "Thread " << id << " reached barrier." << std::endl;
    sync_point.arrive_and_wait();  // All threads will wait here
    std::cout << "Thread " << id << " proceeding after barrier." << std::endl;
}

int main() {
    std::thread t1(thread_func, 1);
    std::thread t2(thread_func, 2);
    std::thread t3(thread_func, 3);

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
```

### Futures and Promises

**Futures** allow you to get the result of an asynchronous operation at some later point.

```cpp
#include <iostream>
#include <future>

int calculate_square(int x) {
    return x * x;
}

int main() {
    std::future<int> result = std::async(calculate_square, 5);
    std::cout << "Square: " << result.get() << std::endl;  // Waits for result
    return 0;
}
```

---

## 8. Examples and Scenarios

### Example 1: Thread Pool

In a thread pool, worker threads process tasks from a shared queue. Tasks are added to the queue and workers fetch them for execution.

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <functional>

class ThreadPool {
public:
    ThreadPool(size_t threads) {
        for (size_t i = 0; i < threads; ++i) {
            workers.push_back(std::thread(&ThreadPool::worker, this));
        }
    }

    ~ThreadPool() {
        for (auto& worker : workers) {
            worker.join();
        }
    }

    void add_task(std::function<void()> task) {
        tasks.push_back(task);
    }

private:
    void worker() {
        while (true) {
            if (!tasks.empty()) {
                auto task = tasks.front();
                tasks.erase(tasks.begin());
                task();
            }
        }
    }

    std::vector<std::thread> workers;
    std::vector<std::function<void()>> tasks;
};
```

---

## 9. Conclusion

C++ concurrency provides a rich set of tools and constructs to write efficient, thread-safe applications. By understanding how threads, mutexes, condition variables, atomic operations, and other constructs work, you can handle the complexities of multithreading and avoid common pitfalls like race conditions, deadlocks, and improper synchronization. This guide covers fundamental concepts and scenarios to help you build safe and efficient multithreaded programs.

Happy coding!
