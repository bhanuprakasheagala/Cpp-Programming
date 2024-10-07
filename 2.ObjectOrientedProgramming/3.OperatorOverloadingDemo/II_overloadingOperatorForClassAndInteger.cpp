#include <iostream>

class Point {
    private:
        int x,y;
    public:
        Point(int a, int b) : x(a), y(b) {}
        void show() const {
            std::cout << "(" << x << "," << y << ")"; 
        }
        Point operator+(const int& rhs) {
            return Point(x + rhs, y+rhs);
        }
};

int main() {
    Point p(3,4);
    p.show();

    // The Overloaded operator works for Point+int
    Point r = p + 6;
    r.show();
    std::cout << '\n';
        
    return 0;
}