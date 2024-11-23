/*
auto - Used for type deduction

*/

#include <iostream>
#include <typeinfo>

class Base {};

int main() {

    auto x = 10;         // x is of type int
    auto y = 3.14;      // y is of type double
    auto str = "Hello"; // str is of type const char*
    auto sp = std::make_shared<Base>;
    auto up = std::make_unique<Base>;
    auto classType1 = Base();
    auto classType2 = new Base();

    std::cout << typeid(x).name() << '\n' << typeid(y).name() << '\n' << typeid(str).name() << '\n'
    << typeid(classType1).name() << '\n' << typeid(classType2).name() << '\n' << typeid(sp).name() << '\n'
    << typeid(up).name() << '\n';

    std::vector<int> vec(0);
    const auto a = 10;        // a is a const int
    auto& b = a;              // b is a reference to const int
    const auto& c = vec[0];   // c is a const reference to an int

    std::cout << typeid(vec).name() << '\n' << typeid(a).name()
    << '\n' << typeid(b).name() << '\n' << typeid(c).name() << '\n';

    auto list = {1, 2, 3}; // list is of type std::initializer_list<int>
    auto lambda = [](int a, int b) { return a + b; };
    std::cout << typeid(list).name() << '\n' << typeid(lambda(3, 4)).name() << '\n';


    return 0;
}

/*
One possible output:

i
d
i
d
PKc
4Base
P4Base
PFNSt3__110shared_ptrI4BaseEEvE
PFNSt3__110unique_ptrI4BaseNS_14default_deleteIS1_EEEEvE
NSt3__16vectorIiNS_9allocatorIiEEEE
i
i
i
St16initializer_listIiE
i

Here the above output names may change based on the platform and compiler combinations but
are consistent within the same platform/development environment

The above outputs are mangled by C++ and we can get demangled outputs with a better description.
*/

