#include <iostream>

struct Person {
    char name[20];
    int age;
    float height;
};

int main() {
    struct Person people[3] = {
        {"John", 25, 5.9},
        {"Alice", 30, 5.7},
        {"Bob", 24, 6.1}
    };

    struct Person *p = people; // Point to first person
    for(int i = 0; i < 3; ++i) {
        printf("Name: %s, Age: %d, Height: %.1f\n", p->name, p->age, p->height);
        p++; // Move to the next person
    }

    return 0;
}