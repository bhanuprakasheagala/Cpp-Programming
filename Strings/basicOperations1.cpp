#include <iostream>
#include <string>

int main() {

    std::string str = "learning to code is to improve the skills";
    std::cout << "String: " << str << '\n' << "String capacity: " << str.capacity() << '\n';
    std::cout << "The length of the string: " << str.length() << '\n';
    str.resize(16);
    std::cout << "String after resize: " << str << '\n' << "String capacity: " << str.capacity() << '\n';
    std::cout << "The length of the string: " << str.length() << '\n';

    // Decreasing the capacity of the string
    // using shrink_to_fit()
    str.shrink_to_fit();
    std::cout << "String after shrink to fit: " << str << '\n';
    std::cout << "The new capacity after shrinking is: " << str.capacity() << '\n';

    return 0;
}