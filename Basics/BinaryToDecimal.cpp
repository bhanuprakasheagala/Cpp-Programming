#include <iostream>
#include <string>

int main() {

    std::string input;
    std::cout << "Enter the binary string: ";
    std::getline(std::cin, input);
    std::string num = input;
    int dec_value = 0;
    int base = 1;
    int len = num.length();

    for(int i=len-1; i>=0; --i){
        if(num[i] == '1')
            dec_value += base;
        base *= 2;
    }

    std::cout << "Decimal value of " << input << " is " << dec_value << '\n';
    return 0;
}