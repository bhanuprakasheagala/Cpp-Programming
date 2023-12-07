#include <iostream>
#include <string>
#include <vector>
#include <list>

template<typename T>
class Less_than {
    const T val; // value to compare against
public:
    Less_than(const T& v) :val(v) {}
    bool operator()(const T& x) const { // call operator
        return x < val; 
    }
};

// Count the occurrences of values for which a predicate returns true
template<typename C, typename P>
int count(const C& c, P predicate){
    int cnt = 0;
    for(const auto& x : c)
        if(predicate(x))
            ++cnt;
    return cnt;
}

// A Predicate is something that we can invoke to return `true` or `false`

// `Less_than<int>{x}` constructs an object for which the call operator compares
// to the `int` called `x`

// `Less_than<std::string>{s}` constructs an object that compares to the 
// `std::string` called `s`

// The function objects carry the value to be compared against with them,
// we don't have to write a separate function for each value(and each type), and we
// dont' have to introduce global variables.
void fun(const std::vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s){
    std::cout << "Number of values less than " << x << ": " << count(vec, Less_than<int>{x}) << '\n';
    std::cout << "Number of values less than " << s << ": " << count(lst, Less_than<std::string>{s}) << '\n';
}

int main() {

    std::vector<int> vec;
    for(int i=0; i<5; ++i)
        vec.push_back(i+1);

    std::list<std::string> lst = {"Abc", "Def", "Ghi", "Jkl"};

    int x = 3;
    std::string s = "Jkl";

    fun(vec, lst, x, s);

    return 0;
}