/*
Program to compare the Byte-Per-Byte Representation of Two Objects
*/

#include <type_traits>
#include <iostream>
#include <cassert>

// Check if a type has unique object representations
bool same_bytes(const char *p0, const char *p1, std::size_t size) {
    for(std::size_t i = 0; i < size; ++i) {
        if(*(p0 + i) != *(p1 + i)) { // Compare byte by byte
            std::cout << "Difference found at byte " << i << ": "
                      << static_cast<int>(*(p0 + i)) << " != "
                      << static_cast<int>(*(p1 + i)) << "\n";
            return false;
        }
    }
    return true;
}

template <class T, class U>
bool same_bytes(const T& a, const U& b) {
    using namespace std;
    static_assert(sizeof a == sizeof b);
    static_assert(has_unique_object_representations_v<T>);
    static_assert(has_unique_object_representations_v<U>);

    return same_bytes(reinterpret_cast<const char*>(&a), reinterpret_cast<const char*>(&b), sizeof a);
}

struct X {
    int x {2}, y{3};
};

struct Y {
    int x {2}, y{3};
};

struct Z {
    int x {3}, y{2};
};

int main() {
    constexpr X x;
    constexpr Y y;
    constexpr Z z;

    assert(same_bytes(x,y));
    std::cout << "X and Y have the same byte representation.\n";

    assert(same_bytes(x,z)); // This will fail as X and Z have different values
    // std::cout << "X and Z have the same byte representation.\n";
}

/*
has_unique_object_representations trait is true for types uniquely defined by their
values, that is, types exempt of padding bits.. That’s sometimes important as C++ does not say what
happens to padding bits in an object, and performing a bit-per-bit comparison of two objects might
yield surprising results. Note that objects of floating point types are not considered uniquely defined
by their values as there are many distinct values that qualify as NaN, or “not a number”.
*/