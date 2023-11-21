#include <array>
#include <iostream>

// General Baseline function for all the types of print_arry calls
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


// Imagine if I want a specific function(which is a bit different code) for one of the above function calls.
// Instead of calling the General Baseline function, we can create a new function.
// So, this is part of template but handling one of the special cases. We can inform the 
// same to the compiler by using template with empty parameters.
template<>
void print_array(std::array<int,3> array){
    std::cout<<"Printing from our specialization!\n";
}

int main() {
    std::array<int, 3> int_array = {1,2,3};
    // print_array<std::array<int, 3>>(int_array); OR
    print_array(int_array); // Calls int array function instead of baseline function

    std::array<float, 3> float_array = {1.1f, 2.2f, 3.3f};
    // print_array<std::array<float, 3>>(float_array); OR
    print_array(float_array); // Type implied automatically

    std::array<double, 3> double_array = {234.3, 234.56, 345.45};
    print_array(double_array); // Type implied automatically

}
