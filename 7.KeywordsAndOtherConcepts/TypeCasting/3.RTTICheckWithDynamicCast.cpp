#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {};

class AnotherDerived : public Base {};

int main()
{
    Base* basePtr1 = new Derived();

    // Safe casting
    if(Derived* derivedPtr = dynamic_cast<Derived*>(basePtr1)) {
        std::cout << "Casted to Derived successfully\n";
    }
    else {
        std::cout << "Failed to cast to Derived\n";
    }

    // Attempt to cast to an unrelated type
    if(AnotherDerived* anotherPtr = dynamic_cast<AnotherDerived*>(basePtr1)) {
        std::cout << "Casted to AnotherDerived type successfully\n";
    }
    else {
        std::cout << "Failed to cast to AnotherDerived\n";
    }

    delete basePtr1;


    // Make the Base pointer related to AnotherDerived 
    Base* basePtr2 = new AnotherDerived();
    if(AnotherDerived* anotherPtr = dynamic_cast<AnotherDerived*>(basePtr2)) {
        std::cout << "Casted to AnotherDerived type successfully\n";
    }
    else {
        std::cout << "Failed to cast to AnotherDerived\n";
    }
    delete basePtr2;

    return 0;
}