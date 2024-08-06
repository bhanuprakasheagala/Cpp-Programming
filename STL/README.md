`std::span` is a utility class introduced in C++20 that provides a non-owning view of a contiguous sequence of elements. It is particularly useful for functions that need to work with arrays or other contiguous containers but do not need to own the data. Here's a detailed explanation of `std::span`, including its purpose, usage, and examples.

### Overview of `std::span`

**Purpose:**
- `std::span` allows you to create a lightweight, non-owning view of a sequence of elements. It provides a way to access a contiguous block of memory without copying or owning the underlying data.
- It is useful for passing arrays or portions of containers to functions in a type-safe manner.

**Key Features:**
- **Non-owning**: `std::span` does not manage the lifetime of the data it views.
- **Contiguous memory**: It works with arrays or contiguous containers like `std::vector` and `std::array`.
- **Bounds checking**: It provides access to the size and individual elements of the span.
- **Const-correctness**: You can have `std::span` for both constant and non-constant data.

### Syntax and Members

```cpp
#include <span>
#include <vector>
#include <array>
#include <iostream>

template <typename T>
class std::span {
public:
    // Constructors
    constexpr span() noexcept;
    constexpr span(T* ptr, std::size_t count) noexcept;
    constexpr span(T* first, T* last) noexcept;
    constexpr span(std::vector<T>& vec) noexcept;
    constexpr span(const std::vector<T>& vec) noexcept;
    // Accessors
    constexpr T* data() const noexcept;
    constexpr std::size_t size() const noexcept;
    constexpr T& operator[](std::size_t index) const;
    // Other methods
    // ...
};
```

### Examples of Usage

#### 1. Basic Usage

```cpp
#include <iostream>
#include <span>
#include <vector>

void printSpan(std::span<int> sp) {
    for (int val : sp) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::span<int> sp(vec); // Create a span from a vector

    printSpan(sp);

    // Create a span from a portion of the vector
    std::span<int> subspan = sp.subspan(1, 3); // From index 1, take 3 elements
    printSpan(subspan);

    return 0;
}
```

**Explanation**:
- `std::span<int> sp(vec)` creates a span that views the entire `vec`.
- `sp.subspan(1, 3)` creates a new span that views a portion of `sp`, starting from index 1 and including 3 elements.

#### 2. Using `std::span` with Arrays

```cpp
#include <iostream>
#include <span>

void printSpan(std::span<int> sp) {
    for (int val : sp) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    std::span<int> sp(arr);

    printSpan(sp);

    // Creating a span from a part of the array
    std::span<int> subspan(arr + 2, 3); // From index 2, take 3 elements
    printSpan(subspan);

    return 0;
}
```

**Explanation**:
- `std::span<int> sp(arr)` creates a span for the entire array `arr`.
- `std::span<int> subspan(arr + 2, 3)` creates a span that views elements starting from index 2 and covering the next 3 elements.

#### 3. `std::span` with Different Containers

```cpp
#include <iostream>
#include <span>
#include <vector>
#include <array>

void printSpan(std::span<int> sp) {
    for (int val : sp) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::array<int, 5> arr = {6, 7, 8, 9, 10};

    std::span<int> spanFromVector(vec);
    std::span<int> spanFromArray(arr);

    printSpan(spanFromVector);
    printSpan(spanFromArray);

    return 0;
}
```

**Explanation**:
- `std::span<int> spanFromVector(vec)` creates a span for the vector `vec`.
- `std::span<int> spanFromArray(arr)` creates a span for the array `arr`.

### Use Cases

1. **Function Arguments**:
   - Use `std::span` to accept arrays, vectors, or other contiguous containers without copying the data.

2. **Sub-ranges**:
   - Create sub-ranges or views of existing data without copying, using `std::span::subspan`.

3. **Const Correctness**:
   - Use `std::span<const T>` to provide read-only access to data.

4. **Interoperability**:
   - Interoperate between functions that require different types of containers by accepting `std::span`.

### Advantages of `std::span`

1. **Efficiency**:
   - `std::span` does not own the data, so it avoids copying and manages no additional resources.

2. **Flexibility**:
   - It works with arrays, vectors, and other contiguous containers, providing a unified interface for handling these data structures.

3. **Safety**:
   - It provides bounds-checking access methods and avoids many common pitfalls associated with raw pointers.

### Summary

`std::span` is a powerful feature of C++20 that simplifies handling contiguous sequences of data by providing a view into them without ownership. It is ideal for functions that operate on parts of arrays or containers, offering a safe and efficient way to manage and access sequences of data.