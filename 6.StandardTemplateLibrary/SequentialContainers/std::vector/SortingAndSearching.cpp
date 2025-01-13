#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    //std::cout<<"Hello World";
    std::vector<int> v;
    int target;
    for(;;) {
        std::cout << "Please enter a number (99 to quit): ";
        int i{};
        std::cin >> i;
        if(i == 99)
            break;
        v.push_back(i);
    }
    std::cout << "Enter the target: ";
    std::cin >> target;
    std::cout << "Elements in sorted order: \n";
    std::sort(v.begin(), v.end());
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    auto it = std::lower_bound(v.begin(), v.end(), target);
    if(it != v.end() && *it == target) {
        std::cout << "Found at index: " << std::distance(v.begin(), it) << '\n';
    }
    else {
        std::cout << target << " not found!\n";
    }
    
    return 0;
}
