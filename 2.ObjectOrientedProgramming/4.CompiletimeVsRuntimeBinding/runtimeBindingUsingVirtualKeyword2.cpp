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

// Formal parameter is a pointer type (baseClass*)
void callPrint(baseClass *p){
    p->print();
}

int main() {
    baseClass *q;
    derivedClass *r;

    q = new baseClass(5);
    r = new derivedClass(10, 15);

    q->print();
    r->print();

    std::cout << "Calling the function callPrint: " << '\n';

    callPrint(q);
    callPrint(r);

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