#include <iostream>
#include <vector>

int main() {

    std::vector<int> intList;

    intList.push_back(2);
    intList.push_back(56);
    intList.push_back(78);
    intList.push_back(10);

    std::cout << "List elements: \n";
    for(int& x : intList){
        std::cout << x << " ";
    }
    std::cout << '\n';
    std::cout << "intList capacity: " << intList.capacity() << '\n';

    for(int i=0; i<intList.size(); ++i) {
        intList[i] *= 2;
    }
    std::cout << "List elements: \n";
    for(int& x : intList){
        std::cout << x << " ";
    }
    intList.pop_back();
    std::cout << '\n';
    std::cout << "intList max_size: " << intList.max_size() << '\n';

    std::vector<int>::iterator listIt;
    for(listIt = intList.begin(); listIt != intList.end(); ++listIt) {
        std::cout << *listIt << " ";
    }
    std::cout << '\n';

    int position, newElement;
    std::cout << "Enter the position at which new element needs to be inserted: ";
    std::cin >> position;
    std::cout << "Enter the element: ";
    std::cin >> newElement;
    intList.insert(intList.begin()+position, newElement);
    
    for(listIt = intList.begin(); listIt != intList.end(); ++listIt) {
        std::cout << *listIt << " ";
    }
    std::cout << '\n';

    std::cout << "Reverse list: \n";
    std::vector<int>::reverse_iterator rlistIt;
    for(rlistIt = intList.rbegin(); rlistIt != intList.rend(); ++rlistIt) {
        std::cout << *rlistIt << " ";
    }
    std::cout << '\n';

    return 0;
}