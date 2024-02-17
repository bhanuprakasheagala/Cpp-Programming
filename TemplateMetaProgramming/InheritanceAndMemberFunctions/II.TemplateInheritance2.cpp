#include <iostream>
template <typename T>
class Base {
    public:
        void func1() const {
            std::cout << "func1()\n";
        }
        void func2() const {
            std::cout << "func2()\n";
        }
        void func3() const {
            std::cout << "func3()\n";
        }
};

template <typename T>
class Derived : public Base<T> {
    public:
        using Base<T>::func2;   // (2)
        void callAllBaseFunctions() {
            this->func1();      // (1)
            func2();            // (2)
            Base<T>::func3();   // (3)
        }
};

int main()
{
    Derived<int> obj;
    obj.callAllBaseFunctions();
    return 0;
}

/*
Output:
    func1()
    func2()
    func3()

NOTES:
    (1) Make the name dependent: The call `this->func1()` in line1 is dependent because `this`
        is implicit dependent. The name lookup will consider, in this case, all base classes.
        This is the recommended way.

    (2) Introduce the name into the current scope: The expression `using Base<T>::func2` in (line 2)
        introduces func2 into the current scope.
        
    (3) Call the name fully qualified: Calling func3 fully qualified (line 3) will break a virtual
        dispatch and may cause new surprises.
*/