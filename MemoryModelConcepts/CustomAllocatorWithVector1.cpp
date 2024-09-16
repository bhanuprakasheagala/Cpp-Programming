#include <iostream>
#include <vector>
#include <memory>

// Custom Allocator class
template <typename T>
class CustomAllocator : public std::allocator<T> {
  public:
      using std::allocator<T>::allocator;

      T* allocate(size_t n) {
        std::cout << "Allocating " << n << " elements.\n";
        return std::allocator<T>::allocate(n);
      }
      void deallocate(T* p, size_t n){
        std::cout << "Deallocating " << n << " elements.\n";
        std::allocator<T>::deallocate(p, n);
      }
};

// Comparison operator for allocators (necessary for containers that use allocators)
template <typename T>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<T>&) {
  return true;
}

template <typename T>
bool operator!=(const CustomAllocator<T>&, const CustomAllocator<T>&) {
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
This example uses a custom allocator that inherits from std::allocator. The custom allocator overrides the allocate and
deallocate methods to print messages when memory is allocated or deallocated.
By using this custom allocator with std::vector, you can see how allocation and deallocation are handled.

This code is compiled only with C++20 or later versions as checked in online gdb C++ compiler.

Output:
Allocating 5 elements.
1 2 3 4 5 
Deallocating 5 elements.
*/
