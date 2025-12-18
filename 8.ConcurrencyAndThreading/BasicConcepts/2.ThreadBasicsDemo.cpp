#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start, ull end) {
    for (ull i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        }
    }
}

void findOdd(ull start, ull end) {
    for (ull i = start; i <= end; i++) {
        if (i % 2 != 0) {
            oddSum += i;
        }
    }
}

int main() {
    ull start = 0, end = 1900000000;

    auto start_time = high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    // findEven(start, end); 
    // findOdd(start, end);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Sum of Even Numbers: " << evenSum << std::endl;
    cout << "Sum of Odd Numbers: " << oddSum << std::endl;

    cout << "Time taken: " << duration.count()/1000000 << " seconds" << std::endl;

    return 0;
}