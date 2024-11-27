/*
Streams in C++ use std::streambuf to manage their buffers. A custom stream buffer allows you to control how data is read and
written.
std::streambuf is the low-level component that handles actual data storage and transfer.
Streams like std::cout or std::ifstream delegate their buffering tasks to the streambuf object.
*/

#include <iostream>
#include <fstream>
#include <streambuf>

class DualBuffer : public std::streambuf {
private:
    std::streambuf* consoleBuffer; // Default console buffer
    std::streambuf* fileBuffer;     // File buffer

public:
    DualBuffer(std::streambuf* console, std::streambuf* file) : consoleBuffer(console), fileBuffer(file) {}

    // Override sync() to flush both buffers
    int sync() override {
        if(consoleBuffer->pubsync() == -1 || fileBuffer->pubsync() == -1) {
            return -1;
        }
        return 0;
    }

    // Override overflow() to handle character writes
    int overflow(int c) override {
        if(c == EOF)
            return EOF;
        if(consoleBuffer->sputc(c) == EOF || fileBuffer->sputc(c) == EOF) {
            return EOF;
        }
        return c;
    }
};

int main()
{
    std::ofstream logFile("BuffersDemo.txt");
    DualBuffer dualBuffer(std::cout.rdbuf(), logFile.rdbuf());
    std::ostream dualStream(&dualBuffer);

    dualStream << "This message is logged to both the console and the file\n";

    logFile.close();

    return 0;
}