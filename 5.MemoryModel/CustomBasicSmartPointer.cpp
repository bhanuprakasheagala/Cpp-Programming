#include <iostream>

template <typename T>
class CustomSmartPtr {
    private:
        T* ptr; // Raw pointer to hold the resources
    public:
        // Constructor
        explicit CustomSmartPtr(T* p = nullptr) : ptr(p) {}

        // Destructor to automatically delete the resource
        ~CustomSmartPtr() {
            delete ptr;
        }

        // Overload dereference operator
        T& operator*() const {
            return *ptr;
        }

        // Overload arrow operator
        T* operator->() const {
            return ptr;
        }

        // Delete the copy constructor and assignment operator
        CustomSmartPtr(const CustomSmartPtr&) = delete;
        CustomSmartPtr& operator=(const CustomSmartPtr&) = delete;

        // Move Constructor
        CustomSmartPtr(CustomSmartPtr&& other) noexcept : ptr(other.ptr) {
            other.ptr = nullptr;
        }

        // Move assignment operator
        CustomSmartPtr& operator=(CustomSmartPtr&& other) noexcept {
            if(this != &other) {
                delete ptr;
                ptr = other.ptr;
                other.ptr = nullptr;
            }

            return *this;
        }

        // Boolean conversion operator to support unary NOT
        explicit operator bool() const {
            return ptr != nullptr;
        }

};

int main()
{
    // Creating a simple smart pointer to an integer
    CustomSmartPtr<int> ptr1(new int(10));

    std::cout << "Value: " << *ptr1 << '\n';

    // Moving ownership of the pointer
    CustomSmartPtr<int> ptr2 = std::move(ptr1);
    if(!ptr1) {
        std::cout << "ptr1 is empty after move.\n";
    }
    
    std::cout << "Value after move: " << *ptr2 << '\n';

    return 0;
}