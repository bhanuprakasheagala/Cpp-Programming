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

/*
Notes:

SimpleSmartPointer Implementation Notes

Introduction to Smart Pointers:

Smart pointers in C++ are designed to manage the lifetime of dynamically allocated objects. Unlike raw pointers, smart pointers automatically handle memory deallocation, reducing the risk of memory leaks and dangling pointers.
The `SimpleSmartPointer` mimics some behaviors of C++ standard smart pointers, such as `std::unique_ptr` and `std::shared_ptr`.

Key Concepts:

1. **Ownership**: Smart pointers maintain a clear ownership model. Only one smart pointer can own a resource at a time (exclusive ownership), which prevents double deletion and ensures that the resource is automatically freed when the owner is destroyed.

2. **RAII (Resource Acquisition Is Initialization)**: This principle ties resource management (like memory allocation) to the lifetime of an object. The resource is acquired during construction and released during destruction.

3. **Move Semantics**: Move semantics allow resources to be transferred from one object to another without copying. This is efficient and crucial for smart pointers, enabling ownership transfer without additional overhead.

4. **Copying Restrictions**: To prevent multiple smart pointers from owning the same resource, the copy constructor and assignment operator are deleted. This ensures that a `SimpleSmartPointer` cannot be copied, enforcing the exclusive ownership model.

Internal Structure

### Member Variables

- **Pointer to the Managed Object**: The smart pointer contains a raw pointer that points to the dynamically allocated object. This pointer is essential for accessing the resource and managing its lifetime.

### Constructor

The constructor of `SimpleSmartPointer` takes a raw pointer as an argument. When initialized with a dynamically allocated resource, it assigns the pointer to its member variable. This initialization marks the start of ownership.

### Destructor

The destructor of `SimpleSmartPointer` is responsible for releasing the resource. When the smart pointer goes out of scope, the destructor is called automatically, and it deletes the managed object. This automatic cleanup prevents memory leaks by ensuring that all allocated resources are properly freed.

### Move Constructor and Move Assignment Operator

The move constructor and move assignment operator facilitate the transfer of ownership:

- **Move Constructor**: When a `SimpleSmartPointer` is initialized using another smart pointer, it takes over the resource of the source pointer. The original pointer is nullified to prevent double deletion, meaning it no longer owns the resource.

- **Move Assignment Operator**: Similar to the move constructor, this operator transfers ownership from one smart pointer to another. The current smart pointer first deletes its existing resource (if it owns one) before taking over the resource from the other smart pointer.

### Dereference Operator

The dereference operator allows access to the managed resource. It provides a way to retrieve the value stored in the memory location pointed to by the smart pointer. Internally, it returns a reference to the object, enabling the user to interact with the managed resource as if it were a regular pointer.

### Boolean Conversion Operator

This operator allows checking if the smart pointer is null (i.e., it doesn’t own any resource). It simplifies condition checks, making it easy to determine if the smart pointer has valid ownership.

Code Flow:

### Initialization

1. A `SimpleSmartPointer` is created with a dynamically allocated resource. The constructor assigns the raw pointer to its member variable, establishing ownership.

### Resource Access

2. Users can access the resource using the dereference operator. This action retrieves the value stored at the pointer’s address, enabling operations on the managed object.

### Ownership Transfer

3. When transferring ownership through move semantics, the move constructor or move assignment operator is invoked. The original pointer is set to `nullptr`, indicating it no longer owns the resource, while the new smart pointer takes over.

### Destruction

4. Upon going out of scope, the destructor is called, automatically releasing the managed resource. This prevents memory leaks by ensuring all allocated memory is properly cleaned up.

Behind the Scenes:

- **Memory Management**: The `SimpleSmartPointer` handles dynamic memory using the `new` and `delete` operators. It encapsulates raw pointer management, making it safer and more robust than using raw pointers directly.

- **Error Prevention**: By deleting the copy constructor and assignment operator, the design prevents multiple smart pointers from managing the same resource. This approach significantly reduces the chances of errors such as double deletion or dangling pointers.

- **Efficiency**: Move semantics enable efficient resource transfer without the overhead of copying. This efficiency is particularly important for managing large resources where copying could be costly.

- **Automatic Cleanup**: Leveraging RAII, the `SimpleSmartPointer` ensures that resources are released when they go out of scope, providing a clear and predictable resource management strategy.
*/