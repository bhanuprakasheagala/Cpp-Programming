#include <iostream>
#include <vector>
#include <algorithm>

class BufferManager {
public:
    std::vector<int> buffer;

    // Constructor
    BufferManager(size_t size) : buffer(size, 0) {}

    // Copy constructor (deep copy)
    BufferManager(const BufferManager& other) : buffer(other.buffer) {
        std::cout << "Copy constructor called\n";
    }

    // Move constructor (transfer ownership)
    BufferManager(BufferManager&& other) noexcept : buffer(std::move(other.buffer)) {
        std::cout << "Move constructor called\n";
    }

    // Copy assignment operator
    BufferManager& operator=(const BufferManager& other) {
        if(this == &other) {
            return *this;
        }
        buffer = other.buffer;
        std::cout << "Copy Assignment operator called\n";

        return *this;
    }

    // Move assignment operator
    BufferManager& operator=(BufferManager&& other) {
        if(this == &other) {
            return *this;
        }
        buffer = std::move(other.buffer);
        std::cout << "Move Assignment operator called\n";

        return *this;
    }

    void print() {
        std::cout << "Buffer size: " << buffer.size() << '\n';
    }

 };

int main()
{
    BufferManager bm1(10); // Constructor
    BufferManager bm2 = bm1; // Copy constructor
    BufferManager bm3 = std::move(bm1); // Move constructor

    bm2.print();
    bm3.print();

    BufferManager bm4(5);
    bm4 = bm2;      // Copy assignment
    bm4.print();

    BufferManager bm5(4);
    bm5 = std::move(bm4); // Move assignment
    bm5.print();
    bm4.print();

    return 0;
}