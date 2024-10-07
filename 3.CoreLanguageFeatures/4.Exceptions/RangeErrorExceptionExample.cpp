#include <iostream>
#include <stdexcept>
#include <vector>

int getElement(const std::vector<int>& vec, size_t index) {
    if (index >= vec.size()) {
        throw std::out_of_range("Index out of range");
    }
    return vec[index];
}

int main() {
    std::vector<int> vec = {1, 2, 3};
    try {
        int element = getElement(vec, 5);
        std::cout << "Element: " << element << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }
    return 0;
}
