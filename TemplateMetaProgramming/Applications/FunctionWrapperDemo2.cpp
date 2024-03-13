#include <iostream>
#include <tuple>
#include <functional>

// Define a function wrapper template
template <typename Func, typename... Args>
class FunctionWrapper {

    public:
        FunctionWrapper(Func fun, Args... arg) : m_func(fun), m_args(arg...) {}

        auto operator()()->decltype(auto) {
            return std::apply(m_func, m_args);
        }
    private:
        //std::function<Func> m_func;
        Func m_func;
        std::tuple<Args...> m_args;
};

// Example 1 : Regular Function
int add(int a, int b) {
    return a+b;
}

// Example 2 : Functor(Function Object)
struct AddFunctor {
    int operator()(int a, int b, int c) const {
        return a+b+c;
    }
};

// Example 3 : Class with a Member function
struct myClass {
    double div(int a, char b, double c) const {
        return (a + static_cast<int>(b))/c;
    }
};

int main() {

    // Example1
    FunctionWrapper<decltype(&add), int, int> wrapper1(add, 4, 5);
    std::cout << "Regular function: " << wrapper1() << '\n';

    // Example2
    AddFunctor addFunctor;
    FunctionWrapper<AddFunctor, int, int, int> wrapper2(addFunctor, 1, 2, 4);
    std::cout << "Functor: " << wrapper2() << '\n';

    // Example3
    myClass obj;
    auto addMemberPtr = &myClass::div;
    FunctionWrapper<decltype(addMemberPtr), myClass*, int, char, double> wrapper3(addMemberPtr, &obj, 3, 'c', 2.5);
    std::cout << "Member Function: " << wrapper3() << '\n';

    return 0;
}