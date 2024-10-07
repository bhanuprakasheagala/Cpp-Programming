#include <iostream>

int main() {

    uint8_t buffer[20]; // A buffer to hold raw data
    uint8_t* ptr = buffer; // Pointer to the start of the buffer

    // Store a 32-bit integer in the buffer
    uint32_t value = 0x12345678;
    memcpy(ptr, &value, sizeof(value)); // Copy the value into the buffer
    ptr += sizeof(value); // Move pointer ahead by 4 bytes

    // Store a character string in the buffer
    const char* text = "Hello";
    strcpy((char *)ptr, text);
    ptr += strlen(text) + 1; // Move the pointer past the string and null pointer

    // Print the buffer contents as hexadecimal values
    printf("Buffer content in hex: ");
    for(int i = 0; i < 20; ++i) {
        printf("%02x", buffer[i]);
    }
    printf("\n");

    return 0;
}