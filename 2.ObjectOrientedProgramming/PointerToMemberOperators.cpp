#include <iostream>

class BaseClass {
    public:
        BaseClass() {
            std::cout << "Base Class\n";
        }
        void Func1() {
            std::cout << "Base Func1\n";
        }
};

void (BaseClass::*pmfnFunc1)() = &BaseClass::Func1;

class DerivedClass : public BaseClass {
    public:
        DerivedClass() {
            std::cout << "Derived Class\n";
        }
        void Func2() {
            std::cout << "Derived Func2\n";
        }
};

void (DerivedClass::*pmfnFunc2)() = &DerivedClass::Func2;

int main()
{
    //std::cout<<"Hello World";
    BaseClass bc;
    DerivedClass dc;
    
    (bc.*pmfnFunc1)();
    // (bc.*pmfnFunc2)(); Error: Can't use base class to access pointers to members of derived class
    
    (dc.*pmfnFunc1)();
    (dc.*pmfnFunc2)();
    
    return 0;
}