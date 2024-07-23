/*
Since C++11, the C++ standard library provides a means to specify choosing “the more general type.” std::common_type<>::type yields
the “common type” of two (or more) different types passed as template arguments. 
*/
#include <iostream>
#include <type_traits>

template<typename T1, typename T2>
std::common_type_t<T1,T2> max(T1 a, T2 b) {   // C++14
    return b < a ? a : b;
}

template<typename T1, typename T2>
typename std::common_type<T1,T2>::type min(T1 a, T2 b) {  // C++11
    return a < b ? a : b;
}

int main()
{
    int a = 7;
    float b = 9.9;
    std::cout << "Max is: " << max(a, b) << '\n';
    std::cout << "Min is: " << min(a, b) << '\n';
    
    return 0;
}

/*
std::common_type is a type trait, defined in <type_traits>, which yields a structure having a type member for the
resulting type. Thus, its core usage is as follows:

typename std::common_type<T1,T2>::type (since C++11)

However, since C++14 you can simplify the usage of traits like this by appending _t to the trait name and skipping typename
and ::type, so that the return type definition simply becomes:

std::common_type_t<T1,T2> (since C++14)

The way std::common_type<> is implemented uses some tricky template programming.
Internally, it chooses the resulting type according to the language rules of operator ?: or specializations for specific types.
Thus, both ::max(4, 7.2) and ::max(7.2, 4) yield the same value 7.2 of type double.
Note that std::common_type<> also decays.

*/