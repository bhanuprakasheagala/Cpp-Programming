#include <iostream>
#include <unordered_map>
#include <memory>

class LargeObject {
private:
    int* data;

public:
    LargeObject() {
        data = new int[1000]; // Allocate large memory
        std::cout << "Large Object created\n";
    }

    // Move constructor
    LargeObject(LargeObject&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "LargeObject moved\n";
    }

    // Move assignment operator
    LargeObject& operator=(LargeObject&& other) {
        if(this == &other) {
            return *this;
        }
        data = other.data;
        other.data = nullptr;

        return *this;
    }

    // Destructor
    ~LargeObject() {
        if(data) {
            delete[] data;
            std::cout << "LargeObject destroyed\n";
        }
    }
};

class Cache {
private:
    std::unordered_map<int, LargeObject> cache;

public:
    void addToCache(int key, LargeObject&& obj) {
        cache[key] = std::move(obj);
    }

    LargeObject retrieveFromCache(int key) {
        return std::move(cache[key]);
    }
};

int main()
{
    Cache cache;
    LargeObject obj;

    cache.addToCache(1, std::move(obj));

    LargeObject obj2 = cache.retrieveFromCache(1);

    return 0;
}