/*
Run-Time Type Identification (RTTI) is a feature in C++ that allows you to obtain the type information of an object
during program execution. This can be useful when using dynamic typing, where the type of an object can change at
runtime.

There are two main mechanisms for RTTI in C++:
Example1: typeid operator

typeid is an operator that returns a reference to an object of type std::type_info, which contains information
about the type of the object. The header file <typeinfo> should be included to use typeid.

*/

#include <iostream>
#include <typeinfo>

class Base {
    virtual void dummy() {}
};

class DerivedClass : public Base {
    
};

int main()
{
    Base* b = new Base;
    DerivedClass* d = new DerivedClass;

    std::cout << "b is of type: " << typeid(*b).name() << '\n';
    std::cout << "d is of type: " << typeid(*d).name() << '\n';

    delete b;
    delete d;

    return 0;
}