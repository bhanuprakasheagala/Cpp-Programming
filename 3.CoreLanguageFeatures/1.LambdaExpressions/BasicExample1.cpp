//Here's a simple example to illustrate a basic lambda expression:
#include <iostream>

int main() {
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    std::cout << "Sum: " << add(5, 3) << std::endl;  // Output: Sum: 8
    return 0;
}