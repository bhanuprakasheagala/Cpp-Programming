#include <iostream>

// Function Object Class
template <typename T>
class myFunctor {
    public:
        myFunctor(T value) : data(value) {}

        // Overloading the function call operator
        T operator()(T x) const {
            return data * x;
        }
    private:
        T data;
};

int main() {

    // Instantiate the function object with int type
    myFunctor<int> intFunctor(5);

    // Use the Function object like a function
    int intResult = intFunctor(3);
    std::cout << "Result: " << intResult << std::endl;

    // Instantiate the function object with double type
    myFunctor<double> doubleFunctor(3.456);

    // Use the Function object like a function
    double doubleResult = doubleFunctor(45.3467);
    std::cout << "Result: " << doubleResult << std::endl;

    return 0;

}