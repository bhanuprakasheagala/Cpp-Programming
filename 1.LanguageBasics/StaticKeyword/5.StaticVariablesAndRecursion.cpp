#include <iostream>

int sumOfDigits(long n) {
    static int sum = 0; // Only initialized once
    if(n == 0) {
        int result = sum;
        sum = 0; // Reset static variable for future calls
        return result;
    }
    sum += n%10;
    return sumOfDigits(n/10);
}

int main()
{
    long n;
    std::cin >> n;
    std::cout << "Sum of Digits: " << sumOfDigits(n) << '\n';
    
    return 0;
}