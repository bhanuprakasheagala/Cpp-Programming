#include <iostream>

// Class Template
template <class T>
class Number {
    private:
        T num; // variable of type T
    public:
        Number(T n) : num(n) {}    // Constructor that's initializing `num` with passed value from calling function

        T getNum() {        // public method to access private data
            return num;  
        }
};

int main(){
    // Create an object of type int
    Number<int> numberInt(5);

    // Create an object of type double
    Number<double> numberDouble(345.45);

    std::cout << "int Number = " << numberInt.getNum() << std::endl;
    std::cout << "double Number = " << numberDouble.getNum() << std::endl;

    return 0;
}