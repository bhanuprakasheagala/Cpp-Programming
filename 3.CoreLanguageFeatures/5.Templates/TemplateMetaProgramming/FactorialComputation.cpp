#include <iostream>

template <int N>
struct Factorial2 {
    using value_type = int;
    static constexpr int value = N * Factorial2<N-1>::value;
    static int get_value() {
        return value;
    }

    struct Inner {
        static constexpr int value = N * Factorial2<N-1>::value;
    };

};

template<>
struct Factorial2<0> {
    static constexpr int value = 1; // Base case : 0! = 1
};

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
    Factorial2<4>::value_type x = 10;
    std::cout << "Factorial2<4>::value_type x = " << x << '\n'; // x is valid and initialized
    std::cout << "Factorial of 4: " << Factorial2<4>::value << '\n';
    int val = Factorial2<6>::get_value();
    std::cout << "Computed 6! by calling get_val in Factorial2: " << val << '\n';
    
    int innerFact = Factorial2<3>::Inner::value;
    std::cout << "Getting 3! using Inner Fact computation inside Factorial2: " << innerFact << '\n';
    
    return 0;
}

/*
Notes :-

Recursive Templates: The template Factorial<N> computes the factorial recursively by multiplying N with Factorial<N-1>::value.
Base Case Specialization: The specialization Factorial<0> provides the base case where 0! = 1.
The value of Factorial<5>::value is calculated at compile-time, and the result is available at runtime.

*/