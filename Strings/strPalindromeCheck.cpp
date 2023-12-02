#include <iostream>
#include <string>
/*
std::string isPalindrome(std::string& input){
    int len = input.length();
    for(int i=0; i<(len/2); i++) {
        if(input[i] != input[len-i-1]) {
            return "No";
        }
    }

    return "Yes";
}
*/
std::string isPalindrome(std::string& input) {
    int l = 0;
    int r = input.length() - 1;
    while(l <= r){
        if(input[l] != input[r]){
            return "No";
        }
        l++;
        r--;
    }
    return "Yes";
}

int main(){
    std::string input;
    std::cout<<"Enter string: "<<std::endl;
    std::getline(std::cin, input);
    std::cout<<"Is "<<input<<" Palindrome? : "<<isPalindrome(input)<<std::endl;
    return 0;
}