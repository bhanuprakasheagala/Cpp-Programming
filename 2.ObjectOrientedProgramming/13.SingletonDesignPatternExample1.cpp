#include <iostream>

class Singleton {
private:
    // Private static instance of the class
    static Singleton* instance;
    
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton Instance created!\n";
    }
    
    // Private copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Public static method to access the singleton instance
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton(); // Lazy instantiation
        }
        return instance;
    }
    
    // A method to demonstrate the usage of the singleton
    void showMessage() {
        std::cout << "Hello from Singleton\n";
    }
    
    ~Singleton(){}
};

// Initialize the static instance to nullptr
Singleton* Singleton::instance = nullptr;

int main() {
    
    // Access singleton instance and use it's method
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();
    
    // Access the same Singleton instance again
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();
    
    // Check if both instances are the same
    std::cout << "Are both instances the same?\n" <<(singleton1 == singleton2 ? "Yes" : "No") << '\n';
    
    return 0;
}

/*
Output:
Singleton Instance created!
Hello from Singleton
Hello from Singleton
Are both instances the same?
Yes
*/
