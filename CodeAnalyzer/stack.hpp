#ifndef STACK
#define STACK

#include "linkedlist.hpp"

template<class T>
class Stack {
public:
    T pop();
    T peek();
    void push(T);
    bool isEmpty() const;
    int size() const;

private:
    LinkedList<T> data;
};

template <class T>
T Stack<T>::pop() {
    return data.remove(0);
}

template <class T>
T Stack<T>::peek() {
    return data.get(0);
}

template <class T>
void Stack<T>::push(T obj) {
    data.addToFront(obj);
}

template <class T>
bool Stack<T>::isEmpty () const {
    return data.size()==0;
}

template <class T>
int Stack<T>::size() const{
    return data.size();
}

#endif
