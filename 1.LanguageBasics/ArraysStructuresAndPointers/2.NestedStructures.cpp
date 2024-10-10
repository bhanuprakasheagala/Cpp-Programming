#include <iostream>

struct Inner {
    int inner_val;
};

struct Outer {
    int outer_val;
    Inner* inner_ptr;
};

int main()
{
    Inner in = {100};
    Outer out = {200, in};

    Outer* ptr_out = &out;

    // Accessing members through pointers
    std::cout << "Outer value: " << ptr_out->outer_val << '\n';
    std::cout << "Inner value: " << ptr_out->inner_ptr->inner_val << '\n';
    
    return 0;
}