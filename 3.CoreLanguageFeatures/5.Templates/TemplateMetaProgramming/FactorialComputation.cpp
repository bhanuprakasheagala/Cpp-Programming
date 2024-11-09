#include <iostream>

//TMP for calculating factorial
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N-1>::value; //Recursive template instantiation
};

// Specialization for the base case
template<>
struct Factorial<0> {
    static constexpr int value = 1; // Base case : 0! = 1
};

int main()
{
    std::cout << "Factorial of 5: " << Factorial<5>::value << '\n'; // 5! value computed at Compile time

    return 0;
}

/*
Notes :-

Recursive Templates: The template Factorial<N> computes the factorial recursively by multiplying N with Factorial<N-1>::value.
Base Case Specialization: The specialization Factorial<0> provides the base case where 0! = 1.
The value of Factorial<5>::value is calculated at compile-time, and the result is available at runtime.

*/