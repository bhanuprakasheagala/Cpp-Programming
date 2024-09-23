#include <cstddef>
#include <iostream>

class MemoryAllocator {
    private:
        // Size of the Memory Pool (For simplicity, we'll allocate a fixed size)
        std::size_t poolSize;
        void* memoryPool; // Pointer to the start of the memory pool
        void* freeList;   // Pointer to the free list

        // Helper functiont to create a free list
        void initializeFreeList() {
            // Divide the memory into fixed-size blocks and link them together
            char* currentBlock = static_cast<char*>(memoryPool);
            for(std::size_t i = 0; i < (poolSize / blocksize) - 1; ++i) {
                *reinterpret_cast<void**>(currentBlock) = currentBlock + blocksize;
                currentBlock += blocksize;
            }
            *reinterpret_cast<void**>(currentBlock) = nullptr; // Last block points to nullptr
            freeList = memoryPool; // The free list starts at the beginning
        }
    
    public:
        static constexpr std::size_t blocksize = 32; // Size of each block in bytes

        // Constructor
        MemoryAllocator(std::size_t size) : poolSize(size) {
            memoryPool = ::operator new(poolSize); // Allocate the memory pool
            initializeFreeList();
        }

        

};