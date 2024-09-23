#include <iostream>
#include <sstream>
#include <map>
#include <cctype>
#include <string>

// Enum to represent different kinds of tokens
enum class Kind : char {
    name, number, end,
    plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=',
    lp = '(', rp = ')'
};

// Struct to represent a token
struct Token {
    Kind kind;
    std::string string_value;
    double number_value;
};

int noOfErrors; // Counter for tracking errors

// Function to handle errors and report messages
double error(const std::string& s) {
    noOfErrors++;
    std::cerr << "Error: " << s << '\n';
    return 1;
}

std::map<std::string, double> table; // Variable storage

double expr(bool get);
double term(bool get);
double prim(bool get);

// Class to manage the stream of tokens
class Token_stream {
public:
    Token_stream(std::istream& is) : ip{&is}, owns{false} {}
    Token_stream(std::istream* p) : ip{p}, owns{true} {}

    ~Token_stream() {
        close();
    }

    Token get(); // Get the next token
    Token current() {
        return ct;
    }
    void set_input(std::istream& s) {
        close();
        ip = &s;
        owns = false;
    }
    void set_input(std::istream* p) {
        close();
        ip = p;
        owns = true;
    }

private:
    std::istream* ip;
    bool owns;
    Token ct{Kind::end};

    void close(){
        if(owns){
            delete ip;
        }
    } // Close the input stream
};

Token_stream ts{std::cin}; // Token stream object with default input from cin

// Get the next token from the stream
Token Token_stream::get() {
    char ch;

    do {
        // Skip whitespaces and read until a non-whitespace character is found
        if (!ip->get(ch)) {
            return ct = {Kind::end}; // End of input
        }
    } while (ch != '\n' && std::isspace(ch));

    switch (ch) {
        // Check for specific characters and return corresponding tokens
        case ';':
        case '\n':
            return ct = {Kind::print};
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return ct = {static_cast<Kind>(ch)};
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            // If a digit or dot is encountered, read the number and return the token
            ip->putback(ch);
            *ip >> ct.number_value;
            ct.kind = Kind::number;
            return ct;
        default:
            if (std::isalpha(ch)) {
                // If an alphabetic character is encountered, read the name and return the token
                ct.string_value = ch;
                while (ip->get(ch) && std::isalnum(ch)) {
                    ct.string_value += ch;
                }
                ip->putback(ch);
                return ct = {Kind::name, ct.string_value};
            }
            error("bad token");
            return ct = {Kind::print};
    }
}

// Functions to parse expressions
// Parse and evaluate an expression
double expr(bool get) {
    double left = term(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

// Parse and evaluate a term
double term(bool get) {
    double left = prim(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::div:
                if (auto d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by zero\n");
            default:
                return left;
        }
    }
}

// Parse and evaluate a primary expression
double prim(bool get) {
    if (get)
        ts.get();
    switch (ts.current().kind) {
        case Kind::number:
            // Return the number value and get the next token
            {
                double v = ts.current().number_value;
                ts.get();
                return v;
            }
        case Kind::name:
            // Handle variable names and assignments
            {
                double& v = table[ts.current().string_value];
                if (ts.get().kind == Kind::assign) {
                    v = expr(true);
                }
                return v;
            }
        case Kind::lp:
            // Handle parentheses
            {
                auto e = expr(true);
                if (ts.current().kind != Kind::rp) {
                    return error(" ')' expected ");
                }
                void (ts.get());
                return e;
            }
        default:
            return error("primary expected ");
    }
}

// Function to continuously read and evaluate expressions
void calculate() {
    for (;;) {
        ts.get();
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        std::cout << expr(false) << '\n';
    }
}

// Main function
int main(int argc, char* argv[]) {
    switch (argc) {
        case 1:
            break;
        case 2:
            // Set input source to the given file
            ts.set_input(new std::istringstream{argv[1]});
            break;
        default:
            error("Too many arguments\n");
            return 1;
    }

    // Predefined variables
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    // Start the calculation
    calculate();

    // Return the number of errors
    return noOfErrors;
}