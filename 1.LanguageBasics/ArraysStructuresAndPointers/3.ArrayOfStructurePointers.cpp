// An array of pointers to structures
#include <iostream>

struct Student {
    char name[50];
    int age;
};

int main()
{
    Student s1 = {"John", 20};
    Student s2 = {"Jane", 22};

    Student* arr[2]; // Array of pointers to structures
    arr[0] = &s1;
    arr[1] = &s2;

    for(int i=0; i < 2; ++i) {
        std::cout << "Student " << i+1 << ": " << arr[i]->name << ", Age: " << arr[i]->age << '\n';
    }

    return 0;
}