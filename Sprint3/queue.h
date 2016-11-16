#ifndef QUEUE
#define QUEUE

#include "linkedlist.h"

template<class T>
class Queue{

    public:

        T dequeue();
        T peek();
        void enqueue(T);
        bool isEmpty() const;
        int size() const;

    private:

        LinkedList<T> data;

};

template <class T>
T Queue<T>::dequeue() {
    return data.remove(0);
}

template <class T>
T Queue<T>::peek() {
    return data.get(0);
}

template <class T>
void Queue<T>::enqueue(T obj){
    data.addToBack(obj);
}

template <class T>
bool Queue<T>::isEmpty() const{
    return data.size()==0;
}

template <class T>
int Queue<T>::size() const{
    return data.size();
}

#endif
