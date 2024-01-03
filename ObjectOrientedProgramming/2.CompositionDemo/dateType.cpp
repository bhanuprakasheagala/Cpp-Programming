#include <iostream>
#include "dateType.h"

void dateType::setDate(int day, int month, int year) {
    dDay = day;
    dMonth = month;
    dYear = year;
}

int dateType::getDay() const {
    return dDay;
}

int dateType::getMonth() const {
    return dMonth;
}

int dateType::getYear() const {
    return dYear;
}

void dateType::printDate() const {
    std::cout << dDay << "-" << dMonth << "-" << dYear << '\n';
}

dateType::dateType(int day, int month, int year) {
    setDate(day, month, year);
}

/*
int main() {

    return 0;
}
*/