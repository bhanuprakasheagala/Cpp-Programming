/*
An operator must be overloaded as a non-member when the first operand is not an object of the class.

This version of the + operator cannot be overloaded as a member of the class because every member
function receives the caller object as `*this` of the same class type.
Therefore, we overload this version as a non-member.
*/

#include <iostream>

class Point {
    private:
        int x,y;
    public:
        Point(int a, int b) : x(a), y(b) {}
        void show() const {
            std::cout << "(" << x << "," << y << ") ";
        }

        friend Point operator+(const int& lhs, const Point& rhs);
};

Point operator+(const int& lhs, const Point& rhs) {
    return Point(lhs + rhs.x, lhs + rhs.y);
}

int main() {
    Point p(3,4);
    p.show();

    // The Overloaded operator works for int+Point
    Point r = 6 + p;
    r.show();
    std::cout << '\n';

    return 0;
}