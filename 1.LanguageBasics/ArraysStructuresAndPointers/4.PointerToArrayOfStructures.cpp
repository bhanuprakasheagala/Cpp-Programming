#include <iostream>

struct Book {
    char title[50];
    float price;
};

int main()
{
    Book library[] = {{"A Tale of two cities", 342.56}, {"Journey to the depths", 452.23}, {"The Reader", 397.89}};
    Book (*ptr)[3] = &library; // Pointer to array of 3 structures

    for(int i = 0; i < 3; ++i) {
        std::cout << "Title: " << (*ptr)[i].title << ", Price: " << (*ptr)[i].price << '\n';
    }
    
    return 0;
}