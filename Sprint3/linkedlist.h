#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

template <class T>
class ListNode {
public:

    ListNode();
    ListNode(T);

    ListNode<T>* getNext() const;
    void setNext(ListNode<T>*);
    ListNode<T>* getPrev() const;
    void setPrev (ListNode<T>*);

    T& getData();
    void setData(T);


private:
    ListNode<T>*next;
    ListNode<T>*prev;
    T data;
};


template<class T>
class LinkedList {

public:

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    void addToBack(const T &);
    void addToFront(T);
    void addToIndex (T,int);
    void addAfter (T, ListNode<T>*);
    void addBefore (T, ListNode<T>*);

    T remove(int);

    T get(int) const;
    int size() const;
    bool isEmpty() const;

    void printList() const;

    ~LinkedList();

    T& operator[] (int);
    LinkedList<T>& operator=(const LinkedList<T>&);

private:

    ListNode<T>* start;
    int num_elements;

};


/*
 * ListNode Class Implementation
 *
 */
template<class T>
ListNode<T>::ListNode(){
    next = 0;
    prev = 0;
}

template<class T>
ListNode<T>::ListNode(T payload){
    data = payload;
    next = 0;
    prev = 0;
}

template<class T>
ListNode<T>* ListNode<T>::getNext() const{
    return next;
}

template<class T>
void ListNode<T>::setNext(ListNode<T>* newval){
    next = newval;
}

template<class T>
ListNode<T>* ListNode<T>::getPrev() const{
    return prev;
}

template<class T>
void ListNode<T>::setPrev (ListNode<T>* newval){
    prev = newval;
}

template<class T>
T& ListNode<T>::getData(){
    return data;
}

template<class T>
void ListNode<T>::setData(T newval){
    data = newval;
}


/* LinkedList Class Implementation
 *
 *
 */

//Constructors
template<class T>
LinkedList<T>::LinkedList() {
    start = 0;
    num_elements = 0;
}

template<class T>
LinkedList<T>::LinkedList(T obj){
    start = new ListNode<T> (obj);
    num_elements=1;
}

//Copy Constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
    num_elements=0;
    start = 0;
//    if (num_elements==0){
//        //Empty list, do nothing
//    }
//    else if (num_elements==1){
//        if (start!=0) delete start;
//        start=0;
//    }
//    else{

//    }


    if (rhs.size()==1){
        addToBack(rhs.start->getData());
    }
    else {
        if (rhs.start!=0){
            ListNode<T>* curr = rhs.start;
            while (curr!=0){
                addToBack(curr->getData());
                curr = curr->getNext();
            }
        }
    }
}

//Functions for adding elements

template<class T>
void LinkedList<T>::addToBack(const T& obj) {
    if (start==0){
        //If empty, insert at the beginning
        start = new ListNode<T> (obj);
        num_elements=1;
    }
    else if (num_elements==1) {
        addAfter(obj,start);
    }
    else{
        //Find the last entry
        ListNode<T> * curr = start;
        while (curr->getNext()!=0){
            curr = curr->getNext();
        }
        addAfter(obj, curr);
    }
}

template<class T>
void LinkedList<T>::addToFront(T obj) {
    if (start==0){
        start = new ListNode<T> (obj);
        num_elements++;
    }
    else{
        ListNode<T> * temp = new ListNode<T>(obj);
        temp->setNext(start);
        start->setPrev(temp);
        start = temp;
        num_elements++;
    }
}

template<class T>
void LinkedList<T>::addToIndex(T obj, int index){
    //@TODO: Check for out of bounds
    if (index==0){
        addToFront(obj);
        return;
    }
    else if (index == num_elements-1){
        addToBack(obj);
        return;
    }
    else{
        //Add to middle of list
        ListNode<T> * curr = start;
        int i=0;
        while (curr->getNext()!=0){
            if (i==(index-1)) break;
            else {
                i++;
                curr = curr->getNext();
            }
        }
        addAfter(obj, curr);
    }
}

template<class T>
void LinkedList<T>::addAfter(T obj, ListNode<T> * curr){
    if (curr!=0){
        ListNode<T> * temp = new ListNode<T> (obj);
        temp->setPrev(curr);
        temp->setNext(curr->getNext());
        curr->setNext(temp);
        temp->getPrev()->setPrev(temp);
    }
    num_elements++;
}

template<class T>
void LinkedList<T>::addBefore(T obj, ListNode<T> * curr){
    if (curr!=0){
        ListNode<T> * temp = new ListNode<T> (obj);
        temp->setPrev(curr->getPrev());
        temp->setNext(curr);
        curr->setPrev(temp);
        curr->getPrev()->setNext(temp);
    }
    num_elements++;
}

//Remove an element
template<class T>
T LinkedList<T>::remove(int index){
    T return_val;
    //If the list is already empty
    if (num_elements==0){
        //Removing from empty list, returns default object;
        return return_val;
    }
    //If removing the first element in a single-element lsit
    else if (index==0 && num_elements==1){
        return_val = start->getData();
        delete start;
        start = 0;
        num_elements--;
        return return_val;
    }
    //If removing first element of a longer list
    else if (index==0 && start!=0){
        return_val = start->getData();
        ListNode<T> * toDelete = start;
        start = start->getNext();
        delete toDelete;
        num_elements--;
        return return_val;
    }

    //If removing last element
    else if (index==num_elements-1){
        ListNode<T> * curr = start;

        while (curr->getNext()!=0){
            curr = curr->getNext();
        }

        return_val=curr->getData();

        curr->getPrev()->setNext(0);
        delete curr;
        num_elements--;
        return return_val;
    }
    //If removing element in the middle
    else{

        ListNode<T> * curr = start;

        //Loop through the list to get the address of the item at index
        for (int i=0;i<num_elements && i<index;i++){
            curr = curr->getNext();
        }
        //std::cout<<"Curr:"<<curr->getData()<<" Curr->Next: "<<curr->getNext()->getData()<<" Curr->Prev: "<<curr->getPrev()->getData()<<std::endl;

        return_val = curr->getData();
        curr->getNext()->setPrev(curr->getPrev());
        curr->getPrev()->setNext(curr->getNext());

        delete curr;
        num_elements--;
        return return_val;
    }

    return return_val;
}

//Get an element at index
template<class T>
T LinkedList<T>::get(int index) const{
    int i=0;
    ListNode<T> * curr = start;
    if (num_elements==0){
        return T();
    }
    else if (num_elements==1){
        return curr->getData();
    }
    else {
        while (curr->getNext()!=0 && i<index){
            curr = curr->getNext();
            i++;
        }
    }
    return curr->getData();
}

//Return the length of the list
template<class T>
int LinkedList<T>::size() const{
    return num_elements;
}

//Checks if the list is empty
template<class T>
bool LinkedList<T>::isEmpty() const{
    if (num_elements==0) return true;
    return false;
}

//Destructor
template<class T>
LinkedList<T>::~LinkedList(){
    if (start!=0){
        while (start!=0){
            remove(0);
        }
    }
}

template <class T>
void LinkedList<T>::printList() const{
    if (start !=0){
        ListNode<T> * curr = start;
        while (curr!=0) {
            std::cout<<curr->getData()<<std::endl;
            curr = curr->getNext();
        }
    }
    else{
        std::cout<<"List was empty"<<std::endl;
    }
    std::cout<<"Finished Printing"<<std::endl;
}

template<class T>
T& LinkedList<T>::operator[] (int index){
    int i=0;
    ListNode<T> * curr = start;

    while (curr->getNext()!=0 && i<index){
        curr = curr->getNext();
        i++;
    }

    return curr->getData();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
    //delete this;
    if(rhs.start!=0){
        ListNode<T> * curr = rhs.start;
        while (curr->getNext()!=0) {
            T dataToAdd = curr->getData();
            addToBack(dataToAdd);
            curr = curr->getNext();
        }
    }
    else {
        //Right hand side is empty
        //@TODO: Do something here?
    }

    return *this;
}


#endif
