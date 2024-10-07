#include <iostream>

int main() {

    int x = 20;
    int y = 10;

    // Capture all external variables(external to lambda) by value
    auto printSum = [=]() {
        std::cout << "Sum: " << x+y << '\n';
    }

    printSum(); // Sum : 30

    // Capture all external variables by reference
    auto modifyAndPrint = [&]() {
        x += 5;
        y += 5;
        std::cout << "Modified Sum: " << x+y << '\n';
    }

    modifyAndPrint(); // Sum : 40
    std::cout << "x: " << x << "y: " << y << '\n';

    return 0;
}