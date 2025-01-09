#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
int counter = 1;
const int MAX = 20;

void print_even() {
    while(counter <= MAX) {
        std::unique_lock<std::mutex> lock(mtx);
        
        cv.wait(lock, [](){
            return counter%2 == 0;
        });
        
        if(counter <= MAX) {
            std::cout << "Even: " << counter << '\n';
            ++counter;
        }
        
        cv.notify_all();
    }
}

void print_odd() {
    while(counter <= MAX) {
        std::unique_lock<std::mutex> lock(mtx);
        
        cv.wait(lock, []() {
            return counter%2 != 0;
        });
        
        if(counter <= MAX) {
            std::cout << "Odd: " << counter << '\n';
            ++counter;
        }
        cv.notify_all();
    }
}

int main() {
    std::thread even_thread(print_even);
    std::thread odd_thread(print_odd);
    
    // Start the threads
    odd_thread.join();
    even_thread.join();
    
    return 0;
    
}


/*
Notes :-

This C++ code is a multithreading program that uses synchronization mechanisms such as a `mutex` and a `condition_variable` to print even and odd numbers in sequence from 1 to 20. Here’s a step-by-step breakdown of how it works:

Key Concepts Used:
1.`std::mutex mtx`: A mutex used to protect shared data (`counter`) between the threads.
2.`std::condition_variable cv`: A condition variable to control the synchronization between threads. It helps manage which thread can proceed based on the value of `counter`.
3.`counter`: A shared variable initialized to 1, which will hold the current number to be printed. The threads print numbers sequentially, either odd or even, depending on its value.
4.`MAX`: A constant that determines the maximum number up to which numbers will be printed (in this case, 20).

Threads:
-`print_odd` thread: Prints odd numbers.
-`print_even` thread: Prints even numbers.

Synchronization:
The threads are synchronized such that:
- The `print_odd` thread prints only when `counter` is odd.
- The `print_even` thread prints only when `counter` is even.
- After printing, the thread increments the `counter`, notifies the other thread, and waits for the condition variable to signal it to proceed again.

Detailed Explanation of Code:

1. Main function:
   - Two threads are created: `even_thread` for printing even numbers and `odd_thread` for printing odd numbers.
   - `odd_thread.join()` and `even_thread.join()` ensure that the main thread waits for both threads to finish before exiting.

2. The `print_odd` function:
   - The thread waits until `counter` is odd. The `cv.wait` function uses a lambda condition (`counter%2 != 0`) to make sure it proceeds only when `counter` is odd.
   - Once `counter` is odd, it prints the current value of `counter` and increments `counter`.
   - After printing, the thread calls `cv.notify_all()` to notify the other thread that it can proceed.

3. The `print_even` function:
   - Similarly, the `print_even` thread waits until `counter` is even (`counter%2 == 0`).
   - When `counter` is even, it prints the value and increments `counter`.
   - After printing, it notifies the other thread to proceed.

Execution Flow:
- Initially, `counter` is 1, and the `print_odd` thread will be the first to proceed because `counter` is odd.
- After printing the odd number, `print_odd` increments `counter` to 2, and notifies `print_even` to start.
- `print_even` now checks the condition (`counter%2 == 0`), proceeds, and prints the even number.
- This alternation continues until `counter` exceeds `MAX` (20).

Thread Synchronization in Detail:
- `cv.wait(lock, condition)`:
  - The thread locks the mutex and then waits for the condition to become true.
  - If the condition is not met (i.e., if the counter is not the expected type, odd or even), the thread releases the lock and puts itself to sleep until it's notified.
  
- `cv.notify_all()`:
  - After printing a number, the thread notifies all threads waiting on the condition variable (`cv`) that the state has changed, and other threads might now be able to proceed.

Summary of Output:
The output alternates between printing odd and even numbers in the following sequence:
```
Odd: 1
Even: 2
Odd: 3
Even: 4
...
Odd: 19
Even: 20
```

Key Points:
- The two threads synchronize using `std::mutex` to ensure mutual exclusion and avoid race conditions while accessing the shared `counter` variable.
- `std::condition_variable` allows the threads to communicate and coordinate which thread should print next based on whether `counter` is odd or even.
- The program ensures that odd and even numbers are printed in sequence without overlap.

*/
