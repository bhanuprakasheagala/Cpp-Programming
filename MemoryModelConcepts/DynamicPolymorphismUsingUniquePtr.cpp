#include <iostream>
#include <memory>

class Shape {
    public:
        virtual void draw() const = 0;
        virtual ~Shape() = default;
};

class Circle : public Shape {
    public:
        void draw() const override{
            std::cout << "Circle\n";
        }
};

class Square : public Shape {
    public:
        void draw() const override {
            std::cout << "Square\n";
        }
};

class ShapeFactory {
    public:
        static std::unique_ptr<Shape> create(int type) {
            switch(type) {
                case 1 :
                    return std::make_unique<Circle>();
                case 2 :
                    return std::make_unique<Square>();
                default :
                    throw std::invalid_argument{"Unknown shape!\n"};
            }
        }
};

int main()
{
    const auto circle = ShapeFactory::create(1);
    circle->draw();
    
    const auto square = ShapeFactory::create(2);
    square->draw();
  
    return 0;
}
