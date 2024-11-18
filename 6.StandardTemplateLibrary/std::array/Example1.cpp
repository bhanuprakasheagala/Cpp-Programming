#include <iostream>
#include <array>

int main() {
    std::array<int, 3> arr1 = {1, 2, 3};
    std::array<int, 3> arr2 = {4, 5, 6};

    arr1.fill(0); // Fill all elements of arr1 with zeros

    arr1.swap(arr2); // Swap arr1 and arr2

    std::cout << "arr1: ";
    for(int val : arr1)
        std::cout << val << '\n';
    std::cout << "arr2: ";
    for(int val : arr2)
        std::cout << val << '\n';

    return 0;
}