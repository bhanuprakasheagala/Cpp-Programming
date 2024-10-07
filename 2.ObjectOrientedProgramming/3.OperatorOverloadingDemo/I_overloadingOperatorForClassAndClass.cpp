#include <iostream>

class Point {
    private:
        int x,y;
    public:
        Point(int a, int b) : x(a), y(b) {}
        void show() const {
            std::cout << "(" << x << "," << y << ") ";
        }

        Point operator+(const Point& rhs) const{
            return Point(x+rhs.x, y+rhs.y);
        }
};

int main() {
    Point p(2,5), q(3,8);
    p.show();
    q.show();

    // The Overloaded operator works for Point+Point
    Point r = p +  q;
    r.show();
    std::cout << '\n';
    
    return 0;
}