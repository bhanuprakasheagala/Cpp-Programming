#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;

    myMap["apple"] = 10;

    // Safe access
    std::cout << myMap.at("apple") << std::endl; // Output: 10

    // Risky: Creates a new key "banana" with default value 0
    std::cout << myMap["banana"] << std::endl; // Output: 0

    // std::cout << myMap.at("Orange") << std::endl; // Throws std::out_of_range exception

    return 0;
}