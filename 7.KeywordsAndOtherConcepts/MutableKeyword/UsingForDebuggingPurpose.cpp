#include <iostream>

class AccessCounter {
private:
    mutable int accessCount = 0;

public:
    int getValue() const {
        ++accessCount;
        return 42;
    }

    int getAccessCount() const {
        return accessCount;
    }
};

int main()
{
    AccessCounter counter;
    std::cout << "Value: " << counter.getValue() << '\n';
    std::cout << "Value: " << counter.getValue() << '\n';
    std::cout << "Access Count: " << counter.getAccessCount() << '\n';
    std::cout << "Value: " << counter.getValue() << '\n';
    std::cout << "Value: " << counter.getValue() << '\n';
    std::cout << "Access Count: " << counter.getAccessCount() << '\n';
    return 0;
}