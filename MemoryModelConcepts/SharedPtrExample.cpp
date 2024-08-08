/*
Purpose: Manages shared ownership of a dynamically allocated object using reference counting. Multiple shared_ptr instances
can own the same object, and the object is deleted only when the last shared_ptr owning it is destroyed or reset.

Key Features:
Reference Counting:   Keeps track of how many shared_ptrs are owning the object. When the count reaches zero, the object
                      is deleted.
Copyable:             std::shared_ptr can be copied and assigned.
Custom Deleters:      You can provide a custom deleter.
*/
#include <iostream>
#include <memory>

class SharedPtrDemo {

    public:
      SharedPtrDemo() {
          std::cout << "SharedPtrDemo Object constructed\n";
      }
      ~SharedPtrDemo() {
        std::cout << "SharedPtrDemo Object destroyed\n";
      }
      void greet() {
        std::cout << "Hello, world!!\n";
      }
};

int main() {
  std::shared_ptr<SharedPtrDemo> obj1 = std::make_shared<SharedPtrDemo>();
  
  // New block scope start
  {
    std::shared_ptr<SharedPtrDemo> obj2 = obj1;   // Share Ownership
    obj2->greet();                                // Use the manged object
    std::cout << "Use count: " << obj1.use_count() << '\n';
  } //end of block

  // obj2 goes out of scope here, but obj1 still owns the object
  std::cout << "Use count: " << obj1.use_count() << '\n';

  return 0;
}
