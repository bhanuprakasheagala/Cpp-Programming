#include <iostream>
#include <sstream>
#include <string>

int main() {

    // Create a stringstream object
    std::stringstream obj2;
    std::stringstream obj3;

    // Performing write operation

    // 1. Using constructors
    std::string var = "Input string";
    std::stringstream obj1(var);
    std::cout << obj1.str() << '\n'; //`str` can be used to read and write

    // 2. Using the insertion operator
    obj2 << "string stream using insertion operator";
    std::cout << obj2.str() << '\n';

    // 3. Using `str` function
    obj3.str("write data using str function");
    std::cout << obj3.str() <<'\n';

    return 0;
}