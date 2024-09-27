#include <iostream>
#include <algorithm>
#include <vector>

class MemoryBlock {
public:
    // Constructor
    explicit MemoryBlock(size_t length) :
        _length(length), _data(new int[length]) {
        std::cout << "In MemoryBlock(size_t). length = " << _length << ".\n";
        std::cout << "MemoryBlock constructed. Allocated " << _length << " integers.\n";
    }

    // Destructor
    ~MemoryBlock() {
        std::cout << "In ~MemoryBlock(). length = " << _length << ".\n";
        
        if (_data != nullptr) {
            std::cout << "Deleting the resource of length " << _length << ".\n";
            delete[] _data;
        } else {
            std::cout << "No resource to delete.\n";
        }
    }

    // Copy constructor
    MemoryBlock(const MemoryBlock& other) : _length(other._length), _data(new int[other._length]) {
        std::cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length << ". Copying resource.\n";
        std::copy(other._data, other._data + _length, _data);
        std::cout << "Resource copied successfully.\n";
    }

    // Copy assignment operator
    MemoryBlock& operator=(const MemoryBlock& other) {
        std::cout << "In operator=(const MemoryBlock&). length = " << other._length << ". Copying resource.\n";
        
        if (this != &other) {
            delete[] _data;  // Free the existing resource
            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
            std::cout << "Resource copied successfully.\n";
        } else {
            std::cout << "Self-assignment detected; no action taken.\n";
        }

        return *this;
    }

    // Retrieves the length of the data resource
    size_t Length() const {
        return _length;
    }

private:
    size_t _length;
    int* _data;
};      

int main() {
    std::cout << "Starting main function.\n";
    
    std::vector<MemoryBlock> mbv;
    std::cout << "Creating and pushing a MemoryBlock of length 34 into the vector.\n";
    
    // Create a MemoryBlock of length 34 and push it to the vector
    MemoryBlock tempBlock(34); // Temporary object creation
    mbv.push_back(tempBlock);   // Copying the temporary object
    
    std::cout << "MemoryBlock has been pushed to the vector.\n";
    
    // Explain the temporary object's destruction
    std::cout << "The temporary MemoryBlock created will now be destructed as it goes out of scope.\n";

    std::cout << "Ending main function.\n";

    return 0;
}


/*
Notes:
-> Memory Block construction:
The main function begins by declaring a std::vector<MemoryBlock> named mbv.
mbv.push_back(MemoryBlock(34)); creates a temporary MemoryBlock object with a length of 34. This invokes the constructor:
  MemoryBlock(size_t length);
  
-> Temporary Object Creation:
The MemoryBlock(34) constructor allocates memory for 34 integers and initializes the _length and _data members.
Since this is a temporary object, it is immediately subject to move semantics (or copy semantics if moves aren't available), because it's being added to the vector.

-> Copying the Temporary Object:
When push_back is called, the vector needs to store this new object. Since std::vector manages its elements dynamically, it may need to copy the object to its internal storage.
This invokes the copy constructor:
MemoryBlock(const MemoryBlock& other);
A new MemoryBlock is created inside the vector with its own _data array, and the contents are copied from the temporary object.

-> Destruction of Temporary Object:
After the copy is made, the temporary MemoryBlock object (the one created in push_back) goes out of scope and is destroyed. This invokes the destructor.

-> Destruction of the Vector's Copy:
When mbv goes out of scope (which happens at the end of the main function), the destructor of the MemoryBlock stored in the vector is called. This again invokes the destructor.

Output:
Starting main function.
Creating and pushing a MemoryBlock of length 34 into the vector.
In MemoryBlock(size_t). length = 34.
MemoryBlock constructed. Allocated 34 integers.
In MemoryBlock(const MemoryBlock&). length = 34. Copying resource.
Resource copied successfully.
MemoryBlock has been pushed to the vector.
The temporary MemoryBlock created will now be destructed as it goes out of scope.
Ending main function.
In ~MemoryBlock(). length = 34.
Deleting the resource of length 34.
In ~MemoryBlock(). length = 34.
Deleting the resource of length 34.
*/
