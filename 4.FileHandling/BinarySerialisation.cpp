#include <iostream>
#include <fstream>
#include <string>

struct Person {
    int age;
    double height;
    char name[20];
};

void serialize(const Person& p, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if(!outFile) {
        std::cerr << "Error opening file for writing\n";
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
    outFile.close();
}

void deserialize(Person& p, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if(!inFile) {
        std::cerr << "Error opening file for reading\n";
        return;
    }
    inFile.read(reinterpret_cast<char*>(&p), sizeof(Person));
    inFile.close();
}

int main()
{
    Person original{25, 5.9, "Alice"};
    serialize(original, "person.dat");

    Person loaded{};
    deserialize(loaded, "person.dat");

    std::cout << "Loaded Person: " << loaded.age << " " << loaded.height << " " << loaded.name << '\n';

    return 0;
}