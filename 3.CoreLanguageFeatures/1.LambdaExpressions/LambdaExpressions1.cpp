/*
an example of a lambda function in C++ to understand the syntax and use. Let us take a list of numbers
greater than 1 and separate the prime numbers from the list.
Also, we will add them to another list using the lambda expression.
*/
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    // list of numbers
    std::vector<int> numbers = {137, 171, 429, 467, 909};

    // list for prime numbers
    std::vector<int> pn = {};

    // Visiting each element of `numbers` and separating prime numbers
    // using lambda expressions
    for_each(numbers.begin(), numbers.end(), [&pn](int x)mutable {
        bool notPrime = false;
        for(int i=2; i<=sqrt(x);i++){
            if(x%i == 0){
                notPrime = true;
                break;
            }
        }
        if(!notPrime)
            pn.push_back(x);
    });
    std::cout << "List of Prime numbers: " << std::endl;
    for(int i : pn) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
    return 0;
}