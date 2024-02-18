#include <iostream>
#include <cstddef>

class Array1 {
    public:
        int getSize() const {
            return 0;
        }
    private:
        int elem[10];
};

template <typename T, std::size_t N>
class Array2 {
    public:
        std::size_t getSize() const {
            return N;
        }
    private:
        T elem[N];
};

int main()
{
    Array1 arr;

    Array2<int, 5> myArr1;
    Array2<double, 5> myArr2;

    std::cout << myArr2.getSize() << '\n'; 

    return 0;
}

/*
Output:
5

NOTES:
When you instantiate, for example, a class template  Array2 for various types, only the
used member functions are instantiated. This laziness does not hold for a non-template class Array1. 

The member function getSize() of the class template Array2 is only instantiated for myArr2 (1).
The call causes this instantiation myArr2.getSize() (2).
*/