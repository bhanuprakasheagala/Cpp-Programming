#include <iostream>
#include <string>
#include "CompositionClass.h"
#include "dateType.cpp"
#include "personType.cpp"

personalInfoType::personalInfoType(std::string first, std::string last, int day, int month, int year, int ID) :
name(first, last), bDay(day, month, year) {
    personID = ID;
}

void personalInfoType::setPersonalInfo(std::string first, std::string last, int day, int month, int year, int ID) {
    name.setName(first, last);
    bDay.setDate(day, month, year);
    personID = ID;
}

void personalInfoType::printPersonalInfo() const {
    name.print();
    std::cout << "'s date of birth is: ";
    bDay.printDate();
    std::cout <<"and personal ID is " << personID;
    std::cout << '\n';
}

int main() {

    personalInfoType obj;
    //obj.setDate(06, 06, 1997);
    //obj.printDate();
    obj.setPersonalInfo("Bhanuprakash", "Eagala", 06, 06, 1997, 1818);
    obj.printPersonalInfo();
    return 0;
}