/*
In C++, `map` and `unordered_map` are both associative containers used to store key-value pairs, but they differ in their underlying implementations and performance characteristics.
A `map` is implemented using a balanced binary search tree (typically a Red-Black Tree), which ensures that elements are stored in **sorted order**.
As a result, operations like insertion, search, and deletion have a time complexity of O(log n).

On the other hand, `unordered_map` uses a **hash table**, meaning it does not maintain any order of elements.
It offers **faster average time complexity** (O(1)) for insertion, search, and deletion, but performance can degrade to
O(n) in the worst case due to hash collisions. 

Use `map` when you need elements to be ordered or require range queries, and choose `unordered_map` when you prioritize
faster lookups and don't need the elements to be ordered.
*/

#include <iostream>
#include <map>
#include <unordered_map>

int main() {
    // Using map (sorted order)
    std::map<int, std::string> ordered_map;
    ordered_map[1] = "One";
    ordered_map[3] = "Three";
    ordered_map[2] = "Two";
    
    std::cout << "Map (ordered):" << std::endl;
    for (const auto& pair : ordered_map) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    // Using unordered_map (no specific order)
    std::unordered_map<int, std::string> unordered_map;
    unordered_map[1] = "One";
    unordered_map[3] = "Three";
    unordered_map[2] = "Two";
    
    std::cout << "\nUnordered Map (no specific order):" << std::endl;
    for (const auto& pair : unordered_map) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }
    
    return 0;
}

/*
Map (ordered):
1 => One
2 => Two
3 => Three

Unordered Map (no specific order):
2 => Two
3 => Three
1 => One
*/


// How Unordered Map different from Map in different aspects:
// 1. **Underlying Data Structure**: `map` is implemented as a balanced binary search tree (e.g., Red-Black Tree), while `unordered_map` is implemented as a hash table.
// 2. **Order of Elements**: `map` maintains elements in sorted order based on the keys, while `unordered_map` does not maintain any specific order of elements.
// 3. **Time Complexity**: `map` has O(log n) time complexity for insertion, search, and deletion due to its tree structure, while `unordered_map` has O(1) average time complexity for these operations due to its hash table implementation, but can degrade to O(n) in the worst case due to collisions.
// 4. **Memory Usage**: `unordered_map` may use more memory than `map` due to the need for a hash table and handling collisions, while `map` uses a more compact tree structure.
// 5. **Use Cases**: `map` is suitable when you need ordered data or require range queries, while `unordered_map` is ideal when you prioritize faster lookups and do not need the elements to be ordered.