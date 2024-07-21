/*
If a return type depends on template parameters, the simplest and best approach to deduce the
return type is to let the compiler find out(Possible since C++14).

The use of auto for the return type without a corresponding trailing return type (which would be introduced
with a -> at the end) indicates that the actual return type must be deduced from the return statements in the
function body. Of course, deducing the return type from the function body has to be possible.
Therefore, the code must be available and multiple return statements have to match.
*/

#include <iostream>

template<typename T1, typename T2>
auto max(T1 a, T2 b){
    return a < b ? b : a;
}

int main()
{
    int a = 5, b = 6;
    float p = 7.8, q = 8.9;
    std::cout << max(p, q) << '\n';
    std::cout << max(a, b) << '\n';

    return 0;
}