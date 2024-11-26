#include <iostream>
#include <fstream>

struct Data{
    int id;
    float value;
};

int main()
{
    Data d1 = {1, 3.14};

    // Writing binary data
    std::ofstream outFile("binary.dat", std::ios::binary);
    outFile.write(reinterpret_cast<char*>(&d1), sizeof(d1));
    outFile.close();

    // Reading binary data
    std::ifstream inFile("binary.dat", std::ios::binary);
    Data d2;
    inFile.read(reinterpret_cast<char*>(&d2), sizeof(d2));
    std::cout << "Read Data: " << d2.id << " " << d2.value << '\n';

    return 0;
}