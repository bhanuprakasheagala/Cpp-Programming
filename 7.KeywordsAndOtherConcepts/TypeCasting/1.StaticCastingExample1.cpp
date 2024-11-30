#include <iostream>

int main()
{
    int value = 42;
    void* ptr = &value;

    // Use static cast to convert void* to int*
    int* intPtr = static_cast<int*>(ptr);
    std::cout << "Value: " << *intPtr << '\n';

    return 0;
}