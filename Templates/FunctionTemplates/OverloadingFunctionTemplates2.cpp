#include <iostream>
#include <cstring>
#include <string>

// Maximum of two values of any type
template <typename T>
T max(T a, T b) {
    return b < a ? a : b;
}

// Maximum of two pointers
template <typename T>
T* max(T* a, T* b) {
    return *b < *a ? a : b;
}

// Maximum of two C-strings
char const* max(char const* a, char const* b) {
    return std::strcmp(b, a) < 0 ? a : b;
}

int main()
{
    int a = 7;
    int b = 42;
    auto m1 = ::max(a, b);          // max() for two values of type int
    std::cout << "Max of two values of type int: " << m1 << '\n';

    std::string s1 = "hey";
    std::string s2 = "you";
    auto m2 = ::max(s1, s2);        // max() for two values of type std::string
    std::cout << "Max of two values of type std::string: " << m2 << '\n';

    int* p1 = &b;
    int* p2 = &a;
    auto m3 = ::max(p1, p2);        // max() for two pointers
    std::cout << "Max of two Pointers: " << m3 << '\n';

    char const* x = "hello";
    char const* y = "world";
    auto m4 = ::max(x, y);          // max() for two C-strings
    std::cout << "Max of two C-string types: " << m4 << '\n';

    return 0;
}