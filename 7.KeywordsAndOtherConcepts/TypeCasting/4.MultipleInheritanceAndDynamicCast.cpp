#include <iostream>

class Interface {
public:
    virtual void interfaceMethod() = 0;
    virtual ~Interface() = default;
};

class Base {
public:
    virtual void baseMethod() {
        std::cout << "Base Method\n";
    }
    virtual ~Base() = default;
};

class Derived : public Base, public Interface {
public:
    void baseMethod() override {
        std::cout << "Derived Base Method\n";
    }

    void interfaceMethod() override {
        std::cout << "Interface Method\n";
    }
};

int main()
{
    Interface* interfacePtr = new Derived();

    // Use dynamic_cast to check if interfacePtr can be cast to Base
    if(Base* basePtr = dynamic_cast<Base*>(interfacePtr)) {
        basePtr->baseMethod();
    }
    else {
        std::cout << "Cast to Base failed\n";
    }

    delete interfacePtr;
    
    return 0;
}