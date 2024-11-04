#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <vector>

// Function to demangle type names
std::string demangle(const char* name) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(name, nullptr, nullptr, &status);
    std::string result(demangled ? demangled : name);
    free(demangled);

    return result;
}

class Base {};

int main()
{
    auto x = 10;         // x is of type int
    auto y = 3.14;      // y is of type double
    auto str = "Hello"; // str is of type const char*
    auto sp = std::make_shared<Base>();
    auto up = std::make_unique<Base>();
    auto classType1 = Base();
    auto classType2 = new Base();

    std::cout << demangle(typeid(x).name()) << '\n' 
              << demangle(typeid(y).name()) << '\n' 
              << demangle(typeid(str).name()) << '\n'
              << demangle(typeid(classType1).name()) << '\n' 
              << demangle(typeid(classType2).name()) << '\n' 
              << demangle(typeid(sp).name()) << '\n'
              << demangle(typeid(up).name()) << '\n';

    std::vector<int> vec(0);
    const auto a = 10;        // a is a const int
    auto& b = a;              // b is a reference to const int
    const auto& c = vec[0];   // c is a const reference to an int

    std::cout << demangle(typeid(vec).name()) << '\n' 
              << demangle(typeid(a).name()) << '\n'
              << demangle(typeid(b).name()) << '\n' 
              << demangle(typeid(c).name()) << '\n';

    auto list = {1, 2, 3}; // list is of type std::initializer_list<int>
    auto lambda = [](int a, int b) { return a + b; };
    std::cout << demangle(typeid(list).name()) << '\n' 
              << demangle(typeid(lambda(3, 4)).name()) << '\n';
    return 0;
}

/*
Notes:

This C++ code demonstrates the use of the `abi::__cxa_demangle` function to convert mangled type names into human-readable
formats. Name mangling occurs in C++ to encode additional type information, which is essential for the compiler to distinguish between different types,
especially in the context of templates and overloaded functions. The `demangle` function takes a mangled type name as input, calls `abi::__cxa_demangle`
to obtain the demangled version, and returns it as a `std::string`. 
This process allows developers to gain insights into the actual types used in their code, particularly when utilizing features like `typeid` for type introspection.

In the `main` function, various variables are declared with type inference using `auto`, and their types are printed using the `demangle` function.
This not only highlights the deduced types but also showcases the practicality of demangling in understanding complex C++ type information during debugging and development.
Overall, the code exemplifies how demangling enhances clarity and aids in interpreting the underlying type structures in a C++ program.

Output:

g++ --std=c++14 AutoKeywordExample2.cpp
./a.out

int
double
char const*
Base
Base*
std::__1::shared_ptr<Base>
std::__1::unique_ptr<Base, std::__1::default_delete<Base>>
std::__1::vector<int, std::__1::allocator<int>>
int
int
int
std::initializer_list<int>
int
*/