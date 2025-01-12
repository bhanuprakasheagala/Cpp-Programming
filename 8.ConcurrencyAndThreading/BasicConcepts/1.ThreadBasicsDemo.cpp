#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from thread\n";
}

int main() {

    std::thread t1(printMessage);
    t1.join();

    std::cout << "Hello from main thread\n";
    return 0;
}