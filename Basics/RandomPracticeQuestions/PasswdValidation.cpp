#include <iostream>
#include <cctype>
#include <string>

bool isValidPasswd(const std::string& passwd) {
    bool hasLower = false, hasUpper = false, hasDigit = false;
    
    // Password length should be atleast 6 characters
    if(passwd.size() < 6) {
        return false;
    }

    // Check each character of the password
    for(char ch : passwd) {

        // No spaces or / allowed
        if(ch == ' ' || ch == '/') {
            return false;
        }

        if(isdigit(ch))
            hasDigit = true;
        else if(islower(ch))
            hasLower = true;
        else if(isupper(ch))
            hasUpper = true;
    }

    // All three conditions should be satisfied
    return (hasLower && hasDigit && hasUpper);
}

int main() {
    std::string passwd;
    std::cout << "Enter the password: ";
    std::getline(std::cin, passwd);
    if(isValidPasswd(passwd)) {
        std::cout << "Valid Password\n";
    }
    else {
        std::cout << "Invalid Password, try again!\n";
    }

    return 0;
}