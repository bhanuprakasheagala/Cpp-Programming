// 1. Using get method

#include <fstream>
#include <iostream>

int main(){
    std::ifstream myfile;
    myfile.open("sample.txt", std::ios::in); //second parameter is optional as ifstream by default takes in
    // OR std::ifstream myfile("sample.txt");
    if(myfile.is_open()){
        char myChar;
        while(myfile.good()){
            myChar = myfile.get();
            std::cout<<myChar;
        }
    }
    else{
        std::cout<<"file??"<<std::endl;
    }
    return 0;
}

// 2. Using getline method
#include <fstream>
#include <iostream>

int main(){
    std::ifstream myfile("sample.txt"); //ifstream opens in mode
    if(myfile.is_open()){
        std::string line;
        while(myfile.good()){
            std::getline(myfile, line);
            std::cout<< line << std::endl;
        }
    }
    else{
        std::cout<<"File doesn\'t exist"<<std::endl;
    }
    return 0;
}