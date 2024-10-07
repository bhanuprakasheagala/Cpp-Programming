#include <iostream>
#include <string>

class Person {
    std::string name;
    int age;

    public:
        // Constructor with both name and age
        Person(const std::string& n, int a) : name(n), age(a) {
            std::cout << "Person(const std::string&, int)\n"; 
        }

        // Constructor with only name, delegates to other constructor
        Person(const std::string& n) : Person(n, 0) {
            std::cout << "Person(const std::string&)\n";
        }

        // Default constructor, delegates to the constructor with only name
        Person() : Person("Unknown") {
            std::cout << "Person()\n";
        }

        void display() const {
            std::cout << "Name: " << name << ", Age: " << age << '\n';
        }
};

int main()
{
    Person p1;
    p1.display();

    Person p2("Alice");
    p2.display();

    Person p3("Bob", 26);
    p3.display();

    return 0;
}