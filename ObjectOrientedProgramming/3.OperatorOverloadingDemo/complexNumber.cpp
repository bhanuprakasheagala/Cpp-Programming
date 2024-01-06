#include <iostream>
#include "complexNumber.h"

// Overload the stream extraction operator to output a complex number in the form (a, b)
std::ostream& operator<< (std::ostream& osObject, const complexType& complex) {
    osObject << "(";
    osObject << complex.realPart;
    osObject << ", ";
    osObject << complex.imaginaryPart;
    osObject << ")";

    return osObject;
}

// Overload the stream insertion operator to input a complex number in the form (a, b)
std::istream& operator>> (std::istream& isObject, complexType& complex) {
    char ch;
    isObject >> ch;
    isObject >> complex.realPart;
    isObject >> ch;
    isObject >> complex.imaginaryPart;
    isObject >> ch;

    return isObject;
}

bool complexType::operator== (const complexType& otherComplex) const {
    return (realPart == otherComplex.realPart && imaginaryPart == otherComplex.imaginaryPart);
}

complexType complexType::operator+ (const complexType& otherComplex) const {
    complexType temp;
    temp.realPart = realPart + otherComplex.realPart;
    temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;

    return temp;
}

complexType complexType::operator* (const complexType& otherComplex) const {
    complexType temp;
    temp.realPart = (realPart*otherComplex.realPart) - (imaginaryPart*otherComplex.imaginaryPart);
    temp.imaginaryPart = (realPart*otherComplex.imaginaryPart) + (imaginaryPart*otherComplex.realPart);

    return temp;
}

complexType::complexType(double real, double imag) {
    realPart = real;
    imaginaryPart = imag;
}

void complexType::setComplex(const double& real, const double& imag) {
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const{
    real = realPart;
    imag = imaginaryPart;
}

int main() {
    
    complexType num1(23, 34);
    complexType num2;
    complexType num3;

    std::cout << "Num1: " << num1 << '\n';
    std::cout << "Num2: " << num2 << '\n';

    std::cout << "Enter the complex number in the form (a, b): ";
    std::cin >> num2;
    std::cout << '\n';

    std::cout << "New value of Num2 : " << num2 << '\n';

    num3 = num1+num2;
    std::cout << "Num3: " << num3 << '\n';

    std::cout << num1 << "+" << num2 << "=" << num1+num2 << '\n';
    std::cout << num1 << "*" << num2 << "=" << num1*num2 << '\n';

    return 0;
}