#include <iostream>
static int globalCount = 0;

void incr() {
    globalCount++;
}

int main()
{
    incr();
    std::cout << globalCount << '\n'; // Output: 1

    incr();
    std::cout << globalCount << '\n'; // Output: 2

    return 0;
}

/*
Notes:
Static variables can also be used at the file level. When a global variable is declared as static, it has internal linkage,
meaning that the variable is only visible within the file in which it is declared. This is useful for restricting variable scope to a single translation unit.

*/