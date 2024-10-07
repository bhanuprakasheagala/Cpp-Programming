/*
Program that reads a text file and counts the number of words in it.
You can also track the frequency of each word and save the results to
another file.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>

int main(){
    std::string inputFilename, wordCountFilename;
    std::cout<<"Name of input text file: "<<std::endl;
    std::cin>>inputFilename;
    std::cout<<"Name of the file to store the frequencies of word count: "<<std::endl;
    std::cin>>wordCountFilename;

    // Open the input file for reading
    std::ifstream inputFile(inputFilename);
    if(!inputFile.is_open()){
        std::cerr<<"Failed to open the input file "<<inputFilename<<std::endl;
        return 1;
    }
    std::string word;
    std::map<std::string, int> wordCount; // To store the word frequencies
    
    // Read the file and count words
    /*
    In this loop, the >> operator is used to read from the inputFile stream. By default, the >> operator reads data separated by
    whitespace characters (such as space, tab, or newline). This means that each time the loop runs, it reads a sequence of characters
    until it encounters a space or any other whitespace character,
    and it stores that sequence of characters in the word variable. These sequences of characters are treated as individual words.
    */
    while(inputFile >> word){
        
        // Convert word to lowercase to ignore case sensitivity
        for(char& c : word){
            c = tolower(c);
        }
        // Remove punctuation
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Increment word count in map
        wordCount[word]++;
    }
    // Close the input file
    inputFile.close();

    // Open the output file  for writing the frequencies
    std::ofstream outputFile(wordCountFilename);
    if(!outputFile.is_open()){
        std::cerr<<"Failed to open the output file "<<wordCountFilename<<std::endl;
        return 1;
    }

    // Write word frequencies to the output file
    for(const auto& pair : wordCount){
        outputFile<< pair.first << ": " << pair.second << std::endl;
    }

    // Close the output file
    outputFile.close();

    std::cout<<"Word count and frequencies saved to "<<wordCountFilename<<std::endl;

    return 0;
}