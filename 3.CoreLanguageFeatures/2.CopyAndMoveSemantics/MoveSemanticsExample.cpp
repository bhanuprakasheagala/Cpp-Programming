#include <iostream>
#include <vector>

class MemoryBlock {
    public:
        // Simple Constructor that initializes the resource.
        explicit MemoryBlock(size_t length) : _length(length), _data (new int[_length]) {
            std::cout << "In MemoryBlock (size_t). length = " << _length << ".\n";
        }
        
        // Destructor
        ~MemoryBlock() {
            std::cout << "In ~MemoryBlock(). length = " << _length << ".";
            if(_data != nullptr) {
                std::cout << " Deleting resource.\n";
                
                // Delete the resource
                delete[] _data;
            }
            std::cout << '\n';
        }
        
        // Copy constructor
        MemoryBlock(const MemoryBlock& other) : _length(other._length), _data(new int[other._length]) {
            std::cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length <<". Copying resource.\n";
            std::copy(other._data, other._data + _length, _data);
        }
        
        // Copy assignment operator
        MemoryBlock& operator=(const MemoryBlock& other) {
            std::cout << "In operator=(const MemoryBlock&). length = " << other._length << ". Copying resource.\n";
            if(this != &other) {
                // Free the existing resource
                delete[] _data;
                
                _length = other._length;
                _data = new int[other._length];
                std::copy(other._data, other._data + _length, _data);
            }
            return *this;
        }
        
        // Move constructor
        MemoryBlock(MemoryBlock&& other) noexcept : _data(nullptr), _length(0) {
            std::cout <<"In MemoryBlock(MemoryBlock&&). length = " << other._length << ". Moving resource. \n";
            
            // Copy the data pointer and its length from the source object
            _data = other._data;
            _length = other._length;
            
            // Release the data pointer from the source object so that the destructor does not free the memory multiple times.
            other._data = nullptr;
            other._length = 0;
        }
        
        // Move assignment operator
        MemoryBlock& operator=(MemoryBlock&& other) noexcept {
            std::cout << "In operator=(MemoryBlock&&). length = " << other._length << ".\n";
            if(this != &other) {
                // Free the existing resource
                delete[] _data;
                
                // Copy the data pointer and its length from the source object.
                _data = other._data;
                _length = other._length;
                
                // Release the data pointer from the source object so that the destructor does not free the memory multiple times.
                other._data = nullptr;
                other._length = 0;
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
    
    // Create a vector object and add a few elements to it
    std::vector<MemoryBlock> mbv;
    mbv.push_back(MemoryBlock(25));
    mbv.push_back(MemoryBlock(75));
    
    // Insert a new element into the second position of the vector
    mbv.insert(mbv.begin() + 1, MemoryBlock(50));
    
    return 0;
}

/*
Output:
In MemoryBlock (size_t). length = 25.
In MemoryBlock(MemoryBlock&&). length = 25. Moving resource. 
In ~MemoryBlock(). length = 0.
In MemoryBlock (size_t). length = 75.
In MemoryBlock(MemoryBlock&&). length = 75. Moving resource. 
In MemoryBlock(MemoryBlock&&). length = 25. Moving resource. 
In ~MemoryBlock(). length = 0.
In ~MemoryBlock(). length = 0.
In MemoryBlock (size_t). length = 50.
In MemoryBlock(MemoryBlock&&). length = 50. Moving resource. 
In MemoryBlock(MemoryBlock&&). length = 25. Moving resource. 
In ~MemoryBlock(). length = 0.
In MemoryBlock(MemoryBlock&&). length = 75. Moving resource. 
In ~MemoryBlock(). length = 0.
In ~MemoryBlock(). length = 0.
In ~MemoryBlock(). length = 25. Deleting resource.

In ~MemoryBlock(). length = 50. Deleting resource.

In ~MemoryBlock(). length = 75. Deleting resource.
*/
