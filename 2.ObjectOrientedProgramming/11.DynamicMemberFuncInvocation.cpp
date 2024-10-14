// Pointer to Member function

#include <iostream>

class MyClass {
    public:
        void func1() {
            std::cout << "Function 1\n";
        }

        void func2() {
            std::cout << "Function 2\n";
        }
};

int main()
{
    MyClass obj;
    void (MyClass::*ptr)(); // Pointer to a member function which takes no arguments and returns void

    ptr = &MyClass::func1;  // Point to func1
    (obj.*ptr)();           // Call func1 via pointer

    ptr = &MyClass::func2;  // Point to func2
    (obj.*ptr)();           // Call func2 via pointer

    return 0;
}