/*
Write a Singleton class to find vowels from a string and their indices
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <mutex>

class VowelFinder {
private:
    static VowelFinder* instance;
    static std::mutex mtx;
    
    VowelFinder() {
        std::cout << "Private constructor to prevent instantiation\n";
    }
    
public:
    static VowelFinder* getInstance() {
        if(instance == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            instance = new VowelFinder();
        }
        
        return instance;
    }
    
    void findVowelsAndIndexes(const std::string& str) {
        std::vector<std::pair<char, int>> vowels;
        
        for(int i=0; i<str.length(); ++i) {
            char c = tolower(str[i]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels.push_back({str[i], i});
            }
        }
        
        if(!vowels.empty()) {
            std::cout << "Vowels found in the string and their indices:\n";
            for(auto& vowel : vowels) {
                std::cout << "Vowel: " << vowel.first << ", Index: " << vowel.second << '\n'; 
            }
        }
        else {
            std::cout << "No vowels found in the string\n";
        }
    }
};

VowelFinder* VowelFinder::instance = nullptr;
std::mutex VowelFinder::mtx;

int main() {
    std::string str;
    
    std::cout << "Enter a string:\n";
    std::getline(std::cin, str);
    
    VowelFinder* vf = VowelFinder::getInstance();
    vf->findVowelsAndIndexes(str);
    
    return 0;
}

/*
Output:
Enter a string:
Get the vowels and their indices
Private constructor to prevent instantiation
Vowels found in the string and their indices:
Vowel: e, Index: 1
Vowel: e, Index: 6
Vowel: o, Index: 9
Vowel: e, Index: 11
Vowel: a, Index: 15
Vowel: e, Index: 21
Vowel: i, Index: 22
Vowel: i, Index: 25
Vowel: i, Index: 28
Vowel: e, Index: 30
*/
