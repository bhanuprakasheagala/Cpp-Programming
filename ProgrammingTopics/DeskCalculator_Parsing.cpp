#include <iostream>
#include <sstream>
#include <map>
#include <cctype>
#include <string>

/// @brief Enum to represent different kinds of tokens
/// This enum defines the various kinds of tokens that can be encountered in the input.
/// It includes tokens for names, numbers, operators, parentheses, assignment, and special commands.
/// How to use: Kind::name, Kind::number, Kind::plus, etc.
enum class Kind : char {
    name, number, end,
    plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=',
    lp = '(', rp = ')'
};

/// @brief Struct to represent a token
/// This struct holds information about a token, including its kind, string value (for names),
/// and numeric value (for numbers).
/// How to use: Token t{Kind::number, "", 3.14}; Token t{Kind::name, "variable", 0};
struct Token {
    Kind kind;
    std::string string_value;
    double number_value;
};

int noOfErrors; // Counter for tracking errors

/// @brief Function to handle errors and report messages
/// @param s Error message string
/// @return Always returns 1
/// This function increments the error counter, prints the error message to standard error,
/// and returns 1. It is used throughout the program to handle error situations.
/// How to use: return error("Error message");
double error(const std::string& s) {
    noOfErrors++;
    std::cerr << "Error: " << s << '\n';
    return 1;
}

/// @brief Symbol table to store variable names and their values
/// This map associates variable names (strings) with their corresponding values (doubles).
/// It is used to store and retrieve variable values during expression evaluation.
/// How to use: table["variable_name"] = value; double val = table["variable_name"];
std::map<std::string, double> table;


double expr(bool get);
double term(bool get);
double prim(bool get);

/// @brief Class to manage the stream of tokens
/// This class reads characters from an input stream and converts them into tokens.
/// It supports setting the input stream, getting the next token, and managing ownership
/// of the input stream.
/// How to use: Token_stream ts{std::cin}; Token t = ts.get();
/// You can also set a different input stream using ts.set_input(new std::istringstream{"input.txt"});
class Token_stream {
public:
    Token_stream(std::istream& is) : ip{&is}, owns{false} {} // Initialize with a reference to an istream
    Token_stream(std::istream* p) : ip{p}, owns{true} {} // Initialize with a pointer to an istream

    ~Token_stream() {
        close();
    }

    Token get(); // Get the next token by peeking into the input stream. This fu

    /// @brief Return the current token
    /// @return The current token
    /// This function returns the current token stored in the Token_stream object.
    /// How to use: Token t = ts.current();
    Token current() {
        return ct;
    }

    /// @brief Set input from a reference to an istream
    /// @param s Reference to an istream (e.g., cin)
    /// This function sets the input stream for the Token_stream object. If the Token_stream
    /// object owns the current input stream, it will be deleted before setting the new stream.
    /// How to use: ts.set_input(std::cin);
    void set_input(std::istream& s) {
        close();
        ip = &s;
        owns = false;
    }

    /// @brief Set input from a pointer to an istream
    /// @param p Pointer to an istream (e.g., file stream)
    /// This function sets the input stream for the Token_stream object. If the Token_stream
    /// object owns the current input stream, it will be deleted before setting the new stream.
    /// How to use: ts.set_input(new std::istringstream{"input.txt"});
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

/// @brief Get the next token from the stream
/// @return The next token
/// This function reads characters from the input stream, skipping whitespace,
/// and constructs tokens based on the characters read. It handles numbers, names,
/// operators, and special characters.
/// How to use: Token t = ts.get();
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
                ct.string_value = ch; // Start with the first character

                // Read the rest of the name (alphanumeric characters)
                while (ip->get(ch) && std::isalnum(ch)) {
                    ct.string_value += ch;
                }

                // Put back the last character read that is not part of the name into the stream
                ip->putback(ch);
                return ct = {Kind::name, ct.string_value}; // Return the name token
            }
            error("bad token");
            return ct = {Kind::print}; // Return a print token on error
    }
}

/// @brief Parse and evaluate an expression
/// @param get Boolean indicating whether to get the next token
/// @return The evaluated result of the expression
/// This function parses and evaluates an expression, which consists of terms
/// combined with addition and subtraction. It uses the term() function to evaluate
/// individual terms.
/// How to use: double result = expr(true);
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

/// @brief  Parse and evaluate a term
/// @param get Boolean indicating whether to get the next token
/// @return The evaluated result of the term
/// This function parses and evaluates a term, which consists of primary expressions
/// combined with multiplication and division. It uses the prim() function to evaluate
/// individual primary expressions.
/// How to use: double result = term(true);
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

/// @brief Parse and evaluate a primary expression
/// @param get Boolean indicating whether to get the next token
/// @return The evaluated result of the primary expression
/// This function parses and evaluates a primary expression, which can be a number,
/// a variable name (with optional assignment), or a parenthesized expression.
/// It handles getting the next token if indicated by the 'get' parameter.
/// How to use: double result = prim(true);

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

/// @brief Calculate and process input expressions
/// This function continuously reads and evaluates expressions from the input stream.
/// It handles end-of-input and print commands, and outputs the results of evaluated expressions.
/// How to use: calculate();
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

/// @brief Main function to run the desk calculator
/// @param argc Argument count
/// @param argv Argument vector
/// @return Number of errors encountered
/// This is the main function that initializes the calculator, sets up predefined variables,
/// and starts the calculation process. It handles command-line arguments for input sources.
/// How to use: Compile and run the program, optionally providing an input file as an argument.
int main(int argc, char* argv[]) {
    switch (argc) {
        case 1:
            break; // Use standard input because no file is provided
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

/*
Notes on the code and code flow:
1. Token and Kind: The Token struct and Kind enum are used to represent different types of tokens in the input stream, such as numbers, operators, and variable names.
2. Token_stream Class: This class manages the input stream and provides functionality to read tokens from the stream. It supports setting the input source and handles ownership of the input stream.
3. Parsing Functions: The expr, term, and prim functions implement a recursive descent parser to evaluate expressions based on operator precedence. They handle addition, subtraction, multiplication, division, and parentheses.
4. Error Handling: The error function is used to report errors and increment an error counter. It is called whenever an error is encountered during parsing or evaluation.
5. Symbol Table: The table map stores variable names and their corresponding values, allowing for variable assignment and retrieval.
6. Main Function: The main function initializes the calculator, sets up predefined variables, and starts the calculation process. It handles command-line arguments for input sources.
7. Input Handling: The program can read from standard input or from a file specified as a command-line argument.
8. Output: The results of evaluated expressions are printed to standard output, and errors are printed to standard error.
9. Memory Management: The Token_stream class ensures proper memory management by deleting the input stream if it owns it, preventing memory leaks.
10. Usage: To use the calculator, compile the program and run it, optionally providing an input file as an argument. The calculator will read expressions, evaluate them, and print the results.
nction is called by expr(), term(), and prim() to get the next token.

Demo Input and Ouputs:
Input:
    1 + 2;
    3 * (4 + 5);
    x = 10;
    y = x * 2;
    y + 5;
    pi * 2;
    e + 1;
    z; // Undefined variable
    10 / 0; // Division by zero
    (1 + 2; // Missing closing parenthesis
    5 + * 3; // Invalid expression
    ;
Output:
3
27
25
6.28319
3.71828
Error: primary expected
Error: divide by zero
Error:  ')' expected
Error: primary expected
Error: primary expected
Error: primary expected
Error: primary expected
*/