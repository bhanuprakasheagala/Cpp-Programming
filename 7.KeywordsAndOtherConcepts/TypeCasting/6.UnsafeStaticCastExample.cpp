#include <iostream>

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {};

int main()
{
    Base* base = new Derived();

    // Downcast Base* to Dervided* (No runtime check so here at compile time it doesn't know)
    Derived* derived = static_cast<Derived*>(base);
    if(derived) {
        std::cout << "Downcast succeeded using static_cast\n";
    }
    
    delete base;

    return 0;
}

/*
Output:
Downcast succeeded using static_cast

Why Unsafe?
If the object pointed to by base wasn’t of type Derived, the cast would still succeed but lead to undefined behavior when dereferenced.
Avoid static_cast for downcasting in polymorphic hierarchies unless you are absolutely certain of the object's type.
*/