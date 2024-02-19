#include <iostream>
#include <string>

std::string replaceWord(std::string& sentence, const std::string& oldWord, const std::string& newWord) {
    
    // Find the position of the old world in the sentence
    size_t pos = sentence.find(oldWord);

    // If the old word is not found, return the original sentence
    if(pos == std::string::npos) {
        return sentence;
    }

    // Replace the old word with the new word
    sentence.replace(pos, oldWord.length(), newWord);

    return sentence;
}

int main()
{
    std::string sentence, oldWord, newWord;

    std::cout << "Enter the sentence: ";
    std::getline(std::cin, sentence);

    std::cout << "Enter the word to replace: ";
    std::cin >> oldWord;
    std::cout << "Enter the new word: ";
    std::cin >> newWord;

    std::string newSentence = replaceWord(sentence, oldWord, newWord);

    std::cout << "Modified sentence: " << newSentence << '\n';
    return 0;
}