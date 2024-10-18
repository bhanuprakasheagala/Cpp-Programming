#include <iostream>
#include <cassert>

template<typename T>
class DynamicArray {
    private:
        size_t size;
        size_t capacity;
        T* data;

        void resize() {
            capacity *= 2;
            T* newData = new T[capacity];
            for(size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }
    
    public:
        DynamicArray() : size(0), capacity(1), data(new T[capacity]) {}
        ~DynamicArray() {
            delete[] data;
        }

        void addElement(T elem) {
            if(size == capacity) {
                resize();
            }
            data[size++] = elem;
        }

        T get(int index) {
            assert(index >= 0 && index < size);
            return data[index];
        }
};

int main()
{
    DynamicArray<int> dArr;
    dArr.addElement(5);
    dArr.addElement(19);

    std::cout << "Element at index 0: " << dArr.get(0) << '\n';
    std::cout << "Element at index 1: " << dArr.get(1) << '\n';

    DynamicArray<std::string> strArr;
    strArr.addElement("String1");
    strArr.addElement("String2");

    std::cout << "Index 0 of String Array: " << strArr.get(0) << '\n';

    return 0;
}