#include <iostream>
class IntCell {
    public:
        explicit IntCell(int initialValue = 0) : storedValue(initialValue) {}
        int read() const {
            return storedValue;
        }
        void write(int x) {
            storedValue = x;
        }
    private:
        int storedValue;
};
/*
explicit Constructor : 
All one-parameter constructors should be explicit to avoid behind-the-scenes type conversions.
Otherwise, there are somewhat lenient rules that will allow type conversions without explicit
casting operations.
Example:
IntCell obj; // obj is an IntCell
obj = 37;    // Should not compile : type mismatch

However, C++ has lenient rules. Normally, a one-parameter constructor defines an implicit type
conversion, in which a temporary object is created that makes an assignment compatible. In this
case, the compiler would attempt to convert

obj = 37;

into

IntCell temporary = 37;
obj = temporary;

The construction of the temporary can be performed by using one-parameter construction.

The use of explicit means that a one-parameter constructor cannot be used to generate an
implicit temporary. Thus, since IntCell's constructor is declared explicit, the compiler
will correctly complain that there is a type mismatch.

*/
int main()
{
    IntCell obj(37);
    //obj = 37;
    //obj.write(55);
    std::cout << obj.read() << '\n';

    return 0;
}
