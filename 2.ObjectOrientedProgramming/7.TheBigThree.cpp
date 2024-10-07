#include <iostream>

class IntCell {
    public:
        explicit IntCell(int initialValue = 0);

        IntCell(const IntCell& rhs);
        ~IntCell();
        const IntCell& operator=(const IntCell& rhs);

        int read() const;
        void write(int x);
    
    private:
        int *storedValue;
};

IntCell::IntCell(int initialValue) {
    storedValue = new int(initialValue);
}

IntCell::IntCell(const IntCell& rhs) {
    storedValue = new int(*rhs.storedValue);
}

IntCell::~IntCell() {
    delete storedValue;
}

const IntCell& IntCell::operator=(const IntCell& rhs) {
    if(this != &rhs)
        *storedValue = *rhs.storedValue;
    return *this;
}

int IntCell::read() const {
    return *storedValue;
}

void IntCell::write(int x) {
    *storedValue = x;
}

/*
NOTES:
In C++, Compiler provides default constructor, destructor, copy constructor, and copy assignment operator.
If a class consists of data members that are exclusively primitive types and objects for which the defaults
make sense, the class defaults will usually make sense.Thus a class whose data members are `int`, `double`,
`vector<int>`, `string`, and even `vector<string>` can accept the defaults.

The main problem occurs in class that contains a data member that is a `pointer`. 
Suppose the class contains a single data member that is a pointer. This pointer points at a dynamically
allocated object. The default destructor for pointers does nothing. Furthermore, the copy constructor
and `operator==` both copy not the objects being pointed at, but simply the value of the pointer.
Thus we will simply have two class instances that contain pointers that point to the same object.
This is a so-called `Shallow copy`. Typically, we would expect a `Deep copy`, in which a clone of
the entire object is made. Thus, when a class contains pointers as data members, and deep semantics
are important, we typically must implement the destructor, operator==, and copy constructor ourselves.
*/

int main()
{
    IntCell obj1(2);        // Obj1 = 2
    IntCell obj2 = obj1;    // Obj2 = 2
    IntCell obj3;
    obj3 = obj2;            // Obj3 = 2
    obj1.write(4);          // Obj1 = 4
    std::cout << obj1.read() << " " << obj2.read() << " " << obj3.read() << '\n';

    return 0;
}