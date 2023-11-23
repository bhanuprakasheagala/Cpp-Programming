#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function Object class for comparing strings by length
class StringLengthComparator {
    public:
        bool operator()(const std::string& str1, const std::string& str2) const {
            return str1.length() < str2.length();
        }
};

int main() {

    // Create a vector of strings
    std::vector<std::string> words = {"apple", "banana", "organge", "grape", "guva"};

    // Use the StringLengthComparator function object to sort the vector
    std::sort(words.begin(), words.end(), StringLengthComparator());

    // Print the sorted vector
    std::cout << "Sorted by length: \n";
    for(const auto& word : words)
        std::cout << word << " ";
    std::cout << "\n";

    return 0;
}