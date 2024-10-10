#include <iostream>

struct Point {
    int x;
    int y;
};

int main()
{
    Point points[] = {{1, 2}, {3, 4}, {5, 6}}; // Each array element is struct Point type
    Point* ptr = points; // Points to the first element of the array
    // std::cout << *ptr;             Error : Invalid operands to binary expression and 'Point' 
    // std::cout << (*ptr).x << '\n'; Prints 1
    std::cout << "Size of points: " << sizeof(points);
    std::cout << "\nNumber of elements: " << sizeof(points)/sizeof(points[0]); 
    
    for(int i=0; i<3; ++i) {
        std::cout << "Point " << i+1 << ": (" << (ptr + i)->x << ", " << (ptr + i)->y << ")\n";
    }

    return 0;
}