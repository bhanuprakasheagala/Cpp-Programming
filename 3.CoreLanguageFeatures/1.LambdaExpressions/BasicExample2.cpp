#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4};

    // Lambda that prints each element
    auto print = [](int x) {
        std::cout << x << " ";
    };

    // Apply lambda to each element in the vector
    std::for_each(v.begin(), v.end(), print);
    std::cout << '\n';

    // Lambda that captures by value
    int multiplier = 2;
    std::for_each(v.begin(), v.end(), [multiplier](int& x) {
        x *= multiplier; // Capture by value
    });

    std::for_each(v.begin(), v.end(), print);
    std::cout << '\n';

    // Lambda that captures by reference
    int sum = 5;
    std::for_each(v.begin(), v.end(), [&sum](int x) {
        sum += x; // Capture by reference
    });
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

/*
Notes on How lambdas Work internally in C++:
Lambdas in C++ are implemented as unnamed function objects (functors). When a lambda expression is defined, the compiler generates a unique class type for it. This class contains an overloaded operator() that implements the body of the lambda. 
The capture list in the lambda expression determines how variables from the surrounding scope are stored in the generated class. Variables captured by value are stored as member variables of the class, while those captured by reference are stored as references. 

When the lambda is invoked, the operator() function is called, allowing access to the captured variables as if they were local to the lambda. This mechanism allows lambdas to maintain state and interact with their surrounding context effectively.
In the provided example, we demonstrate three different lambdas:
1. A lambda that prints each element of a vector.
2. A lambda that captures a variable by value to multiply each element in the vector.
3. A lambda that captures a variable by reference to accumulate a sum of the elements in the vector.
This showcases the flexibility and power of lambda expressions in C++ for creating concise and context-aware functions.

*/