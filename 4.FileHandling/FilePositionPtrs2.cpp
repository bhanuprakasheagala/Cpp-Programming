/*
istream& seekg (streampos pos), this function returns the istream object by changing the position of get pointer to pos.
istream& seekp (streampos pos), this function returns the ostream object by changing the position of put pointer.
We could also overload the seekg() & seekp() by providing an offset. Pointers will move with respect to offsets, 
i.e., ios_base::beg to start from the beginning of the file, ios_base::end to start from the ending of the file, 
ios_base::curr to start from the current positions of the pointer.
The default value of offset is the beginning of the file.
*/

#include <iostream>
#include <fstream>

int main(){
    std::fstream myFile("myfile.txt", std::ios::out);
    myFile<<"123456789";
    myFile.seekp(5); // Now put/write pointer points to index 5(which is 6)
    myFile<<"*";  // Now the content is: 12345*789
    myFile.close();
    myFile.open("myfile.txt", std::ios::app);
    myFile<<"\ntext appended";
    myFile.close();

    myFile.open("myfile.txt", std::ios::in);
    myFile.seekg(3); // Now get/read pointer points to index 3
    std::string line;
    while(myFile.good()){  //reads from current put pointer till end of the file line by line
        std::getline(myFile, line); //becasue getline reads line by line
        std::cout<<line<<std::endl;
    }
    myFile.close();
    return 0;
}