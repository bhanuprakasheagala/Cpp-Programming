/******************************************************************************

The function print_reversed() is called from main() repeatedly but with different typed arguments, 
all of which are resolved at compile-time and are implicitly convertible to std::string_view.
*******************************************************************************/
#include <iostream>
#include <string>
#include <string_view>

void print_reversed(std::string_view sv) {
    for(auto iter = crbegin(sv); iter != crend(sv); ++iter) {
        std::cout << *iter;
    }
    std::cout << '\n';
}

int main()
{
    const char* s1 = "Elf";
    char s2[] = "Dwarf";
    std::string s3 = "Hobbit";
    std::string_view s4 = "Orc";
    
    print_reversed(s1);
    print_reversed(s2);
    print_reversed(s3);
    print_reversed(s4);
    print_reversed("Man");
    
    return 0;
}
