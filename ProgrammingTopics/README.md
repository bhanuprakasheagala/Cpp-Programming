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

## Matrix Class Template

Here's an updated README that covers template metaprogramming concepts and other programming details in more depth:

---

# Matrix Class Template

This repository contains a C++ implementation of a matrix class template that supports various operations such as addition, multiplication, transposition, and determinant calculation. The class is designed using modern C++ features, including templates and exception handling.

## Table of Contents

1. [Introduction](#introduction)
2. [File Structure](#file-structure)
3. [Matrix Class Template Overview](#matrix-class-template-overview)
4. [Functionality](#functionality)
   - [Constructor](#constructor)
   - [Set and Get Elements](#set-and-get-elements)
   - [Print Matrix](#print-matrix)
   - [Addition](#addition)
   - [Multiplication](#multiplication)
   - [Transpose](#transpose)
   - [Determinant](#determinant)
5. [Template Metaprogramming Concepts](#template-metaprogramming-concepts)
6. [Exception Handling](#exception-handling)
7. [Code Flow](#code-flow)
8. [How to Use](#how-to-use)

## Introduction

The Matrix class template allows users to create matrices of arbitrary dimensions (rows and columns) and perform various mathematical operations. The design leverages C++ templates to ensure type safety and performance.

## File Structure

```
/matrix
│
├── matrix.hpp    // Header file containing the Matrix class template declaration
├── matrix.cpp     // Implementation file for the Matrix class template methods
└── main.cpp       // Main program to demonstrate the Matrix class functionality
```

## Matrix Class Template Overview

The `Matrix` class is defined as a template:

```cpp
template <size_t Rows, size_t Cols>
class Matrix {
    // Class members and methods...
};
```

This allows for compile-time determination of the matrix dimensions, leading to optimized memory usage and performance.

## Functionality

### Constructor

The constructor initializes all matrix elements to zero using a loop:

```cpp
Matrix() {
    for(auto& row : data) {
        row.fill(0); // Initialize all elements to 0
    }
}
```

### Set and Get Elements

The `set` and `get` methods allow manipulation of individual matrix elements. They include bounds checking to prevent out-of-range access:

```cpp
void set(size_t row, size_t col, int value);
int get(size_t row, size_t col) const;
```

### Print Matrix

The `print` method outputs the matrix to the console in a formatted manner:

```cpp
void print() const;
```

### Addition

The `add` method computes the element-wise sum of two matrices of the same dimensions:

```cpp
Matrix<Rows, Cols> add(const Matrix<Rows, Cols>& other) const;
```

### Multiplication

The `multiply` method performs matrix multiplication, which requires proper dimension matching:

```cpp
template <size_t OtherCols>
Matrix<Rows, OtherCols> multiply(const Matrix<Cols, OtherCols>& other) const;
```

### Transpose

The `transpose` method creates a new matrix by flipping the rows and columns:

```cpp
Matrix<Cols, Rows> transpose() const;
```

### Determinant

The `determinant` function calculates the determinant of square matrices. It includes specializations for 1x1 and 2x2 matrices, while a general case handles larger matrices using cofactor expansion:

```cpp
long determinant() const; // General declaration
template<> long Matrix<1, 1>::determinant() const; // Specialization for 1x1
template<> long Matrix<2, 2>::determinant() const; // Specialization for 2x2
```

## Template Metaprogramming Concepts

### Compile-Time Size Parameters

The `Matrix` class uses template parameters `Rows` and `Cols` to specify matrix dimensions at compile time. This allows the compiler to allocate the appropriate amount of memory and perform optimizations.

### Specialization

Function template specialization enables us to define different behaviors for specific cases of a template:

```cpp
template<>
long Matrix<1, 1>::determinant() const {
    return data[0][0];
}
```

This specialization avoids unnecessary calculations for 1x1 matrices, making the code more efficient.

### Static Assertions

Static assertions ensure that certain conditions are met at compile time:

```cpp
static_assert(Rows == Cols, "Determinant is only defined for square Matrices.\n");
```

This prevents misuse of the determinant function with non-square matrices and provides a clear error message.

## Exception Handling

The code utilizes `std::out_of_range` exceptions to handle errors gracefully when accessing elements outside the valid range. This improves the robustness of the class:

```cpp
if(row >= Rows || col >= Cols) {
    throw std::out_of_range("Index out of range\n");
}
```

## Code Flow

The `main` function demonstrates the usage of the `Matrix` class by creating instances, performing operations, and printing results. This serves as a simple test suite to verify the class's functionality.

## How to Use

1. Clone the repository:

   ```bash
   git clone <repository-url>
   ```

2. Navigate to the project directory:

   ```bash
   cd matrix
   ```

3. Compile the code:

   ```bash
   g++ main.cpp matrix.cpp -o matrix_program
   ```

4. Run the program:

   ```bash
   ./matrix_program
   ```


---

Feel free to explore the programs, run them, and use them as examples to enhance your understanding of C++ programming. If you have any questions or suggestions, please open an issue or submit a pull request. Happy coding! 🎉

---
