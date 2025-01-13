#include <iostream>
#include <forward_list>

// Function to print a forward list
void print_forward_list(const std::forward_list<int>& list) {
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::forward_list<int> list1 = {1, 2, 3, 4, 5};
    std::cout << "List1 : ";
    print_forward_list(list1);

    list1.push_front(0); // Insert at front of the list
    list1.push_front(-1); // Insert at front of the list
    std::cout << "list1 after inserting 0 and then -1: ";
    print_forward_list(list1);

    // Removing an element
    list1.pop_front(); // Remove the first element
    std::cout << "list1 after removing first element: ";
    print_forward_list(list1);


    // Insert after a specific element
    auto it = list1.begin();
    list1.insert_after(it, 10); // Insert 10 after the first element
    advance(it, 3);
    list1.insert_after(it, 20); // Insert 20 after the fourth element
    std::cout << "list after inserting 10 and 20: ";
    print_forward_list(list1);


    std::forward_list<int> list2 = {6, 7, 8, 9, 8, 10};
    std::cout << "List2 : ";
    print_forward_list(list2); 
    list2.remove(8); // Remove all elements with value 8
    std::cout << "list2 after removing all 8: ";
    print_forward_list(list2);

    // Remove elements after a specific position
    auto it2 = list2.begin();
    advance(it2, 2);
    list2.erase_after(it2); // Remove the element after third element
    std::cout << "list2 after removing element after 3rd element: ";
    print_forward_list(list2);

    list1.reverse(); // Reverse the order of elements
    std::cout << "list1 after reversing: ";
    print_forward_list(list1);

    list2.sort(); // Sort the elements in ascending order
    std::cout << "list2 after sorting: ";
    print_forward_list(list2);

    return 0;
}