// Example1: Opening/Creating a file using open()
#include <iostream>
#include <fstream>

int main(){
    
    // Create a new object of fstream class, which is a base class of both ifstream and ofstream
    std::fstream new_file;
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;
    // open() creates a new file by setting mode to `out` which allows us to write in our file
    new_file.open(filename, std::ios::out);

    if(!new_file){
        std::cout<<"File creation failed, can't open!";
    }
    else{
        std::cout<<"File named " << filename << " created successfully!\n";
        new_file<<"Writing this data into "<< filename << '\n';  //Writing to newly created file
        new_file.close(); //file closed
    }
    new_file.open(filename, std::ios::in); //Opening file2 in read mode
    if(!new_file){
        std::cout<<"No such file";
    }
    else{   //Read data from file till end of the file
        char ch;
        while(!new_file.eof()){
            new_file>>ch;
            /*
            Once eof gets to the last character it will simply read it for the first time and 
            since it's not the end of the stream, the eof flag will not be set. So while printing
            it will print last character twice as ch still has previous character.
            To avoid this, we break from loop as soon as the last character prints instead of waiting 
            for the last iteration in loop.
            */
            if(new_file.eof())  
                break;
            std::cout<<ch; //printing file data to console
        }
        std::cout<<std::endl;
        new_file.close();
    }

    return 0;
}