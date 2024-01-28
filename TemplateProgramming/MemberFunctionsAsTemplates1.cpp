/*
A typical example of a generic member function is a templated assignment operator.
The reason is straightforward. You want to assign an Array<T, N> to an Array<T2, N2>
if T is assignable to T2 and both arrays have the same size.
*/
#include <iostream>
#include <cstddef>
#include <string>

template <typename T, std::size_t N>
class Array {
    public:
        std::size_t getSize() const {
            return N;
        }
    private:
        T elem[N];
};

int main() {

    Array<float, 5> floatArr1;
    Array<float, 5> floatArr2;

    floatArr2 = floatArr1; // Same type and size: Valid

    /*
    Array<double, 5> doubleArr;
    floatArr2 = doubleArr; // Same size but not type: Error
    */

    return 0;
}
