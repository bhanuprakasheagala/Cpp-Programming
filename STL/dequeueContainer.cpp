/*
deque stands for double-ended queue. Deque containers are implemented as
dynamic arrays in such a way that the elements can be inserted at both ends.
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main() {

    std::deque<int> intDeq;
    std::ostream_iterator<int> screen(std::cout, " ");
    
    intDeq.push_back(13);
    intDeq.push_back(75);
    intDeq.push_back(28);
    intDeq.push_back(35);

    std::cout << "Deque: ";
    std::copy(intDeq.begin(), intDeq.end(), screen);
    std::cout << '\n';

    intDeq.push_front(12);
    intDeq.push_back(100);
    std::cout << "After adding two elements at front and back, Deque: \n";
    std::copy(intDeq.begin(), intDeq.end(), screen);
    std::cout << '\n';

    intDeq.pop_front();
    intDeq.pop_front();
    std::cout << "After removing the first two elements, Deque: \n";
    std::copy(intDeq.begin(), intDeq.end(), screen);
    std::cout << '\n';

    intDeq.pop_back();
    intDeq.pop_back();
    std::cout << "After removing the last two elements, Deque: \n";
    std::copy(intDeq.begin(), intDeq.end(), screen);
    std::cout << '\n';

    std::deque<int>::iterator deqIt;

    deqIt = intDeq.begin();
    ++deqIt; // deqIt points to the second element
    intDeq.insert(deqIt, 444);
    std::cout << "After inserting 444, Deque: \n";
    std::copy(intDeq.begin(), intDeq.end(), screen);
    std::cout << '\n';

    return 0;
}