#include <iostream>

template <typename Object>
class Vector {
    private:
        int theSize;
        int theCapacity;
        Object* objects;
    
    public:
        explicit Vector(int initSize = 0) : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY) {
            objects = new Object[theCapacity];
        }

        Vector(const Vector& rhs) : objects(nullptr) {
            operator=(rhs);
        }

        ~Vector() {
            delete[] objects;
        }

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

        void resize(int newSize) {
            if(newSize > theCapacity)
                reserve(newSize * 2 + 1);

            theSize = newSize;
        }

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

        Object& operator[](int index) {
            return objects[index];
        }

        const Object& operator[](int index) const {
            return objects[index];
        }

        bool empty() const {
            return size() == 0;
        }

        int size() const {
            return theSize;
        }

        int capacity() const {
            return theCapacity;
        }

        void push_back(const Object& data) {
            if(theSize == theCapacity)
                reserve(2 * theCapacity + 1);

            objects[theSize++] = data;
        }

        void pop_back() {
            theSize--;
        }

        const Object& back() const {
            return objects[theSize - 1];
        }

        typedef Object* iterator;
        typedef const Object* const_iterator;

        iterator begin() {
            return &objects[0];
        }

        const_iterator begin() const {
            return &objects[0];
        }

        iterator end() {
            return &objects[size()];
        }

        const_iterator end() const {
            return &objects[size()];
        }

        enum {SPARE_CAPACITY = 16};

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
    Vector<int> myVect;
    myVect.push_back(56);
    myVect.push_back(334);
    myVect.push_back(132);
    myVect.myDisplay();

    return 0;
}