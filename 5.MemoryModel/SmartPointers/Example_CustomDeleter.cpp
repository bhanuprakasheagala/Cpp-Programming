#include <iostream>
#include <memory>

int main()
{
    auto customDeleter = [](int* ptr) {
        std::cout << "Custom deleter called for pointer: " << ptr << '\n';
        delete ptr;
    };

    std::unique_ptr<int, decltype(customDeleter)> ptr(new int(42), customDeleter);

    return 0;
}