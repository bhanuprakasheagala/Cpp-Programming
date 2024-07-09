/*
The dynamic_cast operator is used to safely cast a pointer or reference to a base class to a pointer or
reference to a derived class. If the cast is not possible, dynamic_cast returns nullptr for pointers or throws
a std::bad_cast exception for references.

*/

#include <iostream>

class Base {
    virtual void dummy(){}
};

class Derived : public Base {
    public:
        void derivedFunction() {
            std::cout << "Derived function called!!\n";
        }
};

int main()
{
    Base* b1 = new Base;
    Base* b2 = new Derived;

    Derived* d1 = dynamic_cast<Derived*>(b1); // Will return nullptr
    Derived* d2 = dynamic_cast<Derived*>(b2); // Will Succeed

    if(d1) {
        d1->derivedFunction();
    }
    else {
        std::cout << "b1 is not of type Derived\n";
    }

    if(d2) {
        d2->derivedFunction();
    }
    else {
        std::cout << "b2 is not of type Derived\n";
    }

    delete b1;
    delete b2;

    return 0;
}