#include <iostream>
#include <vector>
#include <string>

// Base class Person
class Person {
    protected:
        std::string name;
        int age;
    public:
        Person(std::string n, int a) : name(n), age(a) {};

        virtual void show() const {
            std::cout << "Name: " << name << ", Age: " << age << '\n';
        }
        virtual std::string getRole() const = 0; // Pure virtual function
};

// Participant class
class Participant : public virtual Person {
    public:
        Participant(std::string n, int a) : Person(n, a) {};

        void show() const override {
            std::cout << "Participant: ";
            Person::show();
        }

        std::string getRole() const override {
            return "Participant";
        }
};

// Organizer class
class Organizer : public virtual Person {
    public:
        Organizer(std::string n, int a) : Person(n, a) {};

        void show() const override {
            std::cout << "Organizer: ";
            Person::show();
        }

        std::string getRole() const override {
            return "Organizer";
        }
};

// Event class
class Event {
    private:
        std::string title;
        std::string organizerName;

    public:
        Event(std::string t, std::string orgName) : title(t), organizerName(orgName) {};

        void show() const {
            std::cout << "Event title: " << title << ", Organized by: " << organizerName << '\n';
        }
};

// Multiple inheritance : Person can be both Participant and Organizer
class BothRoles : public Participant, public Organizer {
    public:
        BothRoles(std::string n, int a) : Person(n, a), Participant(n, a), Organizer(n, a) {}

        void show() const override {
            std::cout << "Both Roles(Participant and Organizer): ";
            Person::show();
        }

        std::string getRole() const override {
            return "BothRoles";
        }
};

// Function to display role and user details
void displayRoleAndDetails(const Person* person) {
    std::cout << "Role: " << person->getRole()<< '\n';
    person->show();
}

int main()
{
    // Create Participants, Organizers, and BothRoles instances
    Participant p1("Alice", 24);
    Organizer o1("Bob", 30);
    BothRoles br1("Charlie", 29);

    // Store pointers in a list
    std::vector<Person*> users = {&p1, &o1, &br1};

    // Display each user's role and details
    for(const auto& user : users) {
        displayRoleAndDetails(user);
        std::cout << '\n';
    }

    // Creating events
    Event e1("Tech Conference", o1.getRole());
    Event e2("Art Workshop", br1.getRole());

    // Display Events
    std::cout << "Events: \n";
    e1.show();
    e2.show();

    return 0;
}