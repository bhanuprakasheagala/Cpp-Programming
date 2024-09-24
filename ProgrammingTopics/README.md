# 📚 Programming Concepts and Applications in C++

Welcome to the **Programming Concepts** repository! This repository includes various Applications showcasing different aspects of C++ programming. Below is a detailed description of each program included in this repository.

## Table of Contents

1. [🖥️ Simple Shell using CPP](#simple-shell-using-cpp)
2. [📦 Abstract Types Demo](#abstract-types-demo)
3. [📂 Count Number of Bytes in a File](#count-number-of-bytes-in-a-file)
4. [🔄 I/O of User-Defined Types](#io-of-user-defined-types)
5. [🧮 A DeskCalculator Example](#a-deskcalculator-example)
6. [📊 Simple C++ Vector Implementation](#simple-c-vector-implementation)
7. [🛠️ Custom Memory Tracker and Viewer](#custom-memory-tracker-and-viewer)
8. [🛠️ Custom Memory Allocator](#custom-memory-allocator)

---

## 🖥️ Simple Shell using CPP

This simple shell reads user input, splits it into arguments, and then forks a child process to execute the specified command. The `execvp` function is used to replace the child process's image with the specified command. The parent process waits for the child process to finish using `waitpid`.

## 📦 Abstract Types Demo

An abstract type is a type that completely insulates a user from implementation details. To achieve this, we decouple the interface from the representation and avoid using genuine local variables. Since the representation of an abstract type is unknown (including its size), objects must be allocated on the free store and accessed through references or pointers.

## 📂 Count Number of Bytes in a File

A simple version of `wc` that takes the command-line option `-c` and outputs the number of bytes in a file.

### About the Line

```cpp
std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>())
```

1. **`std::istreambuf_iterator<char>(file)`**: Creates an input iterator for reading characters from the file.
2. **`std::istreambuf_iterator<char>()`**: Represents the end of the stream.
3. **`std::vector<char>`**: A vector of characters.

The line uses the range constructor of `std::vector` to copy the contents of the file into the vector, resulting in `buffer` containing all characters from the file.

_Check the Notes section in the cpp file to learn more._

## 🔄 I/O of User-Defined Types

In addition to the I/O of built-in types and standard `string`s, the `iostream` library allows defining I/O for user-defined types. Here, a `struct` type is used as a simple example. Outputting is straightforward, while input is more complex. Note that `is>>c` skips whitespace by default, but `is.get(c)` does not. Therefore, the input operator ignores whitespace outside the name string but not within it.

## 🧮 A DeskCalculator Example

This C++ code implements a simple calculator handling basic arithmetic expressions, variable assignments, and predefined constants.

### Key Components

- **Token Definition**: Defines an enumeration `Kind` for different token types.
- **Token Struct**: Holds information about a token, including its kind, string value, and number value.
- **Error Handling**: Uses a global variable `noOfErrors` to count errors, print messages, and return a default value.
- **Symbol Table**: Utilizes `std::map` named `table` for variable assignments.
- **Token Stream Class**: Manages the input stream of tokens.
- **Token Stream Implementation**: Extracts tokens from the input stream.
- **Expression Parsing**: Implements a recursive descent parser with functions `expr`, `term`, and `prim`.
- **Calculate Function**: Evaluates expressions and prints results.
- **Main Function**: Sets up the calculator, processes command-line arguments, initializes constants, and calls `calculate`.

### Usage

- **No command line arguments**: Reads expressions from standard input.
- **One command line argument**: Reads expressions from the provided string.
- **More than one argument**: Reports an error.

Supports basic arithmetic operations, variable assignments, and predefined constants. Results are printed to standard output, and the program returns the number of errors encountered.

## 📊 Simple C++ Vector Implementation

This is a simple implementation of a dynamic array-like container similar to `std::vector` in C++. It provides basic functionalities such as adding, removing, resizing, and accessing elements.

### Features

- **Dynamic Sizing**: Automatically adjusts capacity as elements are added or removed.
- **Efficient Memory Management**: Allocates memory efficiently.
- **Iterator Support**: Provides iterators for element traversal.
- **Custom Display Function**: Includes `myDisplay()` for printing elements.

### Usage

Include the header file and instantiate a `Vector` object with the desired data type. Use its methods to manipulate and access elements.

### Example

```cpp
#include <iostream>
#include "Vector.h" // Include the Vector header file

int main() {
    // Create a Vector of integers
    Vector<int> myVector;

    // Add elements to the Vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Display the elements of the Vector
    myVector.myDisplay();

    // Access the first and last elements
    std::cout << "First element: " << *(myVector.begin()) << '\n';
    std::cout << "Last element: " << *(myVector.end() - 1) << '\n';

    // Remove the last element
    myVector.pop_back();

    // Check if the Vector is empty
    if (myVector.empty()) {
        std::cout << "Vector is empty\n";
    } else {
        std::cout << "Vector is not empty\n";
    }

    return 0;
}
```

## 🛠️ Custom Memory Tracker and Viewer

This C++ program demonstrates custom memory management by overloading `new` and `delete` operators to track memory allocations and deallocations. It also includes functionality to display and inspect raw memory contents.

### Overview

The program tracks memory allocations and deallocations, providing insights into memory usage through custom operator overloading. It also includes a utility for displaying memory buffer contents.

### Key Components

- **Global Variables**:
  - **`uint16_t new_counter`**: Tracks `new` allocations.
  - **`uint16_t delete_counter`**: Tracks `delete` operations.
  - **`size_t allocated_memory`**: Tracks total allocated memory.
- **Functions**:
  - **`resetCounter()`**: Resets counters and prints a message.
  - **`displaySummary()`**: Prints current values of counters.
  - **`showMemory(unsigned char* buffer, std::size_t buffer_size, const char* headline)`**: Displays memory buffer contents in hexadecimal and ASCII formats.
- **Operator Overloading**:
  - **`void* operator new(std::size_t sz)`**: Custom `new` operator using `malloc`.
  - **`void operator delete(void* ptr) noexcept`**: Custom `delete` operator using `free`.

### Core Logic Explanation

1. **Initialization and Summary Display**: Displays initial memory statistics.
2. **Explicit Memory Management**: Demonstrates allocation and deallocation with updated statistics.
3. **STL Container Usage**: Shows implicit memory management with `std::vector<int>`.
4. **Memory Dump Demonstration**: Uses `showMemory` to inspect buffer contents.

### Usage

- **Memory Management Tracking**: Provides insights into memory allocation and deallocation.
- **Raw Memory Inspection**: Use `showMemory` to inspect and analyze memory buffer contents.

-------

## Custom Memory Allocator

This C++ program is a simple custom memory allocator using a fixed-size memory pool. Below, we'll go through how the code works step-by-step and explain the key concepts, such as memory pools, free lists, and casting techniques like `reinterpret_cast`.

### Overview

Memory management in C++ is typically handled by `new` and `delete`. However, for performance-critical applications, especially those that allocate and deallocate memory frequently (e.g., embedded systems), creating a custom memory allocator can help minimize overhead and fragmentation.

#### Design Goals
1. **Memory Pool**: We pre-allocate a large chunk of memory upfront, referred to as the "memory pool."
2. **Fixed-Size Blocks**: The memory pool is divided into small, fixed-size blocks, each 32 bytes in this case.
3. **Free List**: A linked list (known as the "free list") keeps track of free blocks that are available for allocation.
4. **Efficient Allocation and Deallocation**: Blocks are quickly allocated by popping them off the free list, and deallocated by adding them back to the free list.

### Code Walkthrough

#### Constructor: `MemoryAllocator(std::size_t size)`
The constructor is responsible for creating the memory pool and initializing the free list.

#### Memory Pool Allocation
```cpp
memoryPool = ::operator new(poolSize);
```
Here, the `::operator new` allocates raw memory (in this case, a chunk of size `poolSize`). This is different from the usual `new` operator, as it doesn’t invoke constructors—it's essentially allocating a block of bytes, without initializing any objects.

- **Why use `::operator new`?**  
  This low-level memory allocation is used to provide raw memory without initializing objects. We just need the raw memory for the memory pool, not to create actual objects, so we avoid unnecessary constructor overhead.

#### Free List Initialization
Once the memory pool is allocated, it’s divided into blocks and linked together to form a free list.

```cpp
void initializeFreeList() {
    char* currentBlock = static_cast<char*>(memoryPool);
    for (std::size_t i = 0; i < (poolSize / blocksize) - 1; ++i) {
        *reinterpret_cast<void**>(currentBlock) = currentBlock + blocksize;
        currentBlock += blocksize;
    }
    *reinterpret_cast<void**>(currentBlock) = nullptr;
    freeList = memoryPool;
}
```

- **Memory Pool Structure**:  
  The `initializeFreeList()` function divides the memory pool into 32-byte blocks. This is done by treating each block as a node in a singly linked list.

- **`reinterpret_cast<void**>(currentBlock)`**:  
  This line casts the `currentBlock` to a `void**` pointer, which allows us to store the address of the next block inside each block of memory. This is how we create the linked list structure.

    - **How does `reinterpret_cast` work?**  
      `reinterpret_cast` is a type of cast that allows you to treat one type of pointer as another. Here, it converts a `char*` (a pointer to a byte) into a `void**` (a pointer to a pointer). This allows us to manipulate the raw memory and create a linked list by storing the address of the next block in each block. Essentially, the memory block itself holds a pointer to the next free block.

- **Linked List Setup**:  
  After casting each block to `void**`, we assign the address of the next block (`currentBlock + blocksize`). The loop continues this way until all blocks are linked, and the last block points to `nullptr`, indicating the end of the list. Finally, the `freeList` pointer is set to the start of the memory pool, making the first block the head of the free list.

---

#### Allocation: `void* allocate()`
The `allocate()` function returns a block of memory from the free list.

```cpp
void* allocate() {
    if (freeList == nullptr) {
        throw std::bad_alloc();
    }
    void* allocateBlock = freeList;
    freeList = *reinterpret_cast<void**>(freeList);
    return allocateBlock;
}
```

- **Free List Check**:  
  If `freeList == nullptr`, it means there are no more free blocks, so we throw a `std::bad_alloc` exception. This ensures that if the allocator runs out of memory, the program can handle it properly.

- **Allocation Process**:  
  If there are free blocks, we assign `freeList` to `allocateBlock` (this gives us the block to allocate). Next, we update the `freeList` to point to the next free block using the expression `*reinterpret_cast<void**>(freeList)`. This advances the free list to the next available block.

  - **What’s happening here?**  
    `reinterpret_cast<void**>(freeList)` is used again to treat the memory block as a pointer to the next free block. Essentially, we’re moving the head of the free list to the next block, making it the new free block for future allocations.

---

#### Deallocation: `void deallocate(void* block)`
The `deallocate()` function returns a block of memory back to the free list.

```cpp
void deallocate(void* block) {
    *reinterpret_cast<void**>(block) = freeList;
    freeList = block;
}
```

- **Deallocate Process**:  
  When a block is deallocated, we place it back into the free list. This is done by making the deallocated block point to the current head of the free list (`freeList`), and then updating `freeList` to point to this block.

  - **What’s happening with the `reinterpret_cast`?**  
    `reinterpret_cast<void**>(block)` allows us to treat the deallocated block as a pointer, storing the current `freeList` inside it. By doing this, we add the block to the front of the list. This ensures that the most recently deallocated block is available for future allocations.

- **Free List as a Stack**:  
  The free list behaves like a stack in this case. When a block is deallocated, it is placed on top of the stack (i.e., added at the front of the list). When a new block is allocated, it is removed from the top of the stack.

#### Destructor: `~MemoryAllocator()`
```cpp
~MemoryAllocator() {
    ::operator delete(memoryPool);
}
```
The destructor ensures that the memory allocated for the memory pool is properly freed when the `MemoryAllocator` object goes out of scope.

- **Raw Memory Deallocation**:  
  The `::operator delete` function is used to deallocate the memory that was allocated with `::operator new`. This ensures that the memory pool is properly cleaned up when the allocator is no longer needed.

### Internal Mechanisms

1. **Memory Pool**:  
   The memory pool is a large, contiguous block of raw memory that is allocated during the initialization of the `MemoryAllocator` object. This pool is divided into smaller, fixed-size blocks (32 bytes each), and these blocks are managed using a linked list.

2. **Free List**:  
   The free list is a linked list where each node represents a block of memory. The free list is initially created by dividing the memory pool into blocks and linking them together. Blocks are allocated by removing them from the head of the list, and deallocated by adding them back to the front of the list.

3. **`reinterpret_cast`**:  
   This cast is critical for manipulating raw memory as pointers. It allows the allocator to treat blocks of memory as pointers to other blocks, enabling the linked list structure. By casting memory blocks to `void**`, the code can store the addresses of subsequent blocks within the memory pool itself.

## Conclusion

This custom memory allocator provides a simple but efficient way to manage memory using fixed-size blocks and a free list. The use of `reinterpret_cast` allows for the manipulation of raw memory, and the free list ensures that memory is allocated and deallocated quickly. This approach reduces the overhead associated with frequent dynamic memory allocations and is especially useful in systems with constrained resources or performance requirements.

---

Feel free to explore the programs, run them, and use them as examples to enhance your understanding of C++ programming. If you have any questions or suggestions, please open an issue or submit a pull request. Happy coding! 🎉

---
