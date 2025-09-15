#include <iostream>
#include <thread>


/// Demonstrates basic thread creation and joining in C++23

/*
Basic Concepts of Threads in C++23:
1. Thread Creation: You can create a thread by instantiating the std::thread class
   and passing a function or callable object to its constructor.
2. Thread Joining: The join() method is used to wait for a thread to finish its execution.
3. Lambda Functions: You can also use lambda functions to define the thread's task inline.
4. Thread Safety: When multiple threads access shared data, ensure proper synchronization
   using mutexes or other synchronization mechanisms to avoid race conditions/data corruption.
5. Detaching Threads: You can detach a thread using the detach() method, allowing it to run independently.
6. Thread ID: Each thread has a unique ID that can be accessed using std::this_thread::get_id().

*/

void printMessage() {
    std::cout << "Hello from thread with Id: " << std::this_thread::get_id() << '\n';
}

int main() {

    std::thread t1(printMessage);
    std::thread t2([]() {
        std::cout << "Hello from lambda thread with Id: " << std::this_thread::get_id() << '\n';
    });

    t1.join();
    t2.join();

    std::cout << "Hello from main thread with Id: " << std::this_thread::get_id() << '\n';
    return 0;
}

/*
ASCII rerepresentation of the thread execution in C++23:

Main Thread
   |
   |---> Thread 1 (printMessage function)
   |         |
   |         |---> Prints "Hello from thread with Id: <thread_id_1>"
   |
   |---> Thread 2 (Lambda function)
             |
             |---> Prints "Hello from lambda thread with Id: <thread_id_2>"
   |
   |---> Main Thread continues
             |
             |---> Prints "Hello from main thread with Id: <main_thread_id>"
*/