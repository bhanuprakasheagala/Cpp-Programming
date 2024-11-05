#include <iostream>
#include <vector>

class MyClass {
private:
    std::vector<int> numbers;
public:
    // Constructor with a lambda to initialize the vector
    MyClass(int size, int init_value) 
    : numbers(
        [size, init_value]() -> std::vector<int> {
            std::vector<int> temp(size, init_value);
            for(int i=0; i<size; ++i) {
                temp[i] += i;
            }
            return temp;
        }
        () // Immediately Call the lambda, here there is no name and no parameters. And we don't mention return type
    )
    {}


    // Function to print the vector
    void print() const {
        for(int num : numbers) {
            std::cout << num << '\n';
        }
        std::cout << '\n';
    }
};

int main()
{
    MyClass obj(5, 10);
    obj.print();
    
    return 0;
}