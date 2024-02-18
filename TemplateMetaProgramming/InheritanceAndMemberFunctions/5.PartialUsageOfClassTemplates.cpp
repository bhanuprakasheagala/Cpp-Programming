#include <iostream>
#include <vector>

template <typename T>       // (1)
class Matrix {
    public:
        explicit Matrix(std::initializer_list<T> inList) : data(inList) {}
        void printAll() const {     // (2)
            for(const auto& d : data)
                std::cout << d << " ";
        }
    private:
        std::vector<T> data;
};

int main()
{
    const Matrix<int> myMatrix1({1,2,3,4,5});
    myMatrix1.printAll();       // (3)
    std::cout << "\n";

    const Matrix<int> myMatrix2({6,7,8,9,10});
    myMatrix2.printAll();       // (4)
    std::cout << "\n";

    const Matrix<Matrix<int>> myMatrix3({myMatrix1, myMatrix2});
    myMatrix3.printAll();   // If we enable this line, ERROR.

    return 0;
}

/*
Output:
1 2 3 4 5 
6 7 8 9 10

NOTES:
The class template Matrix (1) is intentionally simple. It has a type parameter T, that holds its
data in a std::vector, and can be initialized by a std::initalizer_list. Matrix supports the
member function printAll() to display all its members. (3) and (4) show its usage.
The output operator is not overloaded for Matrix Consequently,
we can create myMatrix3 having other Matrix objects as members, but we cannot display them.

Enabling line 5 causes a pretty verbose error message of about 112 lines.

g++ -std=c++11 5.PartialUsageOfClassTemplates.cpp 2>&1| wc -l
112
*/