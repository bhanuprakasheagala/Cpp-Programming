// 1. Writing in Normal Write mode
#include <iostream>
#include <fstream>
#include <string>

int main(){
    // By default, it will be opened in normal mode
    // which is ios::out
    std::ofstream myfile("sample.txt");

    myfile << "Hello everyone \n";
    myfile << "This content was being written from a C++ Program";

    return 0;
}


// 2. Writing in Append mode
#include <fstream>
#include<iostream>
#include<string>

int main ()
{
    std::ofstream myfile("sample.txt", std::ios_base::app);
    
    myfile << "\nThis content was appended in the File.";
    return 0;
}


// 3. Writing in Truncate mode
#include <fstream>
#include<iostream>
#include<string>

int main ()
{
    std::ofstream myfile("sample.txt", std::ios_base::trunc);
    
    myfile << "Only this line will appear in the file.";
    return 0;
}