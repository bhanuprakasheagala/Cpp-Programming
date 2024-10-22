#include <iostream>

void func1() {
    static int count = 0;
    count++;
    std::cout << count << '\n';
}

int main()
{
    func1(); // Output: 1
    func1(); // Output: 2
    func1(); // Output: 3
    func1(); // Output: 4
    
    return 0;
}

/*
Notes:

A static variable inside a function retains its value between function calls. Normally, local variables get destroyed once the function scope ends,
but a static local variable keeps its value across multiple function invocations.
*/