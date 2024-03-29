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

/*
NOTES:-

Most implementations that incorporate variadic function templates use recursion of some form,
but it's slightly different from traditional recursion. Traditional recursion involves a function
calling itself by using the same signature. (It may be overloaded or templated, but the same signature
is chosen each time.) Variadic recursion involves calling a variadic function template by using differing
(almost always decreasing) numbers of arguments, and thereby stamping out a different signature every time.
A "base case" is still required, but the nature of the recursion is different.
*/