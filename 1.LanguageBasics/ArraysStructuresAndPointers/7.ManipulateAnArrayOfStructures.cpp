#include <iostream>

struct Employee {
    int id;
    float salary;
};

int main()
{
    Employee emp[] = {{101, 50000.0}, {102, 60000.0}, {103, 75000.0}};
    Employee* ptr = emp; // Pointer to the first element of the array

    for(int i = 0; i < 3; ++i) {
        std::cout << "Employee ID: " << (ptr + i)->id << ", Salary: " << (ptr + i)->salary << '\n';
    }

    // Accessing elements using pointer arithmetic
    ptr->salary += 10000.0; // Increase salary of first employee
    (ptr + 2)->salary -= 10000.0; // Decrease salary of third employee

    std::cout << "\nUpdated Salaries:\n";
    for(int i = 0; i < 3; ++i) {
        std::cout << "Employee ID: " << (ptr + i)->id << ", Salary: " << (ptr + i)->salary << '\n';
    }

    return 0;
}