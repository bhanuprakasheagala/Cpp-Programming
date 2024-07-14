#include <iostream>
#include <new>  // Required for placement new

class MyClass {
public:
    MyClass(int x) : x_(x) {
        std::cout << "MyClass constructed with value " << x_ << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructed" << std::endl;
    }

    void display() {
        std::cout << "Value: " << x_ << std::endl;
    }

private:
    int x_;
};

int main() {
    // Allocate a buffer of raw memory sufficient to hold one MyClass object
    char buffer[sizeof(MyClass)];

    // Use placement new to construct a MyClass object in the buffer
    MyClass* p = new (buffer) MyClass(42);

    // Use the object
    p->display();

    // Manually call the destructor
    p->~MyClass();

    return 0;
}
