#ifndef BAG
#define BAG

#include <iostream>
#include <sstream>
#include <cassert>

template <class T>
class Bag {
public:
    Bag();
    Bag(const Bag& other);
    Bag<T>& operator=(const Bag& other);
    Bag<T> extractAll(const T& item);

    ~Bag();

    T getSize() const;
    T getCapacity() const;
    T pickRandom();

    void addItem(const T& item);
    bool contains(const T& item) const;
    bool removeItem(const T& item);
    bool isEmpty() const;
    void dump();
    int numberOf(const T& item) const;
    void removeAll(const T& item);
    void dumpInto(Bag<T>& other);

    template <class R>
    friend std::ostream& operator<<(std::ostream& out, const Bag<R>& myBag);

private:
    T* elements;
    int size;
    int capacity;
    void grow();
};

//Constructor//
template <class T>
Bag<T>::Bag()
    : size(0), capacity(10) {
    elements = new T[capacity];
}

//Copy Constructor//
template <class T>
Bag<T>::Bag(const Bag& other) {
    capacity = other.capacity;
    size = other.size;
    elements = new T[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

//Assignment Operator//
template <class T>
Bag<T>& Bag<T>::operator=(const Bag& other) {
    if (this != &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        delete [] elements;
        elements = new T[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

//Destructor//
template <class T>
Bag<T>::~Bag() {
    delete [] elements;
}

//Functions//

//Get Size//
template<class T>
T Bag<T>::getSize() const {
    return size;
}

//Get Capacity//
template<class T>
T Bag<T>::getCapacity() const {
    return capacity;
}

//Grow Capacity//
template <class T>
void Bag<T>::grow() {
    if (size >= capacity) {
        T* old = elements;
        capacity = size * 2;
        elements = new T[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = old[i];
        }
        delete [] old;
    }
}

//Add Item//
template <class T>
void Bag<T>::addItem(const T& item) {
    if (size >= capacity) {
        grow();
        elements[size] = item;
        size++;
    }
    else {
        elements[size] = item;
        size++;
    }
}

//Contains?//
template <class T>
bool Bag<T>::contains(const T& item) const {
    for (int i = 0; i < size; i++) {
        if (this->elements[i] == item) {
            return true;
        }
    }
    return false;
}

//Remove Item//
template <class T>
bool Bag<T>::removeItem(const T& item) {
    if (this->contains(item)) {
        for (int i = 0; i < size; i++) {
            if (this->elements[i] == item) {
                for (int j = i; j < (size - 1); j++) {
                    elements[j] = elements[j + 1];
                }
                --size;
                return true;
            }
        }
    }
    return false;
}

//Is Empty?//
template <class T>
bool Bag<T>::isEmpty() const {
    if (this->size == 0) {
        return true;
    }
    return false;
}

//Dump//
template <class T>
void Bag<T>::dump() {
    this->size = 0;
}

//Number Of?//
template <class T>
int Bag<T>::numberOf(const T& item) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (this->elements[i] == item) {
            count += 1;
        }
    }
    return count;
}

//Remove All//
template <class T>
void Bag<T>::removeAll(const T& item) {
    assert(this->contains(item));
    int i = 0;
    while (i < size) {
        if (this->elements[i] == item) {
            for (int j = i; j < (size - 1); j++) {
                elements[j] = elements[j + 1];
            }
            --size;
        }
        else {
            i++;
        }
    }
}

//Pick Random Item//
template <class T>
T Bag<T>::pickRandom() {
    assert(this->size > 0);
    T random = this->elements[rand() % size];
    this->removeItem(random);
    return random;
}

//Dump Into//
template <class T>
void Bag<T>::dumpInto(Bag<T>& other) {
    int newSize = this->size + other.size;
    while (other.capacity < newSize) {
        other.grow();
    }
    for (int i = 0; i < this->size; i++) {
        other.addItem(this->elements[i]);
    }
    this->dump();
}

//Extract All//
template <class T>
Bag<T> Bag<T>::extractAll(const T& item) {
    Bag<T> newBag;
    if (!(this->contains(item))) {
        return newBag;
    }
    else {
        for (int i = 0; i < this->size; i++) {
            if (this->elements[i] == item) {
                T currentItem = this->elements[i];
                newBag.addItem(currentItem);
            }
        }
    }
    this->removeAll(item);
    return newBag;
}

//Stream Insertion Operator//
template <class R>
std::ostream& operator<<(std::ostream& out, const Bag<R>& myBag) {
    out << "[";
    for(int i = 0; i < myBag.size - 1; i++) {
        out << myBag.elements[i] << ", ";
    }
    if(myBag.size > 0) {
        out << myBag.elements[myBag.size - 1];
    }
    out << "]";
    return out;
}

#endif // BAG

