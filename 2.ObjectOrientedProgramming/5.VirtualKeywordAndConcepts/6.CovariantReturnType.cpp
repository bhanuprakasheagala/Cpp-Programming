#include <iostream>

class Base {
    public:
        virtual Base* clone() {
            std::cout << "Base variant\n";
            return new Base(*this);
        }
};

class Derived : public Base {
    public:
        Derived* clone() override {     // Covariant return type
            std::cout << "Derived variant\n";
            return new Derived(*this);
        }
};

int main()
{
    Base* b1 = new Derived();
    std::cout << b1->clone() << '\n';

    return 0;
}