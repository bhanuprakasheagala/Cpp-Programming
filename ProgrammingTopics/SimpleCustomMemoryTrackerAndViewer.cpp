#include <iostream>
#include <exception>
#include <vector>
#include <iomanip>
#include <cstring>

// Global variables to count each call of new and delete operators
uint16_t new_counter = 0;       // Counter to keep track of the number of new allocations
uint16_t delete_counter = 0;    // Counter to keep track of the number of delete calls
size_t allocated_memory = 0;    // Total memory allocated by new operator

// Function to reset the global counters to zero
void resetCounter() {
    std::cout << "Resetting counter to all zeros...\n"; // Inform the user about the reset action
    new_counter = 0;             // Reset the new counter
    delete_counter = 0;          // Reset the delete counter
    allocated_memory = 0;        // Reset the allocated memory counter
}

// Function to display the summary of new/delete calls and memory usage
void displaySummary() {
    std::cout << std::dec << "#new: " << new_counter      // Display the number of new calls in decimal
              << " #delete: " << delete_counter          // Display the number of delete calls in decimal
              << " #bytes: " << allocated_memory << '\n'; // Display the total allocated memory in bytes
}

// Overload the new operator to track allocations and memory usage
void* operator new(std::size_t sz) {
    void* ptr = std::malloc(sz); // Allocate memory using malloc
    
    if(ptr) {
        new_counter++;             // Increment the new counter
        allocated_memory += sz;   // Increase the allocated memory counter
        return ptr;                // Return the allocated memory pointer
    }
    else {
        throw std::bad_alloc{};    // Throw an exception if memory allocation fails
    }
}

// Overload the delete operator to track deallocations
void operator delete(void* ptr) noexcept {
    delete_counter++;   // Increment the delete counter
    std::free(ptr);     // Free the allocated memory using free
}

// Function to display the contents of raw memory in a readable format
void showMemory(unsigned char* buffer, std::size_t buffer_size, const char* headline = "") {
    if(headline != "" ){
        std::cout << headline << '\n'; // Print the headline if provided
    }
    // Print the address of the buffer and its size
    std::cout << "&buffer=0x" << std::hex << reinterpret_cast<uintptr_t>(buffer) << " " << std::dec << buffer_size << " bytes\n";

    /*
    -> Initializes i to iterate over the buffer.
    -> first: is the starting index of the current chunk of memory.
    -> last: is the ending index of the current chunk. It is calculated to be either 10 bytes ahead or the end of the buffer, whichever is smaller.
    -> std::setw(2): Ensures that the address is printed with at least 2 hexadecimal digits.
    */
    int i = 0;
    while(i < buffer_size) { // Loop through the buffer in chunks
        int first = i; // Start index for the current chunk
        int last = i + std::min(10, int(buffer_size - first)); // End index for the current chunk, limited to 10 bytes
        std::cout << "&=" << std::setw(2) << std::hex << std::size_t(first); // Print the start address of the chunk

        /*
        -> Loops through each byte in the current chunk.
        -> If the byte value is in the printable ASCII range (32 to 127), it prints the corresponding character.
        -> Non-printable characters are replaced with a dot (.) for readability.
        */
        std::cout << " asc: "; // Print the ASCII representation header
        for(int k = first; k < last; ++k) { 
            if((buffer[k] >= 32) and (buffer[k] <= 127)) {
                std::cout << buffer[k]; 
            }
            else {
                std::cout << "."; 
            }
        }
        i += 10; // Move to the next chunk
        std::cout << '\n'; // Print a newline after each chunk
    }
    std::cout << '\n'; // Print a newline after displaying the memory
}

int main()
{
    displaySummary(); // Display the summary before any allocations

    std::cout << "\nAfter calling one explicit new and delete operators:\n";
    int *pi = new int; // Allocate memory for an int
    delete pi;         // Deallocate the memory for the int
    std::cout << "Summary for each call of new/delete: \n";
    displaySummary(); // Display the summary after one explicit allocation and deallocation
    
    resetCounter(); // Reset counters to zero
    
    std::cout << "\nFor STL containers, new and delete are called implicitly..\n";
    std::vector<int> v; // Create an empty vector of integers
    std::cout << "Summary for each call of new/delete: \n";
    for(int i = 0; i < 10; ++i) {
        v.push_back(i); // Add elements to the vector
        displaySummary(); // Display the summary after each insertion
    }

    // Display the contents of raw memory using showMemory function
    std::cout << "\n\n**************Concept of Displaying Raw Memory**************\n";
   
    // Create a buffer with printable ASCII characters and some Non-printable ASCII characters
    const std::size_t bufferSize = 50;
    unsigned char bufferSpace[bufferSize];
    
    // Fill the buffer with some data
    for(std::size_t i=0; i < bufferSize; ++i) {
        if(i % 2 == 0) {
            bufferSpace[i] = 'A' + (i%26); // Printable characters 'A' to 'Z'
        }
        else {
            bufferSpace[i] = static_cast<unsigned char>(i%32); // Non-printable characters
        }
    }
    
    // Add some text to the bufferSpace
    std::strcpy(reinterpret_cast<char*>(bufferSpace)+26, "Hello, Memory!!");
    
    showMemory(bufferSpace, bufferSize, "-----MEMORY DUMP----");
    
    return 0; // Return 0 to indicate successful completion
}
