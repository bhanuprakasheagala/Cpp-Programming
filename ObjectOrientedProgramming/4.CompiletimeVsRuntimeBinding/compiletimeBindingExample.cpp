#include <iostream>

class baseClass {
    public:
        void print();
        baseClass(int u = 0);
    private:
        int x;
};

class derivedClass : public baseClass {
    public:
        void print();
        derivedClass(int u=0, int v=0);
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

// Formal parameter is of type baseClass&
void callPrint(baseClass& p) {
    p.print();
}

int main() {
    baseClass one(5);
    derivedClass two(3,4);

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
In derivedClass: In baseClass x = 3
In derivedClass a = 4
Calling the function callPrint: 
In baseClass x = 5
In baseClass x = 3

Notes: For both `callPrint` calls in the main,the member function print of the class baseClass is executed.
This is due to the fact that the binding of the member function print, in the body of the function callPrint,
occurred at compile time. Because the formal parameter p of the function callPrint is of type baseClass,
for the statement p.print();, the compiler associates the function print of the class baseClass.
More specifically, in compile-time binding, the necessary code to call a specific function is generated
by the compiler.(Compile-time binding is also known as static binding.)
*/