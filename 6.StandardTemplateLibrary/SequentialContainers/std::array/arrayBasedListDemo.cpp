#include <iostream>
#include <string>
#include <cassert>
#include "arrayBasedListDemo.h"

template <class elemType>
bool arrayListType<elemType>::isEmpty() const {
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const {
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const {
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const {
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const {
    for(int i=0; i<length; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << '\n';
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem) {
    if(location < 0 || location >= maxSize){
        std::cerr << "The given position is out of range\n";
    }
    else {
        if(length >= maxSize)
            std::cerr << "List is Full : Cannot insert\n";
        else {
            for(int i=length; i>location; --i) {
                list[i] = list[i-1]; // Move the elements down
            }
            list[location] = insertItem;
            length++;
        }
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem) {
    if(length >= maxSize) {
        std::cerr << "List is full : Cannot insert\n";
    }
    else {
        list[length] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location) {
    if(location < 0 || location >= maxSize) {
        std::cerr << "The given position is out of range\n";
    }
    else {
        for(int i=location; i<length-1; ++i)
            list[i] = list[i+1]; // Move the elements up to fill the removed slot in the middle
        length--;
    }
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const {
    if(location < 0 || location >= length) {
        std::cerr << "The location of the item to be retrieved is out of range\n";
    }
    else {
        retItem = list[location];
    }
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem) {
    if(location < 0 || location >= length) {
        std::cerr << "The location of the item to be retrieved is out of range\n";
    }
    else {
        list[location] = repItem;
    }
}

template <class elemType>
void arrayListType<elemType>::clearList() {
    length = 0;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size) {
    if(size < 0) {
        std::cerr << "The array size must be positive. Creating an array of size 5. \n";
        maxSize = 5;
    }
    else {
        maxSize = size;
    }
    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType() {
    delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList) {
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize];
    assert(list != NULL);

    for(int j=0; j<length; ++j)
        list[j] = otherList.list[j];
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList) {
    if(this != &otherList) {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];
        assert(list != NULL);

        for(int i=0; i<length; ++i)
            list[i] = otherList.list[i];
    }
    return *this;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const {
    int loc;
    bool found = false;
    for(loc = 0; loc < length; ++loc) {
        if(list[loc] == item){
            found = true;
            break;
        }
    }
    if(found)
        return loc;
    else
        return -1;
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem) {
    int loc;
    if(length == 0) {
        list[length++] = insertItem;
    }
    else if(length == maxSize) {
        std::cerr << "Cannot insert in a full list\n";
    }
    else {
        loc = seqSearch(insertItem);
        if(loc == -1) {
            list[length++] = insertItem;
        }
        else {
            std::cerr << "The item to be inserted is already present in the list\n";
        }
    }
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem) {
    if(length == 0)
        std::cerr << "Cannot delete from the empty list\n";
    else {
        int loc = seqSearch(removeItem);
        if(loc != -1) {
            removeAt(loc);
        }
        else {
            std::cerr << "The item to be deleted is not in the list\n";
        }
    }
}

int main() {
    arrayListType<int> intList(10);
    arrayListType<std::string> stringList(7);

    int number;
    std::cout << "Enter 5 integers: ";
    for(int i=0; i<5; ++i) {
        std::cin>>number;
        intList.insertAt(i, number);
    }
    std::cout << "\n";
    std::cout << "The list you've entered is: ";
    intList.print();
    std::cout << "\n";
    std::cout << "Enter the item to be deleted: ";
    std::cin >> number;
    intList.remove(number);
    std::cout << "The list is: ";
    intList.print();
    std::cout << "\n";
    std::cout << "List size: " << intList.listSize() << '\n';
    std::cout << "Max list size: " << intList.maxListSize() << '\n';
    intList.insert(78);
    intList.print();

    std::string str;
    std::cout << "Enter 5 strings: ";
    for(int i=0; i<5; ++i) {
        std::cin>>str;
        stringList.insertAt(i, str);
    }
    std::cout << "\nEntered list of strings: \n";
    stringList.print();
    
    std::cout << "\nEnter the item to be deleted: ";
    std::cin >> str;
    stringList.remove(str);
    std::cout << "The list is: ";
    stringList.print();
    std::cout << '\n';

    return 0;
}
