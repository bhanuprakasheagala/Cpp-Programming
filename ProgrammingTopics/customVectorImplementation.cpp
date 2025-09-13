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
    
    // 1. Create a vector of integers with Default Constructor. Here it will call the constructor with initSize = 0
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

    // 2. Create a vector of doubles with Parameterized Constructor
    Vector<double> myVect2(5); // Initial size of 5
    for(int i=0; i<5; i++) {
        myVect2[i] = i * 1.1; // Assign values to the elements
    }
    myVect2.myDisplay();
    std::cout << "Size: " << myVect2.size() << '\n';
    std::cout << "Capacity: " << myVect2.capacity() << '\n';
    std::cout << "Resizing the vector to size 8\n";
    myVect2.resize(8); // Resize to 8
    myVect2.myDisplay();
    std::cout << "Capacity after resizing: " << myVect2.capacity() << '\n';
    std::cout << "Reserving capacity for 20 elements\n";
    myVect2.reserve(20); // Reserve capacity for 20 elements
    std::cout << "Capacity after reserving: " << myVect2.capacity() << '\n';

    // 3. Create a vector of strings with Parameterized Constructor
    Vector<std::string> myVect3(3); // Initial size of 3
    myVect3[0] = "Hello";
    myVect3[1] = "World";
    myVect3[2] = "C++23";
    myVect3.myDisplay();
    std::cout << "Adding another string to the vector\n";
    myVect3.push_back("Programming");
    myVect3.myDisplay();
    std::cout << "Size: " << myVect3.size() << '\n';
    std::cout << "Capacity: " << myVect3.capacity() << '\n';
    std::cout << "Last element: " << myVect3.back() << '\n';

    // 4. Using Copy Constructor
    Vector<std::string> myVect4 = myVect3; // Calls copy constructor
    std::cout << "Contents of copied vector:\n";
    myVect4.myDisplay();
    std::cout << "Size of copied vector: " << myVect4.size() << '\n';
    std::cout << "Capacity of copied vector: " << myVect4.capacity() << '\n';
    std::cout << "Modifying the original vector\n";
    myVect3.push_back("NewString");
    std::cout << "Original vector after modification:\n";
    myVect3.myDisplay();
    std::cout << "Copied vector remains unchanged:\n";
    myVect4.myDisplay();

    // 5. Using Copy Assignment Operator
    Vector<std::string> myVect5;
    myVect5 = myVect3; // Calls copy assignment operator
    std::cout << "Contents of assigned vector:\n";
    myVect5.myDisplay();
    std::cout << "Size of assigned vector: " << myVect5.size() << '\n';
    std::cout << "Capacity of assigned vector: " << myVect5.capacity() << '\n';
    std::cout << "Modifying the original vector again\n";
    myVect3.push_back("AnotherString");
    std::cout << "Original vector after modification:\n";
    myVect3.myDisplay();
    std::cout << "Assigned vector remains unchanged:\n";
    myVect5.myDisplay();

    return 0;
}

/*
Output:

Vector elements: 
56 334 132 
The first element 56
The last element 132
Pop the last element!!
Vector elements: 
56 334 
Is vector empty? No
Vector elements: 
0 1.1 2.2 3.3 4.4 
Size: 5
Capacity: 21
Resizing the vector to size 8
Vector elements: 
0 1.1 2.2 3.3 4.4 0 0 0 
Capacity after resizing: 21
Reserving capacity for 20 elements
Capacity after reserving: 20
Vector elements: 
Hello World C++23 
Adding another string to the vector
Vector elements: 
Hello World C++23 Programming 
Size: 4
Capacity: 19
Last element: Programming
Contents of copied vector:
Vector elements: 
Hello World C++23 Programming 
Size of copied vector: 4
Capacity of copied vector: 19
Modifying the original vector
Original vector after modification:
Vector elements: 
Hello World C++23 Programming NewString 
Copied vector remains unchanged:
Vector elements: 
Hello World C++23 Programming 
Contents of assigned vector:
Vector elements: 
Hello World C++23 Programming NewString 
Size of assigned vector: 5
Capacity of assigned vector: 19
Modifying the original vector again
Original vector after modification:
Vector elements: 
Hello World C++23 Programming NewString AnotherString 
Assigned vector remains unchanged:
Vector elements: 
Hello World C++23 Programming NewString 
*/