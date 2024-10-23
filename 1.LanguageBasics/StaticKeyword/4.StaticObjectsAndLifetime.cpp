#include <iostream>

class StaticDemo {
    public:
        StaticDemo() {
            std::cout << "Constructor called\n";
        }
        
        ~StaticDemo() {
            std::cout << "Destructor called\n";
        }
};

int main()
{
    static StaticDemo demo; // Static object
    std::cout << "Main function\n";

    return 0;
}

/*
Static objects in C++ have a lifetime that lasts the entire program. This means they are created when the program starts
and destroyed when the program ends regardless of the function scope.
*/