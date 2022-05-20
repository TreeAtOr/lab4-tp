#include "queue.h"

template<typename T> class Set : protected Queue<T>
{
protected: 
    bool isExist(const T value) {
        for (int i = 0; i < this->getSize(); i++){
            if ( value == this->getArray()[i]) return true;
        }
        return false;
    }
public:
    Set(queue_data<T> dat) : Queue<T>(dat) {}
    Set() : Queue<T>() {};
    Set(int n) : Queue<T>(n) {};

    T* getArray() {
        return this->getQueueHead();
    };
    void add(T value) {
        if(!this->isExist(value)) this->push(value);
    };
    void show() {
        this->print();
    };
    Set<T> clone(){
        return Set<T>(this->copy());
    }

    T operator[](int i) {
        return this->at(i);
    };
    Set<T> operator+(Set<T> &set) { 
        Set<T> tmp(this->copy());
        const T* array = set.getArray();
        for (int i = 0; i < set.getSize(); i++) { 
            tmp.add(array[i]);
        }
        return tmp;
    }

    int size() {
        return this->getSize();
    }

    Set<T> operator*(Set<T> &set) { 
        Set<T> tmp;
        const T* array = set.getArray();
        for (int i = 0; i < set.getSize(); i++) { 
            if(this->isExist(array[i])) tmp.add(array[i]);
        }
        return tmp;
    }
    bool operator<(Set<T> &set) {
        const T* array = set.getArray();
        for (int i = 0; i < set.getSize(); i++) { 
            if(!this->isExist(array[i])) return false;
        }
        return true;
    }

};