/*
Demo of a custom static memory allocator in C++.

What and How it's working:
- This code demonstrates a custom static memory allocator using placement new.
- The `StaticMemoryAllocator` class manages a fixed-size buffer and provides an `allocate` method to allocate memory for objects of any type.
- The `Shape` class is an abstract base class with derived classes `Circle` and `Square`.
- The `ShapeFactory` class uses the static memory allocator to create instances of `Circle` and `Square` based on a type identifier.
- The `allocate` method calculates the new offset in the buffer, places the object in the buffer using placement new, and returns a pointer to the newly created object.

Example flow and output:
It starts by creating a `Circle` and a `Square` using the `ShapeFactory`, which utilizes the custom static memory allocator. The shapes are then drawn, demonstrating polymorphism.
*/

#include <iostream>

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

/// @brief A custom static memory allocator using placement new
/// @tparam Size The size of the static buffer to allocate from
/// @details This allocator provides a static buffer and an allocate method to create objects
/// of any type using placement new. It maintains an offset to track the next available memory location
/// in the buffer. It does not support deallocation or reuse of memory.
template<std::size_t Size>
class StaticMemoryAllocator {
    static char buffer_[Size];
    static std::size_t offset_;
    
    public:
        template<typename T>
        static auto allocate() {
            const auto new_offset = offset_ + sizeof(T);
            const auto place = buffer_ + new_offset - sizeof(T);
            offset_ = new_offset;
            return new (place) T {};
        }
};

// Initialize static member variable with empty buffer
template <std::size_t Size>
char StaticMemoryAllocator<Size>::buffer_[] = {};
 
// Initialize static member variable with zero offset
template <std::size_t Size>
std::size_t StaticMemoryAllocator<Size>::offset_ = 0;

/// @brief Factory class to create shapes using the static memory allocator
/// @details This class uses the StaticMemoryAllocator to create instances of shapes
/// based on the provided type identifier. It supports creating Circle and Square shapes.
class ShapeFactory {
    using allocator = StaticMemoryAllocator<8>;
    public:
        static Shape* create(int type) {
            switch(type) {
                case 1:
                    return allocator::allocate<Circle>();
                case 2:
                    return allocator::allocate<Square>();
                default:
                    throw std::invalid_argument{"Unknown Shape!"};
            }
        }
};

int main() {

    // Example1: usage of the ShapeFactory with custom static memory allocator
    Shape* shape1 = ShapeFactory::create(1); // Create Circle
    Shape* shape2 = ShapeFactory::create(2); // Create Square

    shape1->draw(); // Output: Circle
    shape2->draw(); // Output: Square


    // Example2: usage of the StaticMemoryAllocator directly
    auto* circle = StaticMemoryAllocator<8>::allocate<Circle>(); // Allocate Circle
    auto* square = StaticMemoryAllocator<8>::allocate<Square>(); // Allocate Square

    circle->draw(); // Output: Circle
    square->draw(); // Output: Square

    return 0;
}

/*
Output:
Circle
Square
Circle
Square
*/