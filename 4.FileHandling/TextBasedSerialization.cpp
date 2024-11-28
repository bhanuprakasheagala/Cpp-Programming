#include <iostream>
#include <fstream>
#include <string>

struct Person {
    int age;
    double height;
    std::string name;
};

void serializeToJson(const Person& p, const std::string& filename) {
    std::ofstream outFile(filename);
    if(!outFile) {
        std::cerr << "Error opening file for writing\n";
        return;
    }
    outFile << "{\n";
    outFile << "  \"name\": \"" << p.name << "\",\n";
    outFile << "  \"age\": " << p.age << ",\n";
    outFile << "  \"height\": " << p.height << "\n";
    outFile << "}\n";
    outFile.close();
}

Person deserializeFromJson(const std::string& filename) {
    std::ifstream inFile(filename);
    if(!inFile) {
        std::cerr << "Error opening file for reading\n";
        return {};
    }

    Person p;
    std::string line;
    while(getline(inFile, line)) {
        if(line.find("\"name\"") != std::string::npos) {
            size_t start = line.find(": \"") + 3;
            size_t end = line.find("\",");
            p.name = line.substr(start, end - start);
        }
        else if(line.find("\"age\"") != std::string::npos) {
            p.age = std::stoi(line.substr(line.find(": ") + 2));
        }
        else if(line.find("\"height\"") != std::string::npos) {
            p.height = std::stod(line.substr(line.find(": ") + 2));
        }
    }

    return p;
}

int main()
{
    Person original{25, 5.9, "Alice"};
    serializeToJson(original, "person.json");

    Person loaded = deserializeFromJson("person.json");
    std::cout << "Loaded Person: " << loaded.age << " " << loaded.height << " " << loaded.name << "\n";

    return 0;
}