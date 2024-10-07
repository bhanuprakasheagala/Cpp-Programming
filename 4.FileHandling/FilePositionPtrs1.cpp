/*
tellp() returns the current position of put pointer, which is used with output streams while writing the data to the file.
tellg() returns the current position of get pointer which is used with input streams while receiving the data from the file.
*/

#include <iostream>
#include <fstream>

int main(){
    std::ofstream file;
    file.open("myfile.txt", std::ios::out); // Open file in write mode
    std::cout<<"Position of put pointer before writing: "<<file.tellp()<<std::endl;
    file << "Hello Everyone"; // Write on file
    std::cout<<"Position of put pointer after writing: "<<file.tellp()<<std::endl;
    file.close();

    std::ifstream file1;
    file1.open("myfile.txt", std::ios::in); // Open file in read mode
    std::cout<<"Position of get pointer before reading: "<<file1.tellg()<<std::endl;
    int iter = 5;
    while(iter--){
        char ch;
        file1>>ch; // Read from file
        std::cout<<ch;
    }
    std::cout<<"Position of get pointer after reading: "<<file1.tellg()<<std::endl;
    file1.close();
    
    return 0;
}