#include <iostream>

class Counter {
    public:
        static int objectCount; // Declaration of a static member variable

        Counter() {
            objectCount++;
        }
};

int Counter::objectCount = 0; // Definition must be outside the class

int main()
{
    Counter c1, c2, c3;
    std::cout << "Number of objects created: " << Counter::objectCount << '\n';
    
    return 0;
}

/*
Notes:
Static member variables are shared across all instances of the class. They are not tied to a specific object and can be accessed without creating an instance of the class.

*/