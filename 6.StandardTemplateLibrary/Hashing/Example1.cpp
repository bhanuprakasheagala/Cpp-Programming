#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    
    // Receive Input from the user
    std::vector<std::string> words;
    std::string word;
    std::cout << "Enter words (type '-1' to finish): ";
    while (std::cin >> word && word != "-1") {
        words.push_back(word);
    }

    // Create an unordered_map to count the frequency of each word
    std::unordered_map<std::string, int> wordCount;
    for (const auto& w : words) {
        wordCount[w]++;   // If w not present, it will be default-initialized to 0, then incremented to 1.
    }

    // Display the frequency of each word
    std::cout << "\nWord Frequencies:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

// Hash Table structure with each insertion in ASCII diagram
// +----------------+-----------|
// |         Hash Table         |
// +----------------+-----------+
// | Key: "hello"   | Value: 1  |
// +----------------+-----------+
// | Key: "world"   | Value: 1  |
// +----------------+-----------+
// | Key: "hello"   | Value: 2  | <-- Collision occurs, value is incremented
// +----------------+-----------+
// | Key: "example" | Value: 1  |
// +----------------+-----------+ 
// | Key: "hello"   | Value: 3  | <-- Collision occurs, value is updated
// +----------------+-----------+
// | Key: "world"   | Value: 2  | <-- Collision occurs, value is updated
// +----------------+-----------+

// How Unordered Map created in Memory and how it works:
// 1. When a key-value pair is inserted, the key is hashed using a hash function to compute an index in the hash table.
// 2. If the computed index is empty, the key-value pair is stored directly at that index.
// 3. If there is a collision (i.e., another key-value pair is already present at that index), the unordered_map uses chaining (e.g., linked list or another structure) to store multiple key-value pairs at the same index.
// 4. When searching for a key, the hash function is used to compute the index, and then the unordered_map checks the key-value pairs at that index to find the matching key and return its value. If there are multiple pairs due to collisions, it will iterate through them until it finds the correct key.
// 5. The unordered_map automatically resizes the hash table when the load factor (number of elements divided by the size of the table) exceeds a certain threshold, which helps maintain efficient operations.

// How Unordered Map gets created initially in memory:
// 1. When an unordered_map is declared, it allocates an initial hash table with a default size (often a prime number) to minimize collisions.
// 2. The hash table is typically implemented as an array of buckets, where each bucket can store multiple key-value pairs in case of collisions.
// 3. The unordered_map also initializes internal variables to keep track of the number of elements, the size of the hash table, and the load factor threshold for resizing.
// 4. As elements are inserted, the unordered_map manages the hash table dynamically, resizing it when necessary to maintain efficient performance. This involves creating a new hash table with a larger size and rehashing all existing key-value pairs into the new table.

