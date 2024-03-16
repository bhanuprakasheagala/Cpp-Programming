#include <iostream>

// Choosing a hash function
#define CAPACITY 500 // Size of the HashTable
unsigned long hash_function(char *str) {
    unsigned long i = 0;

    for(int j=0; str[j]; j++) {
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

// Create items by allocating memory for a key and value, and return a pointer to the item
Ht_item* create_item(char* key, char* value) {
    Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
    item->key = (char*)malloc(strlen(key)+1);
    item->value = (char*)malloc(strlen(value)+1);
    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

// Create the table by allocating memory and setting size, count, and items
HashTable* create_table(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));

    for(int i=0; i<table->size; ++i) {
        table->items[i] = NULL;
    }

    return table;
}

// Write functions that free up a table item and the whole table
void free_item(Ht_item* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}
void free_table(HashTable* table) {
    // Frees the table
    for(int i=0; i<table->size; ++i) {
        Ht_item* item = table->items[i];
        if(item != NULL) {
            free_item(item);
        }
    }
    free(table->items);
    free(table);
}

// Print table
void print_table(HashTable* table) {
    printf("\nHashTable\n-----------------------\n");
    for(int i=0; i<table->size; ++i) {
        if(table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }

    printf("----------------------\n\n");
}

// Inserting into the HashTable
void ht_insert(HashTable* table, char* key, char* value) {
    // Creates the item
    Ht_item* item = create_item(key, value);

    // Computes the index
    int index = hash_function(key);

    Ht_item* current_item = table->items[index];

    if(current_item == NULL) {
        // Key does not exist
        if(table->count == table->size) {
            // HashTable is full
            printf("Insert Error: HashTable is full\n");
            free_item(item);
            return;
        }
        // Insert directly
        table->items[index] = item;
        table->count++;
    }
    else {
            // Scenario1: Key Value pair already exists. Update the item value to the new one.
            if(strcmp(current_item->key, key) == 0) {
                strcpy(table->items[index]->value, value);
                return;
            }
            else {
                // Scenario2: Handle the collision.
                handle_collision(table, item);
                return;
            }
        }
}

// Searching for an item in the HashTable
char* ht_search(HashTable* table, char* key) {
    // Searchs for the key in the HashTable. Returns NULL if it doesn't exist.
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    // Provide only non-null values
    if(item != NULL) {
        if(strcmp(item->key, key) == 0) {
            return item->value;
        }
    }

    return NULL;
}

// Display the item that matches the search key
void print_search(HashTable* table, char* key) {
    char* val;
    if((val = ht_search(table, key)) == NULL) {
        printf("Key: %s does not exist\n", key);
        return;
    }
    else {
        printf("Key: %s, Value: %s\n", key, val);
    }
}

int main()
{
    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, (char*)"1", (char*)"First address");
    ht_insert(ht, (char*)"2", (char*)"Second address");
    ht_insert(ht, (char*)"Hel", (char*)"Third address");
    ht_insert(ht, (char*)"lo", (char*)"Fourth address");

    print_search(ht, (char*)"1");
    print_search(ht, (char*)"2");
    print_search(ht, (char*)"4");

    print_table(ht);
    free_table(ht);
    print_table(ht);


    return 0;
}