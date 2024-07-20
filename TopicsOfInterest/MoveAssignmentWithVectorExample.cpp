#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};

    // Move assignment
    vec1 = std::move(vec2); // vec2's elements are moved to vec1

    // Print after move
    std::cout << "vec1: ";
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "vec2: ";
    for (int num : vec2) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // vec2 is empty after move

    return 0;
}
