/*
Create a class implementing the Singleton design pattern, ensuring that only one instance of the class is ever created using static variables.
*/
#include <iostream>

class Singleton {
    private:
        static Singleton* instance;

        // Private constructor to prevent direct instantiation
        Singleton() {
            std::cout << "Singleton instance created\n";
        }
    
    public:
        static Singleton* getInstance() {
            if(instance == nullptr) {
                instance = new Singleton();
            }
            return instance;
        }
};

// Initialize the static member
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if(s1 == s2) {
        std::cout << "Both instances are the same.\n";
    }

    return 0;
}