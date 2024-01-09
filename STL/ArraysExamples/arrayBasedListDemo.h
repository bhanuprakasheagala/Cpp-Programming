#ifndef H_arrayBasedListDemo
#define H_arrayBasedListDemo

template <class elemType>

class arrayListType {
    public:
        // Overloads the assignment operator
        const arrayListType<elemType>& operator=(const arrayListType<elemType>&);
        
        // Function to determine whether the list is empty
        bool isEmpty() const;

        // Function to determine whether the list is full
        bool isFull() const;

        // Function to determine the number of elements in the list
        int listSize() const;

        // Function to determine the size of the list
        int maxListSize() const;

        // Function to output the elements of the list
        void print() const;

        // Function to determine whether the item is the same
        bool isItemAtEqual(int location, const elemType& item) const;

        // Function to insert an item in the list at the position specified by location
        void insertAt(int location, const elemType& insertItem);

        // Function to insert an item at the end of the list
        void insertEnd(const elemType& insertItem);

        // Function to remove the item from the list at the position specified by location
        void removeAt(int location);

        // Function to retrieve the element from the list at the position specified by location
        void retrieveAt(int location, elemType& retItem) const;

        // Function to replace the elements in the list at the position specified by location
        void replaceAt(int location, const elemType& repItem);

        // Function to remove all the elements from the list
        void clearList();

        // Function to search the list for a given item
        int seqSearch(const elemType& item) const;

        // Function to insert the item specified by the parameter at the end of the list
        // First, the list is searched to see whether the item to be inserted is already in the list
        void insert(const elemType& insertItem);

        // Function to remove an item from the list
        void remove(const elemType& removeItem);

        // Constructor with default array size of 100
        arrayListType(int size = 5);

        // Copy constructor
        arrayListType(const arrayListType<elemType>& otherList);

        // Destructor : Deallocates the memory occupied by Array
        ~arrayListType();

    protected:
        elemType *list;     // Array to hold the list elements
        int length;         // Current length of the array
        int maxSize;        // Maximum size of the array
};

#endif