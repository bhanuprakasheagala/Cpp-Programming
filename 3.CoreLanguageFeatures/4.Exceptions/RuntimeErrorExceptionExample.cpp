#include <iostream>
#include <exception>

double division(double a, double b) {
    if(b == 0) {
        throw std::runtime_error("Division by Zero");
    }

    return a/b;
}

int main()
{
    try {
        double result = division(10, 0);
        std::cout << "Result: " << result << '\n';
    }
    catch(const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << '\n';
    }

    return 0;
}