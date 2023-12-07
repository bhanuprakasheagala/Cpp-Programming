#include <iostream>

template<typename T>
class Less_than {
    const T val; // value to compare against
public:
    Less_than(const T& v) :val(v) {}
    bool operator()(const T& x) const { // call operator
        return x < val; 
    }
};

int main(){

    int n = 5;
    std::string str = "Backus";

    // We can define named variables of type `Less_than` for some argument type
    Less_than<int> lti {42};
    Less_than<std::string> lts {"Backur"};

    // We can call such an object, just as we call a function
    bool b = lti(n);  // true if n < 42
    bool l = lts(str); // true if str < "Backut"
    
    return 0;
}