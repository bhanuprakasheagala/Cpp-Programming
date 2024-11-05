#include <iostream>
#include <vector>

class MyClass {
private:
    std::vector<int> numbers;
public:
    // Constructor with a lambda to initialize the vector
    MyClass(int size, int init_value) 
    : numbers(
        [size, init_value]() -> std::vector<int> {
            std::vector<int> temp(size, init_value);
            for(int i=0; i<size; ++i) {
                temp[i] += i;
            }
            return temp;
        }
        () // Immediately Call the lambda, here there is no name and no parameters. And we don't mention return type
    )
    {}


    // Function to print the vector
    void print() const {
        for(int num : numbers) {
            std::cout << num << '\n';
        }
        std::cout << '\n';
    }
};

int main()
{
    MyClass obj(5, 10);
    obj.print();

    return 0;
}

/*
Notes:

In this code, the class `MyClass` demonstrates how to use a C++ lambda expression to initialize a `std::vector<int>` member inside the constructor.
The constructor of `MyClass` takes two parameters: `size` and `init_value`. Instead of initializing the `numbers` vector directly,
it uses a lambda function to generate and modify the vector. The lambda captures the constructor arguments `size` and `init_value` by value, 
creates a `std::vector<int>` of the specified size initialized with `init_value`, and then modifies each element of the vector by adding the index to the value. 
The lambda returns the modified vector, which is used to initialize the `numbers` member of the class.

The key part of this code is the immediate invocation of the lambda. The syntax `()()` after the lambda expression calls the lambda immediately,
executing its body and returning the resulting vector. This is a common technique in C++ when you want to perform complex initialization logic
directly in the constructor's initializer list. The `print()` method is provided to display the contents of the vector, which, 
when called on an object of `MyClass` initialized with size 5 and an initial value of 10, prints the vector elements: `10 11 12 13 14`. 
*/