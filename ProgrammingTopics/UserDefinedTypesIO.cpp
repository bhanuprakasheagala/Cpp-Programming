// Program to demonstrate I/O of User-Defined Types
#include <iostream>
#include <string>
// `iostream` library allows programmers to define I/O for their own types.

// For example, Consider a simple type `Entry` that we might use to represent entries
// in a telephone book:

struct Entry {
    std::string name;
    int number;
};
// We can define a simple output operator to write an `Entry` using a
// `{"name", number}` format.
std::ostream& operator<<(std::ostream& os, const Entry& e){
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

// The corresponding input operator is more complicated because it has
// to check for correct formatting and deal with errors

std::istream& operator>>(std::istream& is, Entry& e) {
    // read `{"name", number}` pair. Note: formatted with
    // `{" ",`  and  `}`

    char c1,c2;
    if( is>>c1 && c1=='{' && is>>c2 && c2 == '"' ) {   // start with a {"
        std::string name; // the default value of the string is the empty string: "" 
        while(is.get(c1) && c1 != '"')
            name += c1; // anything before a closing " is a part of the name
        // OR the above two lines can be replaced by the following line
      //std::getline(is, name, '"');              // read the name until a double quote
        if( is>>c1 && c1 == ',') {
            int number;
            if( is>>number>>c1 && c1 == '}'){  // read the `number` and a `}`
                e.name = name;
                e.number = number;  // assign to the entry
                return is;
            }
        }
    }
    is.setstate(std::ios_base::failbit);
    return is;
}

int main(){
    
    Entry ee;
    std::cin>>ee;
    std::cout << ee <<'\n';

    return 0;
}
