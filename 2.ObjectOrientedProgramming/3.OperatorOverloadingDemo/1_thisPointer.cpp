#include <iostream>
#include <string>

class personType {
    public:
        //Function to output the first name and last name in
        //the form firstName lastName
        void print() const {
            std::cout << firstName << " " << lastName;
        }

        //Function to set firstName and lastName according to the parameters
        void setName(std::string first, std::string last) {
            firstName = first;
            lastName = last;
        }

        //Function to set the first name
        personType& setFirstName(std::string first) {
            firstName = first;
            return *this;
        }

        //Function to set the last name
        personType& setLastName(std::string last) {
            lastName = last;
            return *this;
        }

        //Function to return the first name
        std::string getFirstName() const {
            return firstName;
        }

        //Function to return the last name
        std::string getLastName() const {
            return lastName;
        }

        //Constructor
        personType(std::string first, std::string last){
            firstName = first;
            lastName = last;
        }

        personType(){}

    private:
        std::string firstName;
        std::string lastName;
};

int main() {
    personType student1("Lisa", "Smith");
    personType student2;
    personType student3;

    std::cout << "---Student 1---: ";
    student1.print();
    std::cout << '\n';

    student2.setFirstName("Shelly").setLastName("Malik");

    std::cout << "---Student 2---: ";
    student2.print();
    std::cout << '\n';

    student3.setFirstName("Cindy");

    std::cout << "---Student 3---: ";
    student3.print();
    std::cout << '\n';

    student3.setLastName("Tomek");

    std::cout << "---Student 3---: ";
    student3.print();
    std::cout << '\n';

    return 0;
}