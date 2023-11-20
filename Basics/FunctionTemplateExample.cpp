#include <array>
#include <iostream>

template<typename T>
void print_array(T array) {
    for(auto value : array) {
        std::cout << value << ' ';
    }
    std::cout<<std::endl;
}

/* C++20:
In c++20 auto keyword can be used instead of template. g++ --std=c++20 <filename.cpp>
The above code from line4 to line10 can be written:
void print_array(auto array) {
    for(auto value : array) {
        std::cout << value << ' ';
    }
    std::cout<<std::endl;
}
*/


int main() {
    std::array<int, 3> int_array = {1,2,3};
    // print_array<std::array<int, 3>>(int_array); OR
    print_array(int_array); // Type implied automatically

    std::array<float, 3> float_array = {1.1f, 2.2f, 3.3f};
    // print_array<std::array<float, 3>>(float_array); OR
    print_array(float_array); // Type implied automatically

}