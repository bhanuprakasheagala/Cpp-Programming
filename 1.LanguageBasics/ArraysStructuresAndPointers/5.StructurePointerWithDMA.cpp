#include <iostream>

struct Car {
    char brand[50];
    int year;
};

int main()
{
    int n = 3;

    Car* cars = new Car[n]; // Dynamically allocate an array of structures

    // Initialize car details
    for(int i=0; i < n; ++i) {
        std::cout << "Enter brand for car " << i+1 << ": ";
        std::cin >> cars[i].brand;

        std::cout << "Enter year for car " << i+1 << ": ";
        std::cin >> cars[i].year;
    }

    // Access car details
    for(int i=0; i < n; ++i) {
        std::cout << "Car " << i+1 << ": " << cars[i].brand << ", Year: " << cars[i].year << '\n';
    }

    delete[] cars; // Free Dynamically allocated memory

    return 0;
}