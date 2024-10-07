/*
Before C++14, it is only possible to let the compiler determine the return type by more or less making
the implementation of the function part of its declaration. In C++11 we can benefit from the fact that the
trailing return type syntax allows us to use the call parameters. 
That is, we can declare that the return type is derived from what operator?: yields.

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> decltype(b<a?a:b){
    return b<a?a:b;
}

Here, the resulting type is determined by the rules for operator ?:, which are fairly elaborate but
generally produce an intuitively expected result (e.g., if a and b have different arithmetic types,
a common arithmetic type is found for the result).

This definition has a significant drawback: It might happen that the return type is a reference type,
because under some conditions T might be a reference.
For this reason you should return the type decayed from T, which looks as follows:
*/

#include <iostream>
#include <type_traits>

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type {
    return b<a?a:b;
}

/*
Here, the type trait std::decay<> is used, which returns the resulting type in a member type. It is defined by the standard library
in <type_trait>. Because the member type is a type, you have to qualify the expression with typename to access it.
*/

int main() {
    int a = 5, b = 6;
    float p = 7.8, q = 8.9;
    std::cout << max(p, q) << '\n';  // Output: 8.9
    std::cout << max(a, b) << '\n';  // Output: 6

    return 0;
}
