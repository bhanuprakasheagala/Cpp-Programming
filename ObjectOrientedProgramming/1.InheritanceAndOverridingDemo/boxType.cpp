#include <iostream>
#include "boxType.h"
#include "rectangleTypes.cpp"

void boxType::print() const {
    rectangleType::print();
    std::cout << "Height: " << height << '\n';
}

void boxType::setDimension(double l, double w, double h) {
    rectangleType::setDimension(l,w);
    if(h >= 0)
        height = h;
    else
        height = 0.0;
}

double boxType::getHeight() const {
    return height;
}

double boxType::area() const {
    return 2 * (getLength()*getWidth() +  getLength()*height + getWidth()*height);
}

double boxType::volume() const {
    return rectangleType::area() * height;
}

boxType::boxType() {
    height = 0.0;
}

boxType::boxType(double l, double w, double h) : rectangleType(l, w) {
    if(h >= 0)
        height = h;
    else
        height = 0.0;
}

int main() {
    boxType obj1;
    rectangleType obj2;

    obj1.setDimension(10,10,10);
    obj2.setDimension(5.5, 7.8);

    obj1.print();
    obj2.print();

    std::cout << obj1.getHeight() << '\n';
    std::cout << obj1.getLength() << '\n';
    std::cout << obj1.getWidth() << '\n';

    std::cout << obj2.getLength() << '\n';
    std::cout << obj2.getWidth() << '\n';

    std::cout << obj1.area() << '\n';
    std::cout << obj1.volume() << '\n';

    std::cout << obj2.area() << '\n';    


    return 0;
}