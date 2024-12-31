#include <iostream>

class Secret {
private:
    const int secret = 100;
public:
    void printSecret() {
        std::cout << "Secret Number: " << secret << '\n';
    }
};

int main() {
    Secret s;
    s.printSecret();
    
    int* ptr = reinterpret_cast<int*>(&s);
    *(ptr + 0) = 200;
    
    s.printSecret();
    
    return 0;
}