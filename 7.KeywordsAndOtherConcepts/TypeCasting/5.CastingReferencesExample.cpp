#include <iostream>

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {};

int main()
{
    Derived derivedObj;

    // Safe upcast(Derived to Base)
    Base& baseRef = static_cast<Base&>(derivedObj);

    try {
        // Safe downcast using dynamic_cast
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);
        std::cout << "dynamic_cast succeded for reference.\n";
    }
    catch (const std::bad_cast& e){
        std::cout << "dynamic_cast failed: " << e.what() << '\n';
    }

    return 0;
}