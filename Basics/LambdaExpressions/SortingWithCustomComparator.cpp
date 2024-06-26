#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {4,2,5,1,3};

    // Sort in descending order using a lambda expression
    std::sort(numbers.begin(), numbers.end(), [](int a, int b){
        retutn a>b;
    });

    for(int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    
    return 0;
}