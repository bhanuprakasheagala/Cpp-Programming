## DemoPrograms Folder

### Simple Shell using CPP
This simple shell reads user input, splits it into arguments, and then forks a child process to execute the specified command. The execvp function is used to replace the child process's image with the specified command. The parent process waits for the child process to finish using waitpid.

### Abstract Types Demo
An abstract type is a type that completely insulates a user from implementation details. To do that, we decouple the interface from the representation and give up genuine local variables. Since we don’t know anything about the representation of an abstract type (not even its size), we must allocate objects on the free store and access them through references or pointers.

### Count number of Bytes in a file
A simple version of wc that takes the command line option -c and outputs the number of bytes in a file.

About the line:
`std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>())`

1. `std::istreambuf_iterator<char>(file)`: This part creates an input iterator (std::istreambuf_iterator) for reading characters
    from the file. It's used to iterate over the contents of the file.
2. `std::istreambuf_iterator<char>()`: It's used as the ending iterator for the range.
    When used like this, it signifies the end of the stream. This explicitly specifies the type for the ending iterator. 
3. `std::vector<char>`: This is the type of the vector that we are creating. In this case, it's a vector of characters.

The entire line is essentially using the range constructor of std::vector. This constructor takes two iterators representing the
range to copy. In this case, it uses the iterators created from the file to copy the contents of the file into the vector.
So, the `buffer` vector is being initialized with the contents of the file, and the type of elements in the vector is `char`.
After this line, the `buffer` vector contains all the characters from the file, effectively representing the file content.

Check Notes section in cpp file to learn more...

### I/O of User-Defined Types
In addition to the I/O of builtin types and standard `string`s, the `iostream` library allows programmers to define I/O for their own Types.
Here a `struct` type taken as simple example. Outputtuing is straightforward. The corresponding input operator is more complicated.

Note, The `is>>c` skips whitespace by default, but `is.get(c)` does not, so that this `Entry` - input operator ignores(skips) whitespace
outside the name string, but not within it.

### A DeskCalculator Example
This C++ code implements a simple calculator that can handle basic arithmetic expressions, variable assignments, and predefined constants. Here's a step-by-step explanation of how the code works:

#### Token Definition:
The code defines an enumeration Kind to represent different types of tokens. Each token has a kind, and for certain tokens like numbers or names, there are additional fields to store relevant information.
#### Token Struct:
There is a Token struct that holds information about a particular token, including its kind, string value, and number value.
#### Error Handling:
There is a global variable noOfErrors to count the number of errors. The error function increments the error count, prints an error message, and returns a default value (1 in this case).
#### Symbol Table:
The code uses a std::map named table to store variable assignments, associating variable names with their values.
#### Token Stream Class:
The Token_stream class handles the input stream of tokens. It includes functions to get the next token, retrieve the current token, and set the input source. The destructor ensures proper cleanup.
#### Token Stream Implementation:
The implementation of Token_stream includes a get function that extracts the next token from the input stream based on the characters encountered. The switch statement categorizes characters into different token types.
#### Expression Parsing:
The code defines three functions for parsing expressions: expr, term, and prim. These functions collectively implement a recursive descent parser.
expr: Handles addition and subtraction operations.
term: Deals with multiplication and division operations.
prim: Represents the primary elements of an expression, such as numbers, variables, and parenthesized expressions.
calculate Function:
The calculate function repeatedly gets tokens from the stream and evaluates expressions until the end of the input is reached. It prints the result of each expression.
#### Main Function:
The main function sets up the calculator. It checks the command line arguments to determine the input source (either standard input or a string). It initializes the symbol table with constants (pi and e) and calls the calculate function.

#### Usage:
If no command line arguments are provided, the calculator reads expressions from standard input.
If one command line argument is provided, it is treated as a string, and the calculator reads expressions from that string.
If more than one command line argument is provided, an error is reported.

The calculator supports basic arithmetic operations, variable assignments, and predefined constants. After evaluating each expression, the result is printed to the standard output. The program returns the number of errors encountered.

### Simple C++ Vector Implementation

This is a simple implementation of a dynamic array-like container, similar to `std::vector`, in C++. This Vector class provides basic functionality such as adding elements, removing elements, resizing, accessing elements by index, and more.

### Features

- **Dynamic Sizing**: The Vector automatically adjusts its capacity as elements are added or removed.
- **Efficient Memory Management**: Memory is allocated efficiently to minimize overhead.
- **Iterator Support**: It provides iterators for traversing the elements of the Vector.
- **Custom Display Function**: Includes a custom display function (`myDisplay()`) for printing the elements of the Vector.

### Usage

To use the Vector class, simply include the provided header file and instantiate a Vector object with the desired data type. Then, you can utilize its methods to manipulate and access elements as needed.

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
