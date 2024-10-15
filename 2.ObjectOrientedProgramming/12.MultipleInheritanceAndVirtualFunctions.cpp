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

/*
Notes on Code Flow and Concepts Involded:

1. Class Design:
   - The program models a basic event management system with users playing different roles (`Participant`, `Organizer`, or both). 
   - The base class `Person` holds common attributes (`name` and `age`) and declares a pure virtual function `getRole()`. This makes `Person` an abstract class, ensuring that no object of `Person` can be created directly.
   - `Participant` and `Organizer` are derived from `Person`, overriding `getRole()` to return the appropriate role. The `show()` method is overridden to display details specific to each role.
   - The virtual functions (`show()` and `getRole()`) demonstrate polymorphism, where the method invoked depends on the actual type of the object at runtime, even if accessed through a `Person*` pointer.

2. Multiple Inheritance:
   - The class `BothRoles` inherits from both `Participant` and `Organizer`, representing a user who can participate in events and also organize them. Since `BothRoles` inherits from both `Participant` and `Organizer`, it indirectly inherits from `Person` twice. This introduces a diamond problem where the class `BothRoles` would have two separate instances of `Person`.

3. Virtual Inheritance:
   - The diamond problem occurs when a base class (here `Person`) is inherited multiple times through different paths (once through `Participant` and again through `Organizer`), leading to ambiguity and redundant base class data. 
   - Without virtual inheritance, `BothRoles` would inherit two separate copies of `Person`, which is ambiguous and inefficient.
   - To avoid this, virtual inheritance is applied to the inheritance of `Person` in both `Participant` and `Organizer`. Virtual inheritance ensures that `BothRoles` gets only a single instance of `Person`, preventing any ambiguity and redundant base class data.

4. Polymorphism:
   - In the `main()` function, a list of `Person*` pointers is used to store objects of type `Participant`, `Organizer`, and `BothRoles`. This demonstrates runtime polymorphism because the actual object type determines which `show()` method is called, even though the list stores `Person*` pointers.
   - The `getRole()` method is also invoked dynamically at runtime using virtual function dispatch to retrieve the correct role of the object, showcasing dynamic binding.

5. Event Class:
   - The `Event` class represents an event, with attributes for the event title and the organizer's name. It demonstrates simple aggregation (composition), where an event is associated with an organizer.

### Issues and Fixes:

1. Diamond Problem (Multiple Inheritance Ambiguity):
   - Issue: When `BothRoles` inherits from both `Participant` and `Organizer`, both of which inherit from `Person`, the class `BothRoles` would end up with two separate instances of `Person`, leading to ambiguity. The compiler generates an error because it does not know which `Person`'s members to use.
   - Fix: The inheritance of `Person` in both `Participant` and `Organizer` is made virtual. This ensures that `BothRoles` inherits only one shared instance of `Person`, solving the ambiguity.

2. Pure Virtual Function:
   - Concept: The use of a pure virtual function (`getRole()`) in the base class `Person` forces all derived classes to implement their version of the function. This makes `Person` an abstract class, ensuring that no object of `Person` can be instantiated directly.
   
3. Polymorphism and Virtual Functions:
   - Concept: The virtual function mechanism allows the correct `show()` method to be invoked at runtime, depending on the actual type of the object (e.g., `Participant`, `Organizer`, or `BothRoles`). Without declaring `show()` as `virtual`, the base class version would be called, regardless of the object’s actual type.
   - Flow: When `Person*` pointers are used in the vector of `users`, each pointer still invokes the correct overridden method due to the dynamic dispatch enabled by the `virtual` keyword.
*/