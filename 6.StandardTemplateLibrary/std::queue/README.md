# Queue Data Structure in C++ STL

## Table of Contents
1. [Introduction](#introduction)
2. [What is a Queue?](#what-is-a-queue)
3. [Queue in C++ STL](#queue-in-c++-stl)
4. [Basic Operations on Queue](#basic-operations-on-queue)
5. [Important C++ STL Queue Functions](#important-c++-stl-queue-functions)
6. [Advanced Concepts](#advanced-concepts)
7. [Code Examples](#code-examples)
8. [Common Use Cases](#common-use-cases)
9. [Conclusion](#conclusion)

---

## Introduction

The Queue is a linear data structure that follows the **First In First Out (FIFO)** principle. This means that the element added first will be removed first. In C++, the queue is provided by the **`queue`** container adapter in the Standard Template Library (STL). It is built on top of other containers like `deque` or `list` and provides a way to manage a collection of elements in FIFO order.

---

## What is a Queue?

A **Queue** is a data structure where elements are inserted at the **rear** and removed from the **front**. It is often used in scenarios where the order of processing matters, such as in task scheduling, print queues, or implementing breadth-first search (BFS).

### Queue Properties
- **FIFO Order**: The first element inserted will be the first one to be removed.
- **Two Main Operations**:
  - **enqueue** (push): Add an element to the rear.
  - **dequeue** (pop): Remove an element from the front.

---

## Queue in C++ STL

In C++, the **queue** is part of the Standard Template Library (STL). It is a container adapter, which means it provides an abstraction for underlying containers like `deque` or `list`. The queue interface does not expose direct access to elements, only methods for adding and removing.

To use queues in C++, you need to include the `<queue>` header.

```cpp
#include <queue>
```

### Key Features:
- **Type**: `std::queue<T>`
- **Underlying Container**: Typically `std::deque<T>` (can also be `std::list<T>`).
- **Thread-Safe**: Not thread-safe by default. If needed, synchronization mechanisms should be implemented.

---

## Basic Operations on Queue

The `std::queue` provides several functions to perform operations on the queue.

### 1. **`push()`** - Add an element to the queue
This function inserts an element at the rear of the queue.

```cpp
std::queue<int> q;
q.push(10);  // Inserts 10 at the rear
q.push(20);  // Inserts 20 at the rear
```

### 2. **`pop()`** - Remove an element from the queue
This function removes the element from the front of the queue.

```cpp
q.pop();  // Removes the front element (10)
```

### 3. **`front()`** - Access the front element
This function provides access to the element at the front of the queue.

```cpp
int frontElement = q.front();  // Returns the front element (20)
```

### 4. **`back()`** - Access the rear element
This function provides access to the element at the rear of the queue.

```cpp
int backElement = q.back();  // Returns the rear element (20)
```

### 5. **`empty()`** - Check if the queue is empty
Returns `true` if the queue is empty, otherwise returns `false`.

```cpp
bool isEmpty = q.empty();  // Returns false if queue has elements
```

### 6. **`size()`** - Get the number of elements in the queue
Returns the number of elements currently in the queue.

```cpp
int size = q.size();  // Returns 1 after popping one element
```

---

## Important C++ STL Queue Functions

Here’s a breakdown of the most commonly used functions available in the `std::queue` class.

| Function    | Description                                    |
|-------------|------------------------------------------------|
| `push()`    | Adds an element at the back of the queue.      |
| `pop()`     | Removes the element from the front of the queue. |
| `front()`   | Returns the element at the front of the queue. |
| `back()`    | Returns the element at the back of the queue.  |
| `empty()`   | Checks if the queue is empty.                  |
| `size()`    | Returns the number of elements in the queue.   |

### Example:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Pushing elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Displaying front element
    cout << "Front: " << q.front() << endl;  // 10

    // Removing elements from the front
    q.pop();  // Removes 10

    // Displaying size
    cout << "Size after pop: " << q.size() << endl;  // 2

    return 0;
}
```

---

## Advanced Concepts

### 1. **Queue with Custom Containers**

By default, `std::queue` uses `std::deque` as its underlying container. However, you can specify a different underlying container, such as `std::list`, when declaring a queue.

Example:

```cpp
std::queue<int, std::list<int>> q;  // Using std::list as underlying container
```

### 2. **Queue in Multithreading**
In a multithreading environment, queues can be used for managing shared resources between threads. However, `std::queue` is **not thread-safe** by default. You will need to use synchronization techniques (e.g., mutexes) when using queues in multi-threaded applications.

### 3. **Priority Queue**
`std::priority_queue` is another container adapter in C++ STL that behaves similarly to a queue, but with the added feature that it returns the element with the highest priority (instead of FIFO). It is implemented as a heap-based container.

---

## Code Examples

### 1. **Basic Queue Operations**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(5);
    q.push(10);
    q.push(15);

    // Check if queue is empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // Front and back elements
    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;

    // Pop and print elements
    while (!q.empty()) {
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    return 0;
}
```

### 2. **Queue with Custom Container (std::list)**

```cpp
#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main() {
    queue<int, list<int>> q;

    // Push elements
    q.push(100);
    q.push(200);
    q.push(300);

    // Print front and back
    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;

    // Pop elements
    q.pop();
    cout << "After pop, Front: " << q.front() << endl;

    return 0;
}
```

### 3. **Priority Queue Example**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    // Push elements
    pq.push(40);
    pq.push(10);
    pq.push(20);

    // Print highest priority (top element)
    cout << "Top element (Highest Priority): " << pq.top() << endl;

    // Pop elements
    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;

    return 0;
}
```

---

## Common Use Cases

1. **Task Scheduling**: Queues are ideal for managing tasks in the order they arrive.
2. **Breadth-First Search (BFS)**: In graph traversal algorithms, a queue is used to explore nodes in the order they are discovered.
3. **Print Queue**: In print servers, jobs are printed in the order they are received.
4. **Customer Service Systems**: Queues are used to handle customers in the order they arrive.

---

## Conclusion

The `std::queue` in C++ STL is a simple and efficient data structure that follows the **FIFO** principle. It provides several key operations such as `push()`, `pop()`, `front()`, `back()`, `empty()`, and `size()`. For advanced use cases, you can customize the underlying container and implement synchronization in multithreading environments.

By understanding the basic operations and applying the various functionalities, you can leverage `std::queue` for a wide range of practical applications.