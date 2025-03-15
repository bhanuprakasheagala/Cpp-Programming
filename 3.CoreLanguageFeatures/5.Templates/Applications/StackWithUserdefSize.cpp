#include <iostream>
#include <array>
#include <cassert>

template <typename T, std::size_t Maxsize>
class Stack {
private:
    std::array<T, Maxsize> elems;
    std::size_t numElements;

public:
    Stack();
    
    void push(T const& elem);
    void pop();
    T const& top() const;
    
    bool empty() const {
        return numElements == 0;
    }

    std::size_t size() const {
        return numElements;
    }

};

template <typename T, std::size_t Maxsize>
Stack<T, Maxsize>::Stack() : numElements(0) {}

template <typename T, std::size_t Maxsize>
void Stack<T, Maxsize>::push(T const& elem) {
    assert(numElements < Maxsize);
    elems[numElements] = elem;
    ++numElements;
}

template <typename T, std::size_t Maxsize>
void Stack<T, Maxsize>::pop() {
    assert(!elems.empty());
    --numElements;
}

template <typename T, std::size_t Maxsize>
T const& Stack<T, Maxsize>::top() const{
    assert(!elems.empty());
    return elems[numElements - 1];
}

int main()
{
    Stack<int, 20> int20Stack;
    Stack<int, 40> int40Stack;
    Stack<std::string, 30> stringStack;

    int20Stack.push(7);
    int20Stack.push(3);
    std::cout << int20Stack.top() << '\n';
    int20Stack.pop();
    std::cout << int20Stack.size() << '\n';
    int20Stack.pop();

    stringStack.push("hello");
    std::cout << stringStack.top() << '\n';
    stringStack.pop();

    return 0;
}

/*
Note that each template instantiation is its own type. Thus, int20Stack and int40Stack are two
different types, and no implicit or explicit type conversion between them is defined. Thus, one cannot
be used instead of the other, and you cannot assign one to the other.
*/