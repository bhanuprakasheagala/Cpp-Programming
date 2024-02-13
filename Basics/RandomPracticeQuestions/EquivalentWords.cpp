/*
Rahul is copying words from his adjacent students during an exam.
However, he wants to avoid detection, so he rearranges the letters within the words while keeping
the letters constant. In other words, he interchanges the positions of letters in the words.

Your task is to determine if a given pair of words are equivalent according to Rahul's criteria.
Two words are considered equivalent if they contain the same letters in the same quantities,
but the positions of the letters are rearranged.

Write a program that takes two words as input and determines if they are equivalent according
to Rahul's criteria.
*/
#include <iostream>
#include <algorithm>
#include <string>

bool areEquivalentWords(std::string& word1, std::string& word2) {
    if(word1.length() != word2.length())
        return false;

    // Sort the charactes in both the words
    std::sort(word1.begin(), word1.end());
    std::sort(word2.begin(), word2.end());

    return word1 == word2;
}

int main()
{
    std::string word1, word2;
    std::cout << "Enter Word1: ";
    std::cin >> word1;
    std::cout << "Enter Word2: ";
    std::cin >> word2;

    if(areEquivalentWords(word1, word2)) {
        std::cout << "Words are equivalent\n";
    }
    else {
        std::cout << "Words are not equivalent\n";
    }
    return 0;
}