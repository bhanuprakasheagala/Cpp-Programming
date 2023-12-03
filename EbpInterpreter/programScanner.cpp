#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

#include <stdexcept>

class EbpInterpreter{
    public:
        EbpInterpreter(int argc, char* argv[]) : argc(argc), argv(argv){}

        void start() {
            try{
                if(argc > 1){
                    std::cout << "Usage: ebp [script]" << std::endl;
                    exit(64); /*For exit codes, I’m using the conventions defined in the UNIX “sysexits.h” header*/
                }
                else if(argc == 1) {
                    runFile(argv[0]);
                }
                else{
                    runPrompt();
                }
            }
            catch(const std::exception& e){
                std::cerr << "Error: " << e.what() << std::endl;
                exit(1);
            }
        }
    private:
        int argc;
        char** argv;

        void runFile(const std::string& path) {
            try {
                std::ifstream file(path, std::ios::binary);
                if(!file.is_open()) {
                    throw std::ios_base::failure("Unable to open file..\n");
                }
                std::stringstream buffer;
                buffer << file.rdbuf();
                std::string content = buffer.str();

                run(content);
            }
            catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        void runPrompt(){
            try {
                std::string inputline;
                while(true){
                    std::cout << "> ";

                    if(!std::getline(std::cin, inputline)) {
                        if(std::cin.eof())
                            break;
                        else{
                            throw std::runtime_error("Error reading input..\n");
                        }
                    }
                    if(inputline.empty()) {
                        continue;
                    }

                    run(inputline);
                }
            }
            catch(const std::exception& e) {
                std::cerr << "Error. " << e.what() << std::endl;
            }
        }

        void run(const std::string& inputSource) {
            std::istringstream sourceStream(inputSource);
            Scanner scanner;
            std::vector<Token> tokens = scanner.scanTokens();

            for(const auto& token : tokens) {
                std::cout << token << std::endl;
            }
        }
};



int main(int argc, char* argv[]) {
    EbpInterpreter ei(argc, argv);
    ei.start();

    return 0;
}