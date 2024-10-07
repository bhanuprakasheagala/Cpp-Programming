#include <iostream>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n*n << " ";
    });

    std::cout << '\n'; // Output: 1 4 9 16 25

    return 0;
}