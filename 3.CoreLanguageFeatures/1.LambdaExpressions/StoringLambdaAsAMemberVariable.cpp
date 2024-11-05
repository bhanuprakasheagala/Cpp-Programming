#include <iostream>
#include <functional>

class MyClass {
public:
    // Constructor accepting a lambda
    MyClass(std::function<void()> lambda) {
        this->lambda_ = lambda; // Store lambda
    }

    void callLambda() {
        lambda_();  // Invoke the stored lambda
    }

private:
    std::function<void()> lambda_;
};

int main()
{
    // Lambda passed to constructor
    MyClass obj1([]() {
        std::cout << "Lambda Called!\n";
    });

    MyClass obj2([]() {
        std::cout << "Another Lambda Called\n";
    });

    obj1.callLambda();
    obj2.callLambda();

    return 0;
}

/*
Notes:

The std::function<void()> member variable can store any lambda or callable object that matches the signature void().
It allows you to pass a lambda as an argument to the constructor and store it.
The callLambda() function simply calls the stored lambda when invoked.
*/