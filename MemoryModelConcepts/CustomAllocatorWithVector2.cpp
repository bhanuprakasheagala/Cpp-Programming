#include <iostream>
#include <vector>
#include <memory>

// Custom Allocator class
template <typename T>
class CustomAllocator : public std::allocator<T> {
  public:
      using value_type = T;
      
      CustomAllocator() noexcept = default;
      
      template<typename U>
      CustomAllocator(const CustomAllocator<U>&) noexcept {}

      T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements.\n";
        return std::allocator<T>().allocate(n);
      }
      void deallocate(T* p, std::size_t n) noexcept {
        std::cout << "Deallocating " << n << " elements.\n";
        std::allocator<T>().deallocate(p, n);
      }
      
      template <typename U>
      struct rebind {
          using other = CustomAllocator<U>;
      };
};

// Comparison operator for allocators (necessary for containers that use allocators)
template <typename T, typename U>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) {
  return true;
}

template <typename T, typename U>
bool operator!=(const CustomAllocator<T>&, const CustomAllocator<U>&) {
  return false;
}

int main() {
  // Create a vector of integers with a custom allocator
  std::vector<int, CustomAllocator<int>> vec = {1, 2, 3, 4, 5};

  // Print the elements of type vector
  for(const int& val : vec) {
    std::cout << val << " ";
  }
  std::cout << '\n';
  
  return 0;
}

/*
Notes:
Allocator Definition: The CustomAllocator class is defined with the necessary types and methods for compatibility. It uses std::allocator for memory operations internally but allows customization through the interface.
Type Definitions: value_type is defined to meet allocator requirements.
Rebind Mechanism: Implement the rebind struct to ensure compatibility with containers that require type rebound for different types of allocators.
Constructors and Assignment: Added default and conversion constructors to ensure compatibility with various container constructors.
Comparison Operators: Ensure operator== and operator!= are defined for allocator comparison, which is needed by many STL containers.
Noexcept Specification: Added noexcept to deallocate to match modern allocator requirements and to indicate that these operations do not throw exceptions.

Works with C++11 and later standards as checked in online gdb C++ compiler.

Output:
Allocating 5 elements.
1 2 3 4 5 
Deallocating 5 elements.
*/
