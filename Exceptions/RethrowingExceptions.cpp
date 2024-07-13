#include <iostream>
#include <exception>

void function() {
    try {
        throw std::runtime_error("Initial Error..");
    }
    catch(...) {
        std::cout << "Handling and Re-throwing exception!!\n";
        throw; // Re-throw the current exception
    }
}

int main()
{
    try {
        function();
    }
    catch(const std::runtime_error& e) {
        std::cout << "Caught re-thrown exception: " << e.what() << '\n';
    }

    return 0;
}