#include <iostream>

class Base {
    public:
        virtual void show() const{
            std::cout << "Base class show()\n";
        }
};

class Derived : public Base {
    public:
        void show() const override{
            std::cout << "Derived class show()\n";
        }
};

int main()
{
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    basePtr->show(); // Calls derived class show() due to virtual function

    return 0;
}