#include <iostream>

class Box {
    public:
        static int objectCount;

        Box() {
            objectCount++;
        }

        ~Box() {
            objectCount--;
        }

        static int getObjectCount() {
            return objectCount;
        }
};

int Box::objectCount = 0;

int main()
{
    Box b1, b2;
    std::cout << "Object Count: " << Box::getObjectCount() << '\n'; // Outputs 2
    {
        Box b3;
        std::cout << "Object Count: " << Box::getObjectCount() << '\n'; // Outputs 3
    }
    std::cout << "Object Count: " << Box::getObjectCount() << '\n'; // Outputs 2
    
    return 0;
}