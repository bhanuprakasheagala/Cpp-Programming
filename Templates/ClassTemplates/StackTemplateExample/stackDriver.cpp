#include "stackImplementation.hpp"
#include <string>
#include <iostream>


int main()
{
    Stack<int>          numStack;
    Stack<std::string>  strStack;

    numStack.push(7);
    std::cout << "Num Stack: " << numStack.top() << '\n';

    strStack.push("Hello");
    std::cout << "String Stack: " << strStack.top() << '\n';
    strStack.pop();

    return 0;
}