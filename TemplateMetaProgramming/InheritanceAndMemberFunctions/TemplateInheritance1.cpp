#include <iostream>

template <typename T>
class Base {
    public:
        void func() {
            std::cout << "Base: func\n";
        }
};

template <typename T>
class Derived : public Base<T> {
    public:
        void callBase() {
            func();
        }
};

int main()
{
    Derived<int> obj;
    obj.callBase();

    return 0;
}

/*
Output:
TemplateInheritance1.cpp:15:13: error: use of undeclared identifier 'func'

NOTES:
`func` is a so-called non-dependent name because its name does not depend on the
template parameter T. Non-dependent names are looked up and bound at the point of
the template definition. Consequently, the compiler does not look in the form T
dependent base class Base<T>, and there is no name func available outside the class template.
Only dependent names are looked up and bound at the point of template instantiation.

This process is called `Two Phase Lookup`. The first phase is, in particular,
responsible for looking up non-dependent names; the second phase is responsible for
looking up dependent names.

Templates are compiled (at least) twice:
Without Instantiation the template code itself is checked for syntax.
        Eg: Any syntax errors such as ; etc.
At the time of instantiation(when the exact type is known), the template code is checked again
to ensure all calls are valid for that particular type.
        Eg: The template might in turn call to functions which might not be present for that
        particular type.
This is called as Two Phase Lookup.
*/