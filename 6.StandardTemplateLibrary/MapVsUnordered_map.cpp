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
