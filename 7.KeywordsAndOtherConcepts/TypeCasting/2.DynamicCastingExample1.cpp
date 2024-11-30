#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class\n";
    }
};

int main()
{
    Base* basePtr = new Derived();

    // Use dynamic_cast to safely cast base pointer to derived pointer
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if(derivedPtr) {
        derivedPtr->show(); // Calls Derived::show
    }
    else {
        std::cout << "dynamic_cast failed\n";
    }

    delete basePtr;

    return 0;
}