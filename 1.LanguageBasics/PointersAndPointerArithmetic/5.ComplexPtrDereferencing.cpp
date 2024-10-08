#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30};
    int* ptr = arr;
    int** ptr_to_ptr = &ptr;

    std::cout << "Address of ptr(Base address of arr): " << ptr << '\n';
    std::cout << "Value using **ptr_to_ptr: " << **ptr_to_ptr << '\n';
    ptr++; // Ptr is points to next address
    std::cout << "Address after incrementing the Ptr: " << ptr << '\n';
    std::cout << "Value after incrementing the Ptr: " << **ptr_to_ptr << '\n';

    ++*ptr; // The value Ptr points to is incremented
    std::cout << "Value after ++*ptr: " << **ptr_to_ptr << '\n';

    return 0;
}