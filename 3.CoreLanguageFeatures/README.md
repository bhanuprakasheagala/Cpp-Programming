# 🌟 C++11 Core Language Features

Welcome to the C++11 core language features guide! This document provides an overview of key enhancements introduced in C++11, which significantly improve both the language's expressiveness and performance. We will explore the features in-depth, with explanations, examples, and ASCII diagrams to help you understand the concepts.

## 📖 Table of Contents

1. [Auto Type Deduction](#auto-type-deduction)
2. [Range-based for Loops](#range-based-for-loops)
3. [Smart Pointers](#smart-pointers)
4. [Lambda Expressions](#lambda-expressions)
5. [nullptr](#nullptr)
6. [Static Assertions](#static-assertions)
7. [Uniform Initialization](#uniform-initialization)
8. [Move Semantics](#move-semantics)
9. [Thread Support](#thread-support)

---

## 🌈 Auto Type Deduction

**Syntax:** 
```cpp
auto variableName = value;
```

C++11 introduces the `auto` keyword, allowing the compiler to automatically deduce the type of a variable based on its initializer. This enhances code readability and reduces verbosity, especially when dealing with complex types like iterators or containers.

### Benefits:
- Simplifies code, particularly with complicated types.
- Reduces the risk of type mismatches.
- Improves code maintainability.

### Example:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // Using auto for type deduction
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // Output: 1 2 3 4
    }

    return 0;
}
```

### Diagram:

```
|---------------------| 
| auto variableName = |
|        value;       |
|---------------------|
       ↓
|---------------------|
| Type: <deduced>     |
|---------------------|
```

---

## 🌊 Range-based for Loops

**Syntax:**
```cpp
for (auto &item : collection) {
    // use item
}
```

The range-based `for` loop simplifies iteration over containers. It avoids the need for explicit iterators and reduces boilerplate code in loops. This makes the code cleaner and less error-prone.

### Benefits:
- Cleaner and more readable iteration over collections.
- Eliminates common errors, such as off-by-one mistakes.
- Ideal for simple use cases where the index is not required.

### Example:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // Range-based for loop
    for (auto &item : vec) {
        std::cout << item << " "; // Output: 1 2 3 4
    }

    return 0;
}
```

### Diagram:

```
|-------------------------------|
|  auto &item : collection       |
|-------------------------------|
         ↓
|----------------------------------|
| item -> Value at each element   |
|----------------------------------|
```

---

## 🧠 Smart Pointers

C++11 introduces smart pointers (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`) to manage memory automatically, reducing the likelihood of memory leaks and dangling pointers. These pointers manage the lifetime of dynamically allocated objects and help ensure safer code.

### Types of Smart Pointers:
- **`std::unique_ptr`:** Ensures exclusive ownership of a resource.
- **`std::shared_ptr`:** Allows multiple pointers to share ownership.
- **`std::weak_ptr`:** Allows observation of objects owned by `shared_ptr` without contributing to their reference count.

### Benefits:
- Automatic memory management.
- Prevents common memory management errors (e.g., double deletion).
- Provides better resource management in complex systems.

### Example:

```cpp
#include <iostream>
#include <memory>

int main() {
    // Using unique_ptr to manage memory
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << *ptr << std::endl;  // Output: 10

    // No need to manually delete the pointer
    return 0;
}
```

---

## 🪄 Lambda Expressions

**Syntax:** 
```cpp
[capture](parameters) -> returnType { body }
```

Lambda expressions in C++11 allow you to define anonymous functions directly in your code. They are particularly useful for callbacks, event handling, and as function objects passed to algorithms.

### Benefits:
- Concise syntax for defining function objects.
- Greatly enhances flexibility when working with algorithms or callbacks.
- Lambda functions can capture variables from their surrounding scope.

### Example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // Lambda to print each element
    std::for_each(vec.begin(), vec.end(), [](int n) {
        std::cout << n << " "; // Output: 1 2 3 4
    });

    return 0;
}
```

### Diagram:

```
|--------------------------|
| [capture](parameters) ->  |
| returnType { body }      |
|--------------------------|
          ↓
|--------------------------|
| Anonymous function       |
|--------------------------|
```

---

## 🚫 nullptr

**Syntax:**
```cpp
nullptr
```

`nullptr` is a type-safe null pointer constant introduced in C++11. It replaces the old `NULL` or `0` used for null pointer initialization, preventing ambiguities and enhancing type safety.

### Benefits:
- Improves code clarity by being explicitly typed.
- Helps avoid pointer-related bugs by distinguishing between null pointers and integer literals.

### Example:

```cpp
#include <iostream>

int main() {
    int* ptr = nullptr;

    if (ptr == nullptr) {
        std::cout << "Pointer is null!" << std::endl;  // Output: Pointer is null!
    }

    return 0;
}
```

---

## ⚡ Static Assertions

**Syntax:**
```cpp
static_assert(condition, "error message");
```

Static assertions allow compile-time validation of conditions. They are evaluated during compilation and help catch errors early, before runtime.

### Benefits:
- Allows early error detection.
- Provides better documentation and self-checks within code.

### Example:

```cpp
#include <iostream>

int main() {
    static_assert(sizeof(int) == 4, "Expected 4 bytes for int");
    
    return 0;
}
```

---

## 🌐 Uniform Initialization

**Syntax:**
```cpp
Type varName{value};
```

Uniform initialization uses curly braces `{}` for initializing variables. This syntax is consistent across most object types and helps prevent narrowing conversions that could cause unexpected behavior.

### Benefits:
- Prevents narrowing conversions (e.g., converting `double` to `int`).
- Offers a cleaner, more consistent way to initialize variables.

### Example:

```cpp
#include <iostream>

int main() {
    int i{42};  // Uniform initialization
    double d{3.14};
    
    std::cout << i << " " << d << std::endl; // Output: 42 3.14

    return 0;
}
```

---

## 🏃 Move Semantics

**Syntax:**
```cpp
Type&& variable = std::move(otherVariable);
```

Move semantics enable transferring resources (like dynamically allocated memory) from one object to another without copying. `std::move` marks an object as eligible for moving, optimizing performance by avoiding unnecessary deep copies, particularly with large objects.

### Benefits:
- Significantly improves performance, especially for large objects or data structures.
- Reduces resource overhead.

### Example:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4};
    
    // Move v1 into v2
    std::vector<int> v2 = std::move(v1);
    
    std::cout << "v2 contents: ";
    for (auto val : v2) {
        std::cout << val << " ";  // Output: 1 2 3 4
    }

    return 0;
}
```

---

## 💻 Thread Support

C++11 introduces a thread library to enable concurrent programming in C++. This includes `std::thread` for creating threads, mutexes for synchronization, and other concurrency primitives.

### Benefits:
- Makes it easier to write multi-threaded applications.
- Provides a standard way to handle concurrency, avoiding platform-specific libraries.

### Example:

```cpp
#include <iostream>
#include <thread>

void print_hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // Create a thread that runs the print_hello function
    std::thread t(print_hello);
    
    // Join the thread with the main thread
    t.join();
    
    return 0;
}
```
