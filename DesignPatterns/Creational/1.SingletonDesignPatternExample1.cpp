/*
#### Definition
- The Singleton Pattern ensures a class has only one instance and provides a global access point to it.

#### Key Concepts
1. Single Instance: Only one instance of the class exists throughout the application.
2. Global Access: The instance is accessible globally, usually through a static method.
3. Lazy Instantiation: The instance is created only when needed (not at the start).
4. Private Constructor: Prevents external instantiation of the class.
5. Deleted Copy Constructor & Assignment Operator: Prevents copying or assigning the instance.
6. Thread-Safety: Handling concurrent access to ensure one instance in multithreading.

#### Basic Structure
1. Private Static Instance: Holds the single instance of the class.
2. Private Constructor: Prevents direct instantiation.
3. Static `getInstance()` Method: Returns the single instance of the class.

#### Thread-Safety
1. Mutex: Use `std::mutex` to ensure thread-safe creation.
2. Double-Checked Locking: Reduce overhead by checking if the instance is null before locking.

#### Variants of Singleton
1. Eager Initialization: Instance is created when the class is loaded.
2. Lazy Initialization: Instance is created when `getInstance()` is first called.
3. Static Local Variable: C++11 feature where static local variable initialization is thread-safe.

#### Advantages
- Controlled Access to a single instance.
- Global Access to the instance.
- Lazy Loading saves resources.

#### Disadvantages
- Global State can lead to tight coupling.
- Difficult Testing: Hard to mock and test in isolation.
- Hidden Dependencies between classes.

### When to Use
- When you need to ensure only one instance of a class is used (e.g., logging, configuration, database connection).
*/


#include <iostream>
#include <mutex>

class Singleton {
private:
    // Private static instance of the class
    static Singleton* instance;
    static std::mutex mtx;
    
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
        std::lock_guard<std::mutex> lock(mtx);  // Lock mutex to ensure thread safety
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
std::mutex Singleton::mtx; // Initialize mutex

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
