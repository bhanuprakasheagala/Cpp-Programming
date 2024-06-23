#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iterator>

int main() {
    
    std::string str{"hello"};
    std::vector<int> vec{1, 9, 7, 3};
    std::set<int> t{3, 8, 6, 4, 3};
    
    std::cout << "Before :\nString: " << str << "\nVector: ";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nSet: ";
    std::copy(begin(str), end(str), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    auto f1 = str.find('l');
    if(f1 != std::string::npos) {
        std::cout << "Found at poistion: " << f1 << '\n';
        str.erase(f1, 1);
    }
    
    auto f2 = std::find(begin(vec), end(vec), 7);
    if(f2 != end(vec)) {
        std::cout << "Found in Vector: " << *f2 << '\n';
        vec.erase(f2);
    }
    
    auto f3 = t.find(4);
    if(f3 != end(t)) {
        std::cout << "Found in Set: " << *f3 << '\n';
        t.erase(f3);
    }
    
    std::cout << "After:\nInserting: " << str << "\nVector: ";
    std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nSet: ";
    std::copy(begin(t), end(t), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    return 0;
}
