#include <iostream>

class MyClass {
    int* data;
    
    public:
        // Constructor
        MyClass(int value) {
            data = new int(value);
            std::cout << "Constructor: " << *data << '\n';
        }

        // Destroy
        ~MyClass() {
            delete data;
            std::cout << "Destructor\n";
        }

        // Copy constructor
        MyClass(const MyClass& other) {
            data = new int(*other.data);
            std::cout << "Copy constructor: " << *data << '\n';
        }

        // Copy assignment operator
        MyClass& operator=(const MyClass& other) {
            if(this != &other) {
                delete data;
                data = new int(*other.data);
                std::cout << "Copy assignment: " << *data << '\n';
            }

            return *this;
        }

        // Move constructor
        MyClass(MyClass& other) noexcept {
            data = other.data;
            other.data = nullptr;
            std::cout << "Move constructor\n";
        }

        // Move assignment operator
        MyClass& operator=(MyClass&& other) noexcept {
            if(this != &other) {
                delete data;
                data = other.data;
                other.data = nullptr;
                std::cout << "Move assignment operator\n";
            }

            return *this;
        }
};

int main()
{
    MyClass obj1(10);
    MyClass obj2 = std::move(obj1); // Calls Move constructor
    obj2 = MyClass(20);     // Calls Move assignment operator

    MyClass obj3(30);
    obj3 = obj2;            // Calls Copy assignment operator

    return 0;
}