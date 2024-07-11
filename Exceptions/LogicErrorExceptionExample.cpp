#include <iostream>
#include <stdexcept>

void checkAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("Age cannot be negative");
    }
}

int main() {
    try {
        checkAge(-5);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    return 0;
}
