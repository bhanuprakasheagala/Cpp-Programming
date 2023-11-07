#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string inputFileName, outputFileName;
    std::cin>>inputFileName;
    std::cin>>outputFileName;

    // Open the input file for reading
    std::ifstream inputFile(inputFileName);
    if(!inputFile.is_open()){
        std::cerr<<"Failed to open the input file: "<<inputFileName<<std::endl;
        return 1;
    }

    // Open the output file for writing
    std::ofstream outputFile(outputFileName);
    if(!outputFile.is_open()){
        std::cerr<<"Failed to open the output file: "<<outputFileName<<std::endl;
        inputFile.close(); //Close the input file
        return 1;
    }

    std::string line;
    // Read from the input file and write to the output file
    while(std::getline(inputFile, line)){
        outputFile << line << '\n';
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    std::cout<<"Data copied from "<<inputFileName<<" to "<<outputFileName<<std::endl;

    return 0;
}