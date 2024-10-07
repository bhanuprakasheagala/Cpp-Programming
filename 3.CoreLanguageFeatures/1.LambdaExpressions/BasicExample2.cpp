#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4};

    // Lambda that prints each element
    auto print = [](int x) {
        std::cout << x << " ";
    };

    // Apply lambda to each element in the vector
    std::for_each(v.begin(), v.end(), print);
    std::cout << '\n';

    // Lambda with captured variables
    int multiplier = 2;
    std::for_each(v.begin(), v.end(), [multiplier](int& x) {
        x *= multiplier;
    });

    std::for_each(v.begin(), v.end(), print);
    std::cout << '\n';
    return 0;
}