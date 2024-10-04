#include <iostream>
#include <string>

class User {
    private:
        std::string name;
        mutable int logCount; // This is mutable so it can be modified in const method
    
    public:
        User(const std::string& userName) : name(userName), logCount(0) {}

        // A const method that logs the number of times the user's name is accessed
        void displayName() const {
            logCount++;
            std::cout << "User: " << name << '\n';
        }

        // Get the log count
        int getLogCount() const {
            return logCount;
        }
};

int main() {
    const User user1("Alice");
    
    const User user2("Bob");

    // We are calling a const method on a const object
    user1.displayName(); // Allowed because logCount is mutable
    user2.displayName();
    user1.displayName();

    std::cout << "Username1 accessed: " << user1.getLogCount() << " times.\n";
    std::cout << "Username2 accessed: " << user2.getLogCount() << " times.\n";

    return 0;
}