#include <iostream>
#include "rectangleTypes.h"

void rectangleType::setDimension(double l, double w) {
    if(l >= 0)
        length = l;
    else
        length = 0;

    if(w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType::getLength() const {
    return length;
}

double rectangleType::getWidth() const {
    return width;
}

double rectangleType::area() const {
    return length*width;
}

double rectangleType::perimeter() const {
    return 2*(length+width);
}

void rectangleType::print() const {
    std::cout << "Length: " << length << '\n';
    std::cout << "Width: " << width << '\n';
}

rectangleType::rectangleType(double l, double w) {
    setDimension(l, w);
}

rectangleType::rectangleType() {
    length = width = 0;
}

/*
int main() {
    
    rectangleType obj;
    obj.setDimension(5, 10);
    std::cout << obj.getLength() << std::endl;
    std::cout << obj.getWidth() << std::endl;
    std::cout << obj.area() << std::endl;
    std::cout << obj.perimeter() << std::endl;
    obj.print();

    return 0;
}
*/