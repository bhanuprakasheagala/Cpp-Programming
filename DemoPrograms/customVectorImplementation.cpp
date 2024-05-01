#include <iostream>

template <typename Object>
class Vector {
    private:
        int theSize; // Current number of elements in the vector
        int theCapacity; // Current capacity of the vector
        Object* objects; // Pointer to the dynamically allocated array
    
    public:
        // Constructor: Initializes theSize and theCapacity, allocates memory for objects
        explicit Vector(int initSize = 0) : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY) {
            objects = new Object[theCapacity];
        }

        // Copy constructor: Copies the contents of another vector
        Vector(const Vector& rhs) : objects(nullptr) {
            operator=(rhs);
        }

        // Destructor: Frees the dynamically allocated memory
        ~Vector() {
            delete[] objects;
        }

        // Copy assignment operator: Copies the contents of another vector
        const Vector& operator=(const Vector& rhs) {
            if(this != &rhs) {
                delete[] objects;
                theSize = rhs.size();
                theCapacity = rhs.theCapacity;

                objects = new Object[capacity()];
                for(int i=0; i<size(); i++)
                    objects[i] = rhs.objects[i];
            }
            return *this;
        }

        // Resize the vector to a new size
        void resize(int newSize) {
            if(newSize > theCapacity)
                reserve(newSize * 2 + 1);

            theSize = newSize;
        }

        // Reserve memory for a certain capacity
        void reserve(int newCapacity) {
            if(newCapacity < theSize)
                return;

            Object* oldArray = objects;

            objects = new Object[newCapacity];
            for(int i=0; i<theSize; i++)
                objects[i] = oldArray[i];
            theCapacity = newCapacity;

            delete[] oldArray;
        }

        // Accessor for elements by index
        Object& operator[](int index) {
            return objects[index];
        }

        const Object& operator[](int index) const {
            return objects[index];
        }

        // Check if the vector is empty
        bool empty() const {
            return size() == 0;
        }

        // Get the current size of the vector
        int size() const {
            return theSize;
        }

        // Get the current capacity of the vector
        int capacity() const {
            return theCapacity;
        }

        // Add an element to the end of the vector
        void push_back(const Object& data) {
            if(theSize == theCapacity)
                reserve(2 * theCapacity + 1);

            objects[theSize++] = data;
        }

        // Remove the last element from the vector
        void pop_back() {
            theSize--;
        }

        // Access the last element of the vector
        const Object& back() const {
            return objects[theSize - 1];
        }

        // Iterator typedefs
        typedef Object* iterator;
        typedef const Object* const_iterator;

        // Iterator for the beginning of the vector
        iterator begin() {
            return &objects[0];
        }

        const_iterator begin() const {
            return &objects[0];
        }

        // Iterator for the end of the vector
        iterator end() {
            return &objects[size()];
        }

        const_iterator end() const {
            return &objects[size()];
        }

        // Spare capacity constant
        enum {SPARE_CAPACITY = 16};

        // Custom display function
        void myDisplay() {
            std::cout << "Vector elements: \n";
            for(int i=0; i<theSize; i++) {
                std::cout << objects[i] << " ";
            }
            std::cout << '\n';
        } 
};

int main()
{
    // Test the Vector class
    Vector<int> myVect;
    myVect.push_back(56);
    myVect.push_back(334);
    myVect.push_back(132);
    myVect.myDisplay();
    std::cout << "The first element " << *(myVect.begin()) << '\n';
    std::cout << "The last element " << *(myVect.end()-1) << '\n';
    std::cout << "Pop the last element!!\n";
    myVect.pop_back();
    myVect.myDisplay();
    std::cout << "Is vector empty? ";
    if((myVect.empty()) != 0) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    return 0;
}