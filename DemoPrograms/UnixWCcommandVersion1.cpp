/*
A simple C++ program that replicates the basic functionality of wc with the -c option to count the number of bytes in a file
*/

#include <iostream>
#include <fstream>
#include <vector>

int main(int argCount, char* argv[]){

    // Check if the correct number of arguments is provided
    if(argCount != 3 || std::string(argv[1]) != "-c") {
        std::cerr<< "Usage: " << argv[0] << " -c <file> " << std::endl;
    }

    // Get the file path from command line arguments
    const std::string file_path = argv[2];

    // Open the file
    std::ifstream file(file_path, std::ios::binary);
    if(!file.is_open()){
        std::cerr << "Error opening file " << file_path << std::endl;
        return 1;
    }

    // Read the file and count the bytes

    /*
    1. `std::istreambuf_iterator<char>(file)`: This part creates an input iterator (std::istreambuf_iterator) for reading characters
    from the file. It's used to iterate over the contents of the file.
    2. std::istreambuf_iterator<char>(): It's used as the ending iterator for the range.
    When used like this, it signifies the end of the stream. This explicitly specifies the type for the ending iterator. 
    3. std::vector<char>: This is the type of the vector that we are creating. In this case, it's a vector of characters.

    The entire line is essentially using the range constructor of std::vector. This constructor takes two iterators representing the
    range to copy. In this case, it uses the iterators created from the file to copy the contents of the file into the vector.

    So, the `buffer` vector is being initialized with the contents of the file, and the type of elements in the vector is `char`.
    After this line, the `buffer` vector contains all the characters from the file, effectively representing the file content.
    */

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const std::size_t byte_count = buffer.size();

    std::cout << byte_count << " bytes " << std::endl;

/*
Notes:
The Most Vexing Parse occurs when a statement could be interpreted as either a variable declaration or a function declaration.

Consider this line:

```cpp
std::vector<char> buffer(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
```

Due to the way C++ syntax is designed, the compiler could interpret this line as either:

1. A variable declaration for a function named `buffer` that takes two parameters (both of which are function pointers).

or

2. The correct intended meaning, which is the declaration of a variable named `buffer` of type `std::vector<char>`.

To disambiguate and ensure that the compiler interprets it as the second option, you can add an extra pair of
parentheses around the first argument:

```cpp
std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
```

This extra set of parentheses clarifies to the compiler that what's inside the parentheses is an expression,
not a function declaration. It helps in resolving the ambiguity and ensures that `buffer` is treated as a variable of
type `std::vector<char>` rather than a function.

In C++, the presence or absence of parentheses can make a significant difference in how a statement is parsed, and
using an extra set of parentheses in such cases is a common technique to disambiguate and avoid the Most Vexing Parse.
*/

return 0;
}