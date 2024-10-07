#include <iostream>

// Maximum of two int values
int max(int a, int b) {
    std::cout << "Non-Templates for Two ints: ";
    return b < a ? a : b;
}

// Maximum of two values of any type
template<typename T>
T max(T a, T b) {
    std::cout << "Templates for other types: ";
    return b < a ? a : b;
}

int main()
{
    std::cout << ::max(7, 20) << '\n';
    std::cout << ::max(7.0, 42.0) << '\n';
    std::cout << ::max('a', 'b') << '\n';
    std::cout << ::max<>(7, 42) << '\n';
    std::cout << ::max<double>(7, 42) << '\n';
    std::cout << ::max('a', 42.7) << '\n';  // This is not a Template, normal function call

    return 0;
}