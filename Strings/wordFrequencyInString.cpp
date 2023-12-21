#include <iostream>
#include <sstream>
#include <string>
#include <map>

int main() {

    std::string str;
    std::getline(std::cin, str);

    std::stringstream obj(str);
    
    std::map<std::string,int> freq;

    std::string buff;

    while(obj >> buff) {
        freq[buff]++;
    }

    for(auto& it : freq){
        std::cout << it.first << " " << it.second << '\n';
    }

    return 0;
}