#ifndef QUEUE_H
#define QUEUE_H
#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstring>
template<typename T> struct queue_data {T* new_allocated_head; int size; };

template<typename T> class Queue
{
private:
    T* queue_head;
    int queue_size;
protected:
    
    T* getQueueHead()
    {
        return this->queue_head;
    }

    int incrementSize()
    {
        return ++this->queue_size;
    }

    int decrementSize()
    {
        return --this->queue_size;
    }

    
    void setQueueHead(T * head)
    {
        this->queue_head = head;
    }

    
    void setSize(int size)
    {
        this->queue_size = size;
    }

    Queue()
    {
        this->queue_size = 0;
    }

    Queue(queue_data<T> dat)
    {
        this->queue_head = dat.new_allocated_head;
        this->queue_size = dat.size;
    }

    ~Queue()
    {
        free(this->getQueueHead());
    }

    int getSize()
    {
        return this->queue_size;
    }

    void const push(T value){
        if(!this->getSize()) {
            this->setQueueHead((T*)std::calloc(1,sizeof(T)));
            this->incrementSize();
        } else {
            this->setQueueHead((T*)std::realloc(this->getQueueHead(),this->incrementSize() * sizeof(T)));
        }
        this->queue_head[this->getSize() - 1] = value;
    }
    
    T pop(){
        if(!queue_size) {
            throw std::runtime_error("Empth queue");
        }
        int tmp = this->getQueueHead()[0];
        std::memcpy(this->getQueueHead(),
                    this->getQueueHead()+1,
                    this->decrementSize() * sizeof(T));
        this->setQueueHead((T*)std::realloc(this->getQueueHead(),this->getSize() * sizeof(T)));
        return tmp;
    }
    
    T at(const int index){
        if(index < 0) throw std::runtime_error("Index must be greater than 0");
        if(index >= this->getSize()) throw std::runtime_error("Index out of range");
        return this->getQueueHead()[index];
    }
    
    queue_data<T> copy(){
        queue_data<T> ret;
        ret.size = this->getSize();
        ret.new_allocated_head = (T*)std::calloc(ret.size,sizeof(T));
        std::memcpy(ret.new_allocated_head,this->getQueueHead(),ret.size * sizeof(T));
        return ret;
    }
    
    queue_data<T> concat(Queue *a, Queue *b){
        queue_data<T> ret;
        ret.size = a->getSize() + b->getSize();
        ret.new_allocated_head = (T*)std::calloc(ret.size,sizeof(T));

        std::memcpy(ret.new_allocated_head               , a->getQueueHead(), a->getSize());
        std::memcpy(ret.new_allocated_head + a->getSize(), b->getQueueHead(), b->getSize());

        return ret;
    }

    
    void print(){
        for(int i = 0; i < this->getSize(); i++){
            std::cout << this->getQueueHead()[i] << std::endl;
        }
        std::cout << std::endl;
    }

};

#endif // QUEUE_H
