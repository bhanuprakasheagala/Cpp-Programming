/*
A Desk Calculator

*/

enum class Kind : char {
    name, number, end,
    plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign='=',
    lp = '(', rp = ')'
};

struct Token {
    Kind kind;
    std::string string_value;
    double number_value;
};

int noOfErrors;

double error(const std::string& s) {
    noOfErrors++;
    std::cerr << "Error: " << s << '\n';
    return 1;
}

std::map<std::string, double> table;

