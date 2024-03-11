#include <iostream>

// Define a function wrapper template
template<typename Func, typename... Args>
class FunctionWrapper {
    public:
        // Constructor to initialize the function and it's arguments
        FunctionWrapper(Func fun, Args... arg) : m_func(fun), m_args(arg...) {}

        // Operator () to invoke the wrapped function
        auto operator()() -> decltype(auto){
            return std::apply(m_func, m_args);
        }
    private:
        Func m_func;    // Callable Object
        std::tuple<Args...> m_args; // Tuple to store Arguments
};

/*
NOTES:
-> Template Parameters (Func, Args...):
Func represents the type of the callable object (function, lambda, functor, etc.) that we want to wrap.
Args... represents the types of arguments that the callable object takes.

-> Constructor:
The constructor initializes the m_func member variable with the provided callable object fun and the
m_args member variable with the provided arguments arg....
m_args is a std::tuple that stores the arguments passed to the callable object.

-> Operator () Overload:
This operator allows instances of FunctionWrapper to be called as if they were functions themselves.
decltype(auto) is used to deduce the return type of the function call.
Inside the operator(), std::apply is used to expand the arguments stored in the tuple m_args and
apply them to the callable object m_func.
std::apply forwards the arguments in the tuple as arguments to the function m_func.

std::apply allows you to invoke a function with arguments stored in a tuple. It's particularly useful
when you have a tuple of arguments that you want to pass to a function,
but you don't know the exact number of arguments at compile time.

*/

int main()
{
    // Example1: Define the function to be wrapped. In this case, lambda function.
    auto myLambda = [](int x, int y) {
        return x+y;
    };
    
    // Create a function wrapper object with the lamda function and it's arguments
     FunctionWrapper<decltype(myLambda), int, int> wrapperObject(myLambda, 4,5);

    // Invoke the wrapped function and store the result
    auto result = wrapperObject();

    std::cout << "Result: " << result << '\n';
    
    return 0;
}