#include <iostream>

// Define a function wrapper template
template<typename Func, typename... Args>
class FunctionWrapper {
    public:
        // Constructor to initialize the function and it's arguments
        FunctionWrapper(Func fun, Args... arg) : m_func(fun), m_args(arg...) {}

        // Operator () to invoke the wrapped function
        auto operator()() -> decltype(auto){
            return m_func(m_args...);
        }
    private:
        Func m_func;    // Callable Object
        std::tuple<Args...> m_args; // Tuple to store Arguments
};

int main()
{
    // Define the function to be wrapped. In this case, lambda function.
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