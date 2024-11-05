#include <iostream>

class MyClass {
public:
    MyClass(int value) {
        // Initialize the lambda, capturing the constructor parameter
        lambda_ = [value] {
            std::cout << "Captured value: " << value << '\n';
        };
    }

    void callLambda() {
        lambda_();  // Calls the lambda
    }

private:
    std::function<void()> lambda_;  // Store the lambda
};

class YourClass {
public:
    YourClass(int& value) {
        ld_ = [&value] {
            value++;
            return value;
        };
    }

    void callLd() {
        int res = ld_();
        std::cout << res << '\n';
    }

private:
    std::function<int()> ld_;
};

int main()
{   
    MyClass obj1(42);    // Lambda will capture the value
    obj1.callLambda();   
    
    int x = 34;
    YourClass obj2(x);
    obj2.callLd();

    std::cout << x << '\n'; //35


    return 0;
}