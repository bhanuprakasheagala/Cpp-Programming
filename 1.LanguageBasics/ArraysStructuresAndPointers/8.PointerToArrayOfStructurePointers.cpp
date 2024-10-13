#include <iostream>

struct Device {
    char name[20];
    int id;
};

int main()
{
    Device d1 = {"Device1", 566};
    Device d2 = {"Device2", 331};

    Device* devices[] = {&d1, &d2}; // Array of pointers to structures
    Device** ptr = devices; // Pointer to an array of pointers

    // Access and modify elements
    std::cout << "Device 1: " << (*ptr)->name << ", ID: " << (*ptr)->id << '\n';
    std::cout << "Device 2: " << (*(ptr+1))->name << ", ID: " << (*(ptr+1))->id << '\n';

    // Modify values via pointer to array of structure pointers
    (*ptr)->id = 502;
    (*(ptr+1))->id = 302;

    std::cout << "\nUpdated Device IDs: \n";
    std::cout << "Device1 ID: " << (*ptr)->id << '\n' << "Device2 ID: " << (*(ptr+1))->id << '\n';
  
    return 0;
}