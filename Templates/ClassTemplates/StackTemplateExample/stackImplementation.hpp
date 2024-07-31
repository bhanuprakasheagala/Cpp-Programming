#include <cassert>
#include <vector>

template <typename T>
class Stack {
    private:
        std::vector<T> elems;       // elements
    
    public:
        void push(T const& elem);   // push elements
        void pop();                 // pop elements
        T const& top() const;       // return top elements
        bool empty() const {
            return elems.empty();   // return whether the stack is empty
        }
};

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);          // append copy of passed elem
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    //T elem = elems.back();
    elems.pop_back();              // remove last element
    //return elem;
}

template <typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();
}