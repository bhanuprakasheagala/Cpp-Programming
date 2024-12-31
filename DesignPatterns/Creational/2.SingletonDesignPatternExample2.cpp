#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
private:
    static Singleton* instance;
    static std::once_flag flag;

    Singleton() {
        std::cout << "Singleton instance created\n";
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance() {
        std::call_once(flag, []() {
            instance = new Singleton(); // Initialize only once, guarenteed thread safe
        });

        return instance;
    }

    void showMessage() {
        std::cout << "Hello from Singleton thread " << std::this_thread::get_id() << '\n';
    }

    ~Singleton() {
        std::cout << "Destructor of Singleton\n";
    }

};

Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::flag;

void threadFunc(int threadNum) {
    std::cout << "Thread " << threadNum << " trying to get Singleton instance\n";
    Singleton* singleton = Singleton::getInstance();
    singleton->showMessage();
}

int main()
{
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();

    return 0;
}