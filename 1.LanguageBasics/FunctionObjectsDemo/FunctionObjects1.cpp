// A function object, also known as a functor, is an object that can be called as if it were a function.
// It is often implemented by overloading the `operator()` in a class.

#include <iostream>

// Function object class
class Adder {
    public:
        int operator()(int a, int b) const {
            return a+b;
        }
};

int main() {
    Adder adder;  // Create an instance of the function object class

    // Use it like a function
    int result = adder(3,4);

    std::cout << "Result: " << result << std::endl;
    return 0;
}