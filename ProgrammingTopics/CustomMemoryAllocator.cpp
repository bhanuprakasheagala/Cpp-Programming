#include <cstddef>
#include <iostream>

class MemoryAllocator {
    private:
        std::size_t poolSize; // Size of the Memory Pool (For simplicity, we'll allocate a fixed size)
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

        // Allocate a block of memory
        void* allocate() {
            if(freeList == nullptr) {
                throw std::bad_alloc(); // No free blocks left
            }

            void* allocateBlock = freeList;
            freeList = *reinterpret_cast<void**>(freeList); // Move to the next free block

            return allocateBlock;
        }

        // Deallocate a block of memory (return it to the free list)
        void deallocate(void* block) {
            *reinterpret_cast<void**>(block) = freeList; // Add the block to front of the free list
            freeList = block;
        }

        // Destructor
        ~MemoryAllocator() {
            ::operator delete(memoryPool); // Free the memory pool
        }
};

int main() {

    // Create a memory pool of 1024 bytes
    MemoryAllocator allocator(1024);

    // Allocate memory for three objects
    void* block1 = allocator.allocate();
    void* block2 = allocator.allocate();
    void* block3 = allocator.allocate();

    // Use the blocks (cast to appropriate types)
    int *p = static_cast<int*>(block1);
    *p = 42;

    std::cout << "Value in allocated block: " << *p << '\n';

    // Deallocate the blocks
    allocator.deallocate(block1);
    allocator.deallocate(block2);
    allocator.deallocate(block3);

    return 0;
}