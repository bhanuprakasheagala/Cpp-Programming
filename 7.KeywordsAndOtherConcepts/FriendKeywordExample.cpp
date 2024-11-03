#include <iostream>

class Base {
    private:
        int x;
    public:
        Base() {}
        Base(int val) : x(val) {}

        friend void fun(Base&);
};

void fun(Base& obj) {
    std::cout << obj.x << '\n';
    obj.x = 20;
    std::cout << obj.x << '\n';
}

int main() {

    Base b(10);
    fun(b);

    return 0;
}