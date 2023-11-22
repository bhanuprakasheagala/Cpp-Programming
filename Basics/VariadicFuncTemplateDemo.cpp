/*
A good way to illustrate the variadic function template
mechanism is to use it in a rewrite of some of the functionality of `printf`
*/

#include <iostream>

void print() {
    std::cout << std::endl;
}

template<typename T> void print(const T& t){
    std::cout << t << std::endl;
}

template<typename First, typename... Rest> void print(const First& first, const Rest&... rest){
    std::cout << first << ", ";
    print(rest...); // recursive call using pack expansion syntax
}

int main(){

    print();  // Calls first overload, prints only new line
    print(1); // Calls second overload

    // these call the third overload, the variadic template, which uses
    // recursion as needed
    print(10,20);
    print(100,200,300,400);
    print("first", 2, "third", 3.14159);

    return 0;
}