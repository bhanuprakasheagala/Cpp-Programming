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

template <std::size_t Size>
char StaticMemoryAllocator<Size>::buffer_[] = {};
 
template <std::size_t Size>
std::size_t StaticMemoryAllocator<Size>::offset_ = 0;

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
