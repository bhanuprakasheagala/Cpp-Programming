// Overloading binary operator as a memeber function

#include <iostream>

class rectangleType {
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

int main() {

    rectangleType Obj1;
    rectangleType Obj2;

    Obj1.setDimension(5, 10);
    Obj2.setDimension(6, 12);

    rectangleType Res;

    Res = Obj1 + Obj2;
    Res.print();
    std::cout << Res.getLength() << " " << Res.getWidth() << '\n';
    std::cout << Res.area() << " " << Res.perimeter() << '\n';
    
    Res = Obj1 * Obj2;
    Res.print();
    std::cout << Res.getLength() << " " << Res.getWidth() << '\n';
    std::cout << Res.area() << " " << Res.perimeter() << '\n';

    bool res1 = (Obj1 == Obj2);
    std::cout << res1 << '\n';

    bool res2 = (Obj1 != Obj2);
    std::cout << res2 << '\n';

    return 0;
}