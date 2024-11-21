#include <iostream>
#include <string>

class LazyString {
private:
    mutable std::string cachedUppercase;
    std::string data;
public:
    LazyString(const std::string& str) : data(str), cachedUppercase(""){}

    std::string getUppercase() const {
        if(cachedUppercase.empty()) {
            for(char c : data) {
                cachedUppercase += std::toupper(c);
            }
        }

        return cachedUppercase;
    }
};

int main()
{
    LazyString str("hello world");
    std::cout << "Uppercase1: " << str.getUppercase() << '\n';
    std::cout << "Uppercase2: " << str.getUppercase() << '\n'; // Cached result used
    
    return 0;
}