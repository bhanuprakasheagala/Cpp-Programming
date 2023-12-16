/*
`std::array`
Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.
template < class T, size_t N > class array;

`std::array::data` Example:
Returns a pointer to the first element in the array object.
Because elements in the array are stored in contiguous storage locations, the pointer retrieved can be offset
to access any element in the array.
*/

#include <iostream>
#include <cstring>
#include <array>

int main() {

    const char* cstr = "Test string";
    std::array<char, 12> charArray;

    std::memcpy(charArray.data(), cstr, 12);

    std::cout << charArray.data() << '\n';

    return 0;
}