#ifndef VECTOR
#define VECTOR

template <class T>
class Vector{
public:
    //Constructors
    Vector();
    Vector(int);
    Vector(const Vector<T>&);

    //Add and Get
    void add(T );
    void add(T, int);
    T get(int) const;


    int size() const;
    void sort();
    void swap(int, int);
    void reverse();

    void clear();
    void remove(int);
    void shrink_to_fit();

    //Return Data pointer
    T* getData ();

    //Return front and back
    T front() const;
    T back() const;

    T& operator[] (int) const;
    Vector<T>& operator=(const Vector<T>&);
    Vector<T>& operator+=(T);
    Vector<T>& operator += (Vector<T>);

    bool operator==(const Vector<T>&) const;

    //Destructor
    ~Vector();

private:
    void resize();
    void shiftRight(int);
    void shiftLeft(int);
    T * data;
    int capacity;
    int len;
};

//Default Constructor
template<class T>
Vector<T>::Vector(){
    len=0;
    capacity = 10;
    data = new T [capacity];
}

template<class T>
Vector<T>::Vector(int cap){
    len = 0;
    capacity=cap;
    data = new T [capacity];
}

//Copy Constructor
template<class T>
Vector<T>::Vector(const Vector<T>& rhs){
    len = rhs.len;
    capacity = rhs.capacity;
    data = new T [capacity];

    for (int i=0;i<capacity;i++) {
        data[i]=rhs.data[i];
    }

}

//Add Element
template<class T>
void Vector<T>::add(T newElement){
   if(len>=capacity) {
        resize();
    }
     data[len]=newElement;
     len+=1;
}

//Add Element to specific index
template<class T>
void Vector<T>::add(T newElement, int index){
    if(len>=capacity) {
         resize();
     }
    shiftRight(index);

    data[index]=newElement;
}

//Get object at index
template <class T>
T Vector<T>::get(int index) const{
    //@TODO: Gracefully handle out of bounds
    return data[index];
}

//Destructor
template <class T>
Vector<T>::~Vector(){
    delete[] data;
}

//Size function
template <class T>
int Vector<T>::size() const {
    return len;
}

//Sort Vector
template <class T>
void Vector<T>::sort() {
    //Super naive selection sort. Make something faster

    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    for (int j = 0; j < len-1; j++) {
        /* find the min element in the unsorted a[j .. n-1] */

        /* assume the min is the first element */
        int iMin = j;
        /* test against elements after j to find the smallest */
        for (int i = j+1; i < len; i++) {
            /* if this element is less, then it is the new minimum */
            if (data[i] < data[iMin]) {
                /* found new minimum; remember its index */
                iMin = i;
            }
        }

        if(iMin != j) {
            swap(j,iMin);
        }
    }

}

//Swap Elements
template <class T>
void Vector<T>::swap(int a, int b) {
    T working = data[a];
    data[a]=data[b];
    data[b]=working;
}

template <class T>
void Vector<T>::reverse(){
    int high = len-1;
    int low = 0;

    while (high>low) {
        swap (low,high);
        high--;
        low++;
    }
}

template <class T>
void Vector<T>::clear() {
    //Deletes the curent array of data
    delete[]data;
    //Creates a new length of data using the original capacity
    data = new T [capacity];
    //Vector is now empty, length should be zero
    len=0;
}

template <class T>
void Vector<T>::remove(int index) {
    shiftLeft(index);
}

template <class T>
void Vector<T>::shrink_to_fit(){
    //Create working array and copy data into it
    T * working = new T [len];

    for (int i=0;i<len;i++) {
        working [i]=data[i];
    }

    //Clear the old data pointer and create a new one of the correct length
    delete[]data;
    data = working;

    //Update capacity variable
    capacity = len;
}

template <class T>
T* Vector<T>::getData(){
    return data;
}

template <class T>
T Vector<T>::front() const{
    return data[0];
}

template <class T>
T Vector<T>::back() const {
    return data[len-1];
}

//Resize Array
template <class T>
void Vector<T>::resize(){
    //Create working array that is 1.5 times the size of the old one
   int new_size;
    if (capacity==1){
        new_size=2;
    }
    else{
        new_size = capacity * 4;
    }
    T * new_data = new T [new_size];

    //Load old data into the working array
    for (int i=0;i<capacity;i++) {
        new_data[i] = data[i];
    }

    //Delete the old array and reassign the data pointer
    delete[]data;
    data = new_data;

    //Update capacity
    capacity = new_size;
}

//Shift elements right, beginning with given index
template <class T>
void Vector<T>::shiftRight(int index) {
    //Method creates a empty space at the given index by shifting all elements one place to the right

    if (len==capacity) {
        resize();
    }

    len+=1;
    for (int i=len-1;i>index;i--) {
        swap(i-1,i);
    }

}

//Shift elements left, beginning with given index
template <class T>
void Vector<T>::shiftLeft(int index) {
    //Method overwrites the value at the given index by shifting all other elements one place to the left

    if(len == capacity) {
        resize();
    }

    for (int i=index;i<len;i++) {
        data[i]=data[i+1];
    }

    len-=1;
}

//[] Operator
template <class T>
T& Vector<T>::operator[](int index) const {
    return data[index];
}

//Assignment Operator
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
    len = rhs.len;
    capacity = rhs.capacity;

    //Copy all elements
    data = new T [capacity];
    for (int i=0;i<len;i++){
        data[i] = rhs.data[i];
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(T rhs){
    this->add(rhs);
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator += (Vector<T> rhs) {
    for (int i=0;i<rhs.len;i++) {
        add(rhs[i]);
        return *this;
    }
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& rhs) const {
    if (len!=rhs.len) {
        return false;
    }
    if (capacity!=rhs.capacity) {
        return false;
    }
    for (int i=0;i<len;i++) {
        if (data[i]!=rhs.data[i]){
            return false;
        }
    }
    return true;
}

#endif
