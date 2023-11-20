#include <array>
#include <iostream>

template<typename T>
void print_array(T array) {
    for(auto value : array) {
        std::cout << value << ' ';
    }
    std::cout<<std::endl;
}

int main() {
    std::array<int, 3> int_array = {1,2,3};
    print_array<std::array<int, 3>>(int_array);

    std::array<float, 3> float_array = {1.1f, 2.2f, 3.3f};
    print_array<std::array<float, 3>>(float_array);

}