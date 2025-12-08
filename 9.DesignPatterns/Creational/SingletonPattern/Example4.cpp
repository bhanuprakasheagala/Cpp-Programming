#include <iostream>

class Logger {
    public:

        // Delete copy constructor and assignment operator to prevent copies
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        /*
        What's happening here: getInstance() method uses a static local variable to hold the single instance of Logger.
        The first time getInstance() is called, the static variable is initialized, and the same instance is returned on subsequent calls.
        First instantiation calls the constructor Logger() from private section. We don't need to check if the instance is already created or not for subsequent calls
        because static local variables are initialized only once. If we call second time, it will return the already created instance.

        static local Logger instance : This variable is created only once and retains its value between function calls.
        1. On the first call to getInstance(), instance is created and initialized.
        2. On next call, C++ runtime checks that instance is already initialized by looking at its internal state and directly returns the existing instance without re-initializing it.
        3. This ensures that only one instance of Logger is created throughout the program's lifetime
        */
        static Logger& getInstance() {
            static Logger instance;
            return instance;
        }

        void log(const std::string& message) {
            std::cout << "Log: " << message << std::endl;
        }
    
    // Private constructor to prevent direct instantiation and Private Destructor to prevent deletion of the instance from outside the class
    private:
        Logger() {
            std::cout << "Logger Instance Created" << std::endl;
        }
        ~Logger() {
            std::cout << "Logger Instance Destroyed" << std::endl;
        }
};

int main() {

    Logger& logger1 = Logger::getInstance();
    logger1.log("This is the first log message."); // First call, creates the instance

    Logger& logger2 = Logger::getInstance();
    logger2.log("This is the second log message."); // Second call, we use the same instance

    return 0;
}