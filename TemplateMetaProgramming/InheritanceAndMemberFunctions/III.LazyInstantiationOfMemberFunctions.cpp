#include <iostream>
template <class T>
struct Lazy {
    void func1() {
        std::cout << "func1()\n";
    }
    void func2();  // Not defined
};
int main()
{
    Lazy<int> lazy;
    lazy.func1();

    return 0;
}

/*
Output:
func1()

NOTES:
Although the method `func2 ()`of class `Lazy` is only declared but not defined, the compiler
accepts the program. Because `func2`, a definition of the member function is not necessary.

This laziness of the instantiation process of member functions has two interesting properties.
1. Save Resources:
2. Partial Usage of Class Templates : You can instantiate class templates with template arguments
                                      that do not support all member functions.
                                      When you don’t call those member functions, all is fine.
*/