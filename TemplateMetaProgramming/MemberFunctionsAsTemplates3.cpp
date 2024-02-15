#include <iostream>
#include <algorithm>
#include <cstddef>
#include <string>
#include <concepts>

template <typename T, std::size_t N>
class Array {
    public:
        template <typename T2>
        Array<T, N>& operator=(const Array<T2, N>& arr) requires std::convertible_to<T2, T>;
        template <typename, std::size_t> friend class Array;
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
Array<T, N>& Array<T, N>::operator=(const Array<T2, N>& arr) requires std::convertible_to<T2, T> {
    std::copy(std::begin(arr.elem), std::end(arr.elem), std::begin(elem));
    return *this;
} 

int main()
{
    Array<float, 5> floatArr1;
    Array<float, 5> floatArr2;
    floatArr1.getSize();

    floatArr2 = floatArr1;

    Array<double, 5> doubleArr;
    doubleArr = floatArr1;

    floatArr2 = doubleArr;

    Array<int, 5> intArray;
    intArray = doubleArr;

    intArray = floatArr1;
    floatArr2 = intArray;
    doubleArr = intArray;

    Array<std::string, 5> strArr;
    doubleArr = strArr;   //error: no viable overloaded '='

    return 0;
}