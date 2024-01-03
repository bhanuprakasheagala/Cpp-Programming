#include "personType.h"
#include "dateType.h"

#ifndef H_CompositionClass
#define H_CompositionClass

class personalInfoType {
    public:
        // Function to set the personal information
        void setPersonalInfo(std::string first, std::string last, int day, int month, int year, int ID);

        // Function to print the personal information
        void printPersonalInfo() const;

        // Constructor
        personalInfoType(std::string first="", std::string last="", int day=1, int month=1, int year=1900, int ID=0);

    private:
        personType name;
        dateType bDay;
        int personID;
};

#endif