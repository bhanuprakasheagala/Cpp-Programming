#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outFile("example22.txt");
    if(outFile.is_open()) {
        outFile << "Hello, File!\n";
        outFile.close();
    }
    else {
        std::cerr << "Error opening file!\n";
    }

    std::ifstream inFile("example22.txt");
    if(inFile.is_open()) {
        std::string line;
        while(getline(inFile, line)) {
            std::cout << line << '\n';
        }
        inFile.close();
    }

    return 0;
}