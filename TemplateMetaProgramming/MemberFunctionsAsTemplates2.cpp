/*
Here is a naive implementation of the class Array that supports the assignment of two arrays of the same length.
The C-array elem is intentionally public.
The assignment operator Array<T, N>& operator = (const Array<T2, N>& arr) accepts arrays that could vary in
the underlying type but could not vary in length.

To make `elem` private, it must be a friend of the class.

*/
#include <iostream>
#include <cstddef>
#include <string>


template <typename T, std::size_t N>
class Array {
    public:
        template <typename T2>
        Array<T, N>& operator = (const Array<T2, N>& arr) {
            std::copy(std::begin(arr.elem), std::end(arr.elem), std::begin(elem));
            return *this;
        }
        template<typename, std::size_t> friend class Array; // Declares all instances of Array to friends
        std::size_t getSize() const {
            return N;
        }
    private:
        T elem[N];
};
/*
The assignment operator Array<T, N>& operator = (const Array<T2, N>& arr) accepts arrays
that could vary in the underlying type but could not vary in length.
*/


/*
Alternatively above class and functions can be implemented as follows:
Defining the generic member function outside the class:

template <typename T, std::size_t N>
class Array {
    public:
        template <typename T2>
        Array<T,N>& operator = (const Array<T2, N>& arr);
        template<typename, std::size_t> friend class Array;
        std::size_t getSize() const;
    private:
        T elem[N];
};


template <typename T, std::size_t N>
std::size_t Array<T, N>::getSize() const {
    return N;
}

template <typename T, std::size_t N>
template <typename T2>
Array<T,N>& Array<T, N>::operator = (const Array<T2, N>& arr) {
    std::copy(std::begin(arr.elem), std::end(arr.elem), std::begin(elem));
    return *this;
}

In this case, we define a generic member function outside the class body; you have to specify that the class
and the member functions are templates. Additionally, you have to specify the full type qualification of the
generic member function. So far, the assignment operator is used for types T and T2 that is not convertible.
Invoking the assignment operator with non-convertible types gives an ugly error message.
*/

int main() {

    Array<float, 5> floatArr1;
    Array<float, 5> floatArr2;

    floatArr2 = floatArr1; // Same type and size: Valid

    Array<double, 5> doubleArr;
    doubleArr = floatArr1; // Same size but not type : Valid as Assignment operator overload

    return 0;
}
