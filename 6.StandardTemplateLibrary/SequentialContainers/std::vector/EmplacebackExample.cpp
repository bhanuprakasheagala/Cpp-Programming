#include <iostream>
#include <vector>

class MyClass {
    public:
        MyClass(int x) {
            std::cout << "Constructor called with value: " << x << '\n';
        }
        MyClass(const MyClass&) {
            std::cout << "Copy constructor called\n";
        }
        MyClass(MyClass&&) noexcept {
            std::cout << "Move constructor called\n";
        }
};

int main() {

    std::vector<MyClass> vec;
    std::cout << "Using push_back: \n";
    MyClass obj(10);
    vec.push_back(obj); // Copy constructor will be called

    std::cout << "\nUsing emplace_back:\n";
    vec.emplace_back(20); // Constructor directly called, no copy/move

    return 0;
}