#include <iostream>
#include <type_traits>

template <typename T1, typename T2>     // (1)
typename std::conditional<(sizeof(T1) > sizeof(T2)), T1, T2>::type max1(T1 lhs, T2 rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

template <typename T1, typename T2>    // (2)
typename std::common_type<T1, T2>::type max2(T1 lhs, T2 rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

template <typename T1, typename T2>  // (3) 
auto max3(T1 lhs, T2 rhs) {
    return (lhs > rhs) ? lhs : rhs;
}

/*
Notes:

The first two versions max1 (line 1) and max2 (line 2) are based on the type-traits library. -> [-std=c++11]
The third version max3 (line 3) uses the automatic type deduction of auto. -> [-std=c++14]

max1 (line 1): typename std::conditional<(sizeof(T1) > sizeof(T2)), T1, T2>::type returns
the type T1, or T2 that is bigger.
std::conditional is a kind of compile-time ternary operator.

max2 (line2): typename td::common_type<T1, T2>::type returns the common type of the types T1 and T2.
std::common_type can accept an arbitrary number of arguments.

T1 and T2 are dependent names. A dependent name is essentially a name that depends on a template parameter.
In this case, we have to give the compiler a hint that T1 and T2 are types.
Essentially, they can also be non-types or templates.
*/

int main()
{
    std::cout << max1(10.5f, 5.5) << '\n';
    std::cout << max2(10.5f, 5.5) << '\n';
    std::cout << max3(10.5f, 5.5) << '\n';
    
    return 0;
}
