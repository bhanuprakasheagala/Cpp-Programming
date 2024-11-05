#include <iostream>

class MyClass {
public:
    MyClass(int value) {
        lambda_ = [value]() mutable {
            value++;
            std::cout << "Modified captured value: " << value << '\n';
        };
    }

    void callLambda() {
        lambda_();
    }

private:
    std::function<void()> lambda_;
};

int main()
{
    int x = 10;
    MyClass obj(x);
    obj.callLambda();

    std::cout << "Original x value after lambda: " << x << '\n';
    
    return 0;
}