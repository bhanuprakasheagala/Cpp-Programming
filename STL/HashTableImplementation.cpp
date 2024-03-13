#include <iostream>

// Choosing a hash function
constexpr CAPACITY 500; // Size of the HashTable
unsigned long hash_function(char *str) {
    unsigned long i = 0;

    for(int i=0; str[j]; j++) {
        i += str[j];
    }

    return i%CAPACITY;
}

// Defining HashTable Data structure
typedef struct Ht_item {
    char* key;
    char* value;
}Ht_item;

// Now, the HashTable has an array of pointers that point to Ht_item, so it is a double-pointer
typedef struct HashTable {
    // Contains an array of pointers to items
    Ht_item** items;
    int size;
    int count;
} HashTable;

int main()
{
    
    return 0;
}