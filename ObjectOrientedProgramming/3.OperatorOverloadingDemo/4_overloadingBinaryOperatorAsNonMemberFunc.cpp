/*
Overloading binary operator as a Non-Memeber function
using the `friend` functions concept
*/

#include <iostream>

class rectangleType {
    
    // Overload the stream insertion and extraction operators
    friend std::ostream& operator<< (std::ostream&, const rectangleType&);
    friend std::istream& operator>> (std::istream&, rectangleType&);

    public:
        void setDimension(double l, double w);
        double getLength() const;
        double getWidth() const;
        double area() const;
        double perimeter() const;
        void print() const;

        rectangleType operator+(const rectangleType&) const;
        rectangleType operator*(const rectangleType&) const;
        bool operator==(const rectangleType&) const;
        bool operator!=(const rectangleType&) const;

        rectangleType();
        rectangleType(double l, double w);

    private:
        double length;
        double width;

};

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

rectangleType rectangleType::operator+(const rectangleType& rectangle) const {
    rectangleType tempRect;
    tempRect.length = length + rectangle.length;
    tempRect.width = width + rectangle.width;

    return tempRect;
}

rectangleType rectangleType::operator*(const rectangleType& rectangle) const {
    rectangleType tempRect;
    tempRect.length = length * rectangle.length;
    tempRect.width = width * rectangle.width;

    return tempRect;
}

bool rectangleType::operator==(const rectangleType& rectangle) const {
    return (length == rectangle.length && width == rectangle.width);
}

bool rectangleType::operator!=(const rectangleType& rectangle) const {
    return (length != rectangle.length && width != rectangle.width);
}

std::ostream& operator<< (std::ostream& osObject, const rectangleType& rectangle) {
    osObject << "Length: " << rectangle.length << " Width: " << rectangle.width;
    return osObject;
}

std::istream& operator>> (std::istream& isObject, rectangleType& rectangle) {
    isObject >> rectangle.length >> rectangle.width;
    return isObject;
}

int main() {
    rectangleType myRectangle(23,45);
    rectangleType yourRectangle;
    
    std::cout << "My Rectangle: " << myRectangle << '\n';

    std::cout << "Enter the length and width of a rectangle: ";
    std::cin >> yourRectangle;

    std::cout << '\n';

    std::cout << "Your Rectangle: " << yourRectangle << '\n';

    std::cout << "My Rectangle + Your Rectangle: " << myRectangle+yourRectangle << '\n';
    std::cout << "My Rectangle * Your Rectangle: " << myRectangle*yourRectangle << '\n';

    return 0;
}