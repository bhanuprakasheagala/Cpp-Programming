#include <iostream>
class Shape {
    public:
        virtual void draw() = 0; // pure virual function
};

class Circle : public Shape {
    public:
        void draw() override {
            std::cout << "Drawing a Circle\n";
        }
};

class Square : public Shape {
    public:
        void draw() override {
            std::cout << "Drawing Square\n";
        }
};

int main()
{
    // Shape shap => Error: Cannot instantiate an Abstract class
    Circle circle;
    circle.draw();

    Square square1;
    square1.draw();

    Square* square2; // If pointer created, then first we need to assign it an appropriate object and call using -> notation.
    Square obj;
    square2 = &obj;
    square2->draw();

    return 0;
}