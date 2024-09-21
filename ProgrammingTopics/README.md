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

---

Feel free to explore the programs, run them, and use them as examples to enhance your understanding of C++ programming. If you have any questions or suggestions, please open an issue or submit a pull request. Happy coding! 🎉

---
