#ifndef H_personType
#define H_personType

class personType {
    public:
        // Function to print the first and last names
        void print() const;

        // Function to set firstName and lastName
        void setName(std::string first, std::string last);

        // Function to return the first name
        std::string getFirstName() const;

        // Function to return the last name
        std::string getLastName() const;

        // Default constructor
        personType();

        // Constructor with parameters
        personType(std::string first, std::string last);
    
    private:
        std::string firstName;
        std::string lastName;
};

#endif