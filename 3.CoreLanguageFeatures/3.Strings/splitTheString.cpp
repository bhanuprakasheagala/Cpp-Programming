#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> explode(const std::string& str, const char& c) {
    std::string buff{""};
    std::vector<std::string> vec;
    for(auto n : str) {
        if(n != c)
            buff += n;
        else {
            if(n==c && buff != "") {
                vec.push_back(buff);
                buff = "";
            }
        }

    }
    if(buff != "")
        vec.push_back(buff);

    return vec;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> res{explode(input, ' ')};
    for(const auto& n : res)
        std::cout << n << '\n';

    return 0;
}