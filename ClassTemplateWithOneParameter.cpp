// Author : BHANUPRAKASH EAGALA

#include <iostream>

using namespace std;

template<class MemberType>
class TPackage{
    public:
        MemberType m_member;
};

// Instantiating a specific type of the template class TPackage:
// Both TPackage<int> and TPackage<char> are compiled as two independent types.
// They are not derived from any common type or share same data. The only commonality they share is
// that they are generated based on the same pattern, whcih is specified by the TPackage template.

int main()
{
    TPackage<int> integerPackage{};
    TPackage<char> charPackage{};

    integerPackage.m_member = 5;
    charPackage.m_member = 'B';

    cout << integerPackage.m_member << charPackage.m_member;

    return 0;
}

/*
Internally, it is like:
class TPackage_int{
    public:
        int m_member;
};

class TPackage_char{
    public:
        char m_member;
};
During code generation, the template parameter is replaced with the given data types.
As the TPackage template is used fow two different template parameters(int and char),
it is compiled as two different classes - TPackage_int which contains member of type int
and TPackage_char which contains member of type char.
*/
