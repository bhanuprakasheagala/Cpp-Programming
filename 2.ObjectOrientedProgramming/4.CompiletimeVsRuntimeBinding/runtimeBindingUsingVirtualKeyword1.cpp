/*
The binding of virtual functions occurs at program execution time, not at compile time. This kind of binding
is called run-time binding. More formally, in run-time binding, the compiler does not generate the code to
call a specific function. Instead, it generates enough information to enable the run-time system to generate
the specific code for the appropriate function call. Run-time binding is also known as dynamic binding.
*/
#include <iostream>

class baseClass {
    public:
        virtual void print(); // We need to declare a virtual function only in the base class
        baseClass(int u = 0);
    private:
        int x;
};

class derivedClass : public baseClass {
    public:
        void print();
        derivedClass(int u = 0, int v = 0);
    private:
        int a;
};
void baseClass::print() {
    std::cout << "In baseClass x = " << x << '\n';
}

baseClass::baseClass(int u) {
    x = u;
}

void derivedClass::print() {
    std::cout << "In derivedClass: ";
    baseClass::print();
    std::cout << "In derivedClass a = " << a << '\n';
}

derivedClass::derivedClass(int u, int v) : baseClass(u) {
    a = v;
}

// Formal parameter is a reference type (baseClass&)
void callPrint(baseClass& p) {
    p.print();
}

int main() {
    baseClass one(5);
    derivedClass two(10,15);

    one.print();
    two.print();

    std::cout << "Calling the function callPrint: " << '\n';

    // Object `one` is of type baseClass
    callPrint(one);

    // Object `two` is of type derivedClass.
    callPrint(two);

    return 0;
}

/*
Output:

In baseClass x = 5
In derivedClass: In baseClass x = 10
In derivedClass a = 15
Calling the function callPrint: 
In baseClass x = 5
In derivedClass: In baseClass x = 10
In derivedClass a = 15

*/