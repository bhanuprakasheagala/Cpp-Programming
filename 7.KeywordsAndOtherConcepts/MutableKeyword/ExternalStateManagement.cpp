#include <iostream>
#include <fstream>

class Logger {
private:
    mutable std::ofstream fileStream;
public:
    Logger(const std::string& filename) {
        fileStream.open(filename, std::ios::app);
        if(!fileStream.is_open()) {
            throw std::runtime_error("Failed to open file!");
        }
    }

    ~Logger() {
        if(!fileStream.is_open()) {
            fileStream.close();
        }
    }

    void log(const std::string& message) const {
        if(fileStream.is_open()) {
            fileStream << message << '\n';
        }
    }

};

int main()
{
    try{
        Logger logger("Log.txt");
        logger.log("Logging a message....");
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}