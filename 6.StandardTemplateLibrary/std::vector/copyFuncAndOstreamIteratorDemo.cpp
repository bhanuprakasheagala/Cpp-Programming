#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
/*
    The function copy can be used to output the elements of a container.
    In this case, an iterator of type ostream specifies the destination.

    `ostream_iterator<int> screen(cout, " ")`
    This statement creates screen to be an ostream iterator with the element type int.
    The iterator screen has two arguments: the object cout and a space. Thus,
    the iterator screen is initialized using the object cout, and when this iterator outputs
    the elements, they are separated by a space.The statement
    `copy(intArray, intArray+9, screen)` 
    outputs the elements of intArray on the screen. Similarly, the statement
    `copy(vecList.begin(), vecList.end(), screen)`
    outputs the elements of the container vecList on the screen.
*/
int main() {

    int arr[] = {5,6,7,8,9,10,11,12,56};
    std::vector<int> vecList(9);
    std::ostream_iterator<int> screen(std::cout, " ");

    std::cout << "Array: ";
    std::copy(arr, arr+9, screen);
    std::cout << '\n';

    // Copy arr from 0 to n-1 into vecList
    std::copy(arr, arr+9, vecList.begin());

    std::cout << "vecList: ";
    std::copy(vecList.begin(), vecList.end(), screen);
    std::cout << '\n';

    // Copies arr from index 1 to n-1 into arr(from index 0) which is equivalent to
    // Shifting the elements one position to the left.
    std::copy(arr+1, arr+9, arr);
    std::cout << "After shifting the elements one position to the left, arr: \n";
    std::copy(arr, arr+9, screen); // Output the arr using copy and iterator
    std::cout << '\n';

    // Copies vecList from index n-2 to 0 into vecList(from index 0) which is equivalent to
    // Shifting the elements two positions to the right.
    std::copy(vecList.rbegin()+2, vecList.rend(), vecList.rbegin());
    std::cout << "After shifting the elements down by two positions, vecList: \n";
    std::copy(vecList.begin(), vecList.end(), screen); // Using copy function to output elements
    std::cout << '\n';

    return 0;
}