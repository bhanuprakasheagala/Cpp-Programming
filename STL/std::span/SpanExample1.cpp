#include <iostream>
#include <span>
#include <vector>

// Function that modifies data through a span
void modifySpan(std::span<int> sp) {
    for(std::size_t i=0; i<sp.size(); ++i) {
        sp[i] *= 2;
    }
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6};
    
    std::cout << "Before modification: ";
    for(int val : v) {
        std::cout << val << " ";
    }
    std::cout << '\n';
    
    // Create a span of a vector
    std::span<int> sp(v);
    
    // Modify the vector through span
    modifySpan(sp);
    
    std::cout << "After modification: ";
    for(int val : v) {
        std::cout << val << " ";
    }
    std::cout << '\n';
    
    return 0;
}