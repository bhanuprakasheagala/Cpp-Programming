#include <iostream>

class Base {
    public:
        int a = 10;
        virtual void display() const{
            std::cout << "Base class a = " << a << '\n';
        }
};

class Derived : public Base {
    public:
        int a = 20;
        void display() const override{
            std::cout << "Derived class a = " << a << '\n';
        }
};

int main()
{
    Base b;
    Derived d;

    Base* ptr = &d;
    std::cout << "Base pointer to Derived object: ";
    ptr->display();

    std::cout << "Object slicing: ";
    b = d; 
    b.display();

    /*
        In the line 'b = d', the object 'd' (of type 'Derived') is sliced down to Base.
        The Derived specific data members(including 'Derived::a') are lost, and only
        the 'Base' potion to b available. When 'b.display()' is called, it accesses the
        Base's version of 'a'
    */

    return 0;
}