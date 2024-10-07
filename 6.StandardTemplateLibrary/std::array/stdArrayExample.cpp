/*
`std::array`
Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.
template < class T, size_t N > class array;

`std::array::data` Example:
Returns a pointer to the first element in the array object.
Because elements in the array are stored in contiguous storage locations, the pointer retrieved can be offset
to access any element in the array.

`std::array::swap` Example:
Exchanges the content of the array by the content of x, which is another array object of the same type
(including the same size).
After the call to this member function, the elements in this container are those which were in x before the call, and
the elements of x are those which were in `this`.
*/

#include <iostream>
#include <cstring>
#include <array>

int main() {

    const char* cstr = "Test string";
    std::array<char, 12> charArray;

    std::memcpy(charArray.data(), cstr, 12);

    std::cout << charArray.data() << '\n';

    std::array<int, 5> first = {10,20,30,40,50};
    std::array<int, 5> second = {11,22,33,44,55};

    first.swap(second);

    std::cout << "first: ";
    for(int& x : first)
        std::cout<<x<<' ';
    std::cout <<'\n';

    std::cout << "second: ";
    for(int& x : second)
        std::cout<<x<<' ';
    std::cout <<'\n';

    return 0;
}