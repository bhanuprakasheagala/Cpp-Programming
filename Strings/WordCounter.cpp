#include <iostream>
#include <sstream>

int countWords(const std::string& input){
    std::stringstream ss(input);
    std::string word;
    int wordCount = 0;

    while(ss >> word){
        wordCount++;
    }

    return wordCount;
}

int main(){
    std::string inputString;
    
    std::cout<<"Enter a string: ";
    std::getline(std::cin, inputString);

    int numWords = countWords(inputString);

    std::cout<<"Number of words in the sentence: " << numWords << std::endl;

    return 0;
}
