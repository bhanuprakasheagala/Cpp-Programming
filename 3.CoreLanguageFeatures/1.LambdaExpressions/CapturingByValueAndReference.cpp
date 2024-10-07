#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    auto captureByValue = [x, y]() {
        std::cout << "Captured by value: x = " << x << ", y = " << y << std::endl;
    };

    auto captureByReference = [&x, &y]() {
        std::cout << "Captured by reference: x = " << x << ", y = " << y << std::endl;
    };

    x = 30;
    y = 40;

    captureByValue();       // Output: Captured by value: x = 10, y = 20
    captureByReference();   // Output: Captured by reference: x = 30, y = 40

    return 0;
}