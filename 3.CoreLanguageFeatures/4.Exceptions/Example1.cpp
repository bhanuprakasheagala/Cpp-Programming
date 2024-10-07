#include <iostream>
#include <fstream>
#include <exception>

class FileException : public std::exception {
    
    public:
        FileException(const char* message) : msg_(message) {}
        const char* what() const noexcept override {
            return msg_;
        }

    private:
        const char* msg_;
};

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        throw FileException("File not found!\n");
    }

    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if(!file.is_open()) {
        throw FileException("Unable to open file for writing\n");
    }

    file << content;
}

int main()
{
    try {
        writeFile("example.txt", "Hello, world!");
        readFile("example.txt");
    }
    catch(const FileException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}