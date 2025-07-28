#include <iostream>
#include <string>
#include <format>

struct X {
    std::string str;
    X(std::string_view s) : str {s} {
        std::cout << std::format("X::X({})\n", str);
    }
    ~X() {
        std::cout << std::format("~X::X() for {}\n", str);
    }
};

X glob { "global" };
void g() {
    X xg { "g()" };
}

int main() {
    X *p0 = new X { "p0" };
    [[maybe_unused]] X *p1 = new X{ "p1" }; // Will leak
    X xmain { "main()" };
    g();
    delete p0;

    // Forgot to delete p1
}

/*
NOTES:
The fact that the number of constructors and destructors do not match is a sign that we did something
wrong. More specifically, in this example, we manually created an object (pointed to by p1) with
operator new but never manually destructed that object afterward.

One common source of confusion for programmers unfamiliar with C++ is the distinction between
pointer and pointee. In this program, p0 and p1 are both destructed when reaching the end of their
scope (by the closing brace of the main() function), just as xmain will be. However, since p0 and
p1 point to dynamically allocated objects, the pointees have to be explicitly destructed, something
we did for p0 but (deliberately, for the sake of the example) neglected to do for p1.

What happens to p1’s pointee then? Well, it has been manually constructed and has not been manually
destructed. As such, it floats in memory where no one can access it anymore. This is what people often
call a memory leak: a chunk of memory your program allocated but never deallocated.

Worse than leaking the storage for the X object pointed to by p1, however, is the fact that the pointee’s
destructor will never be called, which can cause all sorts of resource leaks (files not closed, database
connections not closed, system handles not released, and so on). In Chapter 4, Using Destructors, we
will examine how it is possible to avoid such situations and write clean, simple code at the same time.
*/